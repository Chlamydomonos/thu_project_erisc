#include "mainwindow.h"
#include "runbylinedialog.h"
#include "ui_mainwindow.h"
#include "../exception/exception.h"
#include "../io/vmconfigreader.h"
#include "../command/allcommands.h"
#include "../io/inpututil.h"
#include "skinconfigdialog.h"
#include "vmsettingdialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QAbstractButton>
#include <QTextStream>

#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->codeEdit->setTitle("未命名");
    isNewFile = true;
    connect(ui->_new, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(ui->_open, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->_save, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->_saveAs, SIGNAL(triggered()), this, SLOT(saveAs()));
    connect(ui->codeEdit, SIGNAL(textChanged()), this, SLOT(updateText()));
    connect(ui->run, SIGNAL(triggered()), this, SLOT(run()));
    connect(ui->loadCommand, SIGNAL(triggered()), this, SLOT(loadCommands()));
    connect(ui->runByLine, SIGNAL(triggered()), this, SLOT(runByLine()));
    fileChanged = false;
    this->vm = nullptr;
    ui->console->setReadOnly(true);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleRunningByLine()));
    connect(ui->vmSettings, SIGNAL(triggered()), this, SLOT(openVMConfig()));
    runningByLine = false;
    app = nullptr;
    fDefault.setToDefault();
    fHighContrast.setToHighContrast();
    fChlamydomonos.setToChlamydomonos();
    connect(ui->skinSettings, SIGNAL(triggered()), this, SLOT(openSkinConfig()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setApp(QApplication *app)
{
    this->app = app;
}

void MainWindow::setSkin(int skin)
{
    this->skin = skin;
    if(skin == 0)
    {
        QFile styleSheetFile(":/style_sheets/default.qss");
        styleSheetFile.open(QIODevice::ReadOnly);
        QString style = styleSheetFile.readAll();
        app->setStyleSheet(style);
        styleSheetFile.close();
    }
    else if(skin == 1)
    {
        QFile styleSheetFile(":/style_sheets/high_contrast.qss");
        styleSheetFile.open(QIODevice::ReadOnly);
        QString style = styleSheetFile.readAll();
        app->setStyleSheet(style);
        styleSheetFile.close();
    }
    else
    {
        QFile styleSheetFile(":/style_sheets/chlamydomonos.qss");
        styleSheetFile.open(QIODevice::ReadOnly);
        QString style = styleSheetFile.readAll();
        app->setStyleSheet(style);
        styleSheetFile.close();
    }
    this->setFormats(skin);
}

void MainWindow::setFormats(int type)
{
    if(type == 0)
        ui->codeEdit->setFormats(&fDefault);
    else if(type == 1)
        ui->codeEdit->setFormats(&fHighContrast);
    else
        ui->codeEdit->setFormats(&fChlamydomonos);
}

void MainWindow::newFile()
{
    if(!handleUnsavedChanges())
        return;
    isNewFile = true;
    fileChanged = false;
    ui->codeEdit->clear();
    ui->codeEdit->setTitle("未命名");
}

void MainWindow::openFile()
{
    if(!handleUnsavedChanges())
        return;
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件", "../input", "*.risc");
    QFile file(fileName);
    file.open(QFile::Text | QIODevice::ReadOnly);
    if(!file.isReadable())
    {
        QMessageBox::warning(this, "错误", "文件打开失败");
        return;
    }
    else
        currentFileName = fileName;
    QByteArray content = file.readAll();
    file.close();
    QString text(content);
    ui->codeEdit->setPlainText(text);
    isNewFile = false;
    fileChanged = false;
    ui->codeEdit->setTitle(currentFileName);
}

void MainWindow::saveFile()
{
    if(isNewFile)
        saveAs();
    else
    {
        QFile file(currentFileName);
        file.open(QFile::Text | QIODevice::WriteOnly);
        if(!file.isWritable())
        {
            QMessageBox::warning(this, "错误", "文件保存失败");
            return;
        }
        QString text = ui->codeEdit->toPlainText();
        QTextStream stream(&file);
        stream << text;
        stream.atEnd();
        file.close();
        fileChanged = false;
        ui->codeEdit->setTitle(currentFileName);
    }
}

void MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "另存为", "../input", "*.risc");
    currentFileName = fileName;
    isNewFile = false;
    fileChanged = false;
    saveFile();
}

void MainWindow::updateText()
{
    fileChanged = true;
    if(isNewFile)
        ui->codeEdit->setTitle("未命名*");
    else
        ui->codeEdit->setTitle(currentFileName + "*");
}

void MainWindow::run()
{
    if(!handleUnsavedChanges())
        return;
    try
    {
        input::VMConfigReader* reader = new input::VMConfigReader("vm.vmcfg");
        int maxLines = reader->getMaxCommandAmount();
        delete reader;
        vm = new vm::VM(maxLines, this);
        erisc::Command** commandList = input::readCommandsFromFile(currentFileName.toLatin1(), vm);
        vm->initCommands(commandList);

        connect(vm, SIGNAL(draw()), this, SLOT(updateDrawArea()));

        while(!vm->end)
            vm->runCurrentCommand();
        if(vm->end)
            ui->console->setPlainText("VM has ended successfully");
        delete vm;
        vm = nullptr;
    }
    catch(Exception& e)
    {
        if(vm != nullptr)
        {
            delete vm;
            vm = nullptr;
        }
        ui->console->setPlainText("Error occurred running file \"" + currentFileName + "\"" + e.what());
    }
}

void MainWindow::updateDrawArea()
{
    ui->drawArea->draw(vm);
}

void MainWindow::runByLine()
{
    if(runningByLine)
        stopRunningByLine();
    else
        startRunningByLine();
}

void MainWindow::loadCommands()
{
    if(!handleUnsavedChanges())
        return;

    try
    {
        input::VMConfigReader* reader = new input::VMConfigReader("vm.vmcfg");
        int maxLines = reader->getMaxCommandAmount();
        delete reader;
        vm = new vm::VM(maxLines, this);
        erisc::Command** commandList = input::readCommandsFromFile(currentFileName.toLatin1(), vm);
        vm->initCommands(commandList);

        vm->currentRunningLine = vm->getCurrentCommandAmount() + 1;

        connect(vm, SIGNAL(draw()), this, SLOT(updateDrawArea()));

        ui->console->setReadOnly(false);
        ui->run->setEnabled(false);
        ui->loadCommand->setEnabled(false);
        ui->runByLine->setEnabled(false);
        connect(ui->console, SIGNAL(commandInputed(const QString&)), this, SLOT(handleInput(const QString&)));
        ui->console->setPlainText("Console started, input \"end\" to stop\n> ");
    }
    catch(Exception& e)
    {
        if(vm != nullptr)
        {
            delete vm;
            vm = nullptr;
        }
        ui->console->setPlainText("Error occurred running file \"" + currentFileName + "\"" + e.what());
        ui->run->setEnabled(true);
        ui->loadCommand->setEnabled(true);
        ui->runByLine->setEnabled(true);
    }
}

void MainWindow::handleInput(const QString & str)
{
    if(vm != nullptr)
    {
        try
        {
            ui->console->appendPlainText("\n> ");
            erisc::Command* command = input::readSingleCommand(str.toLatin1(), vm, vm->getCurrentCommandAmount() + 1);
            vm->addCommand(command);
            while(vm->currentRunningLine <= vm->getCurrentCommandAmount() && !vm->end)
                vm->runCurrentCommand();
            if(vm->end)
            {
                ui->console->setReadOnly(true);
                ui->run->setEnabled(true);
                ui->loadCommand->setEnabled(true);
                ui->runByLine->setEnabled(true);
                delete vm;
                vm = nullptr;
                ui->console->setPlainText("VM has ended successfully");
            }
        }
        catch(Exception& e)
        {
            if(vm != nullptr)
            {
                delete vm;
                vm = nullptr;
            }
            ui->console->setReadOnly(true);
            ui->console->setPlainText(QString(e.what()));
            ui->run->setEnabled(true);
            ui->loadCommand->setEnabled(true);
            ui->runByLine->setEnabled(true);
        }
    }
}

void MainWindow::handleRunningByLine()
{
    try
    {
        if(vm->end)
        {
            stopRunningByLine();
            return;
        }
        int lineNum = vm->currentRunningLine;

        ui->console->appendPlainText(ui->codeEdit->getLine(lineNum));

        vm->runCurrentCommand();

        while(ui->console->blockCount() > 1000)
            ui->console->deleteFirstLine();
    }
    catch(Exception& e)
    {
        ui->console->appendPlainText("error running file \"" + currentFileName + "\":\n" + e.what());
        stopRunningByLine();
    }
}

void MainWindow::openVMConfig()
{
    VMSettingDialog dialog(this);
    dialog.exec();
}

void MainWindow::openSkinConfig()
{
    SkinConfigDialog dialog(this->skin, this);
    int skin = dialog.exec();
    if(skin != this->skin)
    {
        setSkin(skin);
        QFile file("skin.cfg");
        file.open(QIODevice::WriteOnly);
        file.write((char*) &(this->skin), sizeof(this->skin));
        file.close();
    }
}

bool MainWindow::handleUnsavedChanges()
{
    if(fileChanged)
    {
        QMessageBox box(this);
        box.setStandardButtons(QMessageBox::Yes | QMessageBox:: No | QMessageBox::Cancel);
        box.setWindowTitle("有未保存的更改");
        box.setText("有未保存的更改，是否保存并继续?");
        box.button(QMessageBox::Yes)->setText("是");
        box.button(QMessageBox::No)->setText("否");
        box.button(QMessageBox::Cancel)->setText("取消");
        box.show();
        int result = box.exec();

        if(result == QMessageBox::Yes)
            saveFile();
        else if(result == QMessageBox::No && !isNewFile)
        {
            QFile file(currentFileName);
            file.open(QFile::Text | QIODevice::ReadOnly);
            if(!file.isReadable())
            {
                QMessageBox::warning(this, "错误", "文件打开失败");
                return false;
            }
            QByteArray content = file.readAll();
            file.close();
            QString text(content);
            ui->codeEdit->setPlainText(text);
            ui->codeEdit->setTitle(currentFileName);
            isNewFile = false;
            fileChanged = false;
            ui->codeEdit->setTitle(currentFileName);
        }
        else if(result == QMessageBox::Cancel)
            return false;
    }
    return true;
}

void MainWindow::startRunningByLine()
{
    if(!handleUnsavedChanges())
        return;

    RunByLineDialog dialog(this);

    int _time = dialog.exec();
    if(_time <= 0)
        return;

    ui->run->setEnabled(false);
    ui->loadCommand->setEnabled(false);
    ui->runByLine->setText("停止");
    ui->codeEdit->setReadOnly(true);
    try
    {
        runningByLine = true;
        input::VMConfigReader* reader = new input::VMConfigReader("vm.vmcfg");
        int maxLines = reader->getMaxCommandAmount();
        delete reader;
        vm = new vm::VM(maxLines, this);
        erisc::Command** commandList = input::readCommandsFromFile(currentFileName.toLatin1(), vm);
        vm->initCommands(commandList);

        connect(vm, SIGNAL(draw()), this, SLOT(updateDrawArea()));

        timer->start(_time);
        ui->console->setPlainText("Start running…");
    }
    catch (Exception& e)
    {
        ui->console->appendPlainText("\nerror running file \"" + currentFileName + "\":\n" + e.what());
        stopRunningByLine();
    }
}

void MainWindow::stopRunningByLine()
{
    if(vm != nullptr)
    {
        delete vm;
        vm = nullptr;
    }
    ui->run->setEnabled(true);
    ui->loadCommand->setEnabled(true);
    ui->runByLine->setText("逐行运行…");
    ui->codeEdit->setReadOnly(false);
    timer->stop();
    ui->console->appendPlainText("\nRunning stopped");
    runningByLine = false;
}
