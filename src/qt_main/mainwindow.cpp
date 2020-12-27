#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QAbstractButton>
#include <QTextStream>

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
    fileChanged = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    if(fileChanged)
    {
        QMessageBox box(this);
        box.setStandardButtons(QMessageBox::Yes | QMessageBox:: No);
        box.setWindowTitle("有未保存的更改");
        box.setText("是否保存并继续?");
        box.button(QMessageBox::Yes)->setText("确定");
        box.button(QMessageBox::No)->setText("取消");
        box.show();
        int result = box.exec();

        if(result == QMessageBox::Yes)
            saveFile();
        else
            return;
    }
    isNewFile = true;
    fileChanged = false;
    ui->codeEdit->clear();
    ui->codeEdit->setTitle("未命名");
}

void MainWindow::openFile()
{
    if(fileChanged)
    {
        QMessageBox box(this);
        box.setStandardButtons(QMessageBox::Yes | QMessageBox:: No);
        box.setWindowTitle("有未保存的更改");
        box.setText("是否保存并继续?");
        box.button(QMessageBox::Yes)->setText("确定");
        box.button(QMessageBox::No)->setText("取消");
        box.show();
        int result = box.exec();

        if(result == QMessageBox::Yes)
            saveFile();
        else
            return;
    }
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件", "../input", "*.risc");
    currentFileName = fileName;
    QFile file(fileName);
    file.open(QFile::Text | QIODevice::ReadOnly);
    if(!file.isReadable())
    {
        QMessageBox::warning(this, "错误", "文件打开失败");
        return;
    }
    QByteArray content = file.readAll();
    file.close();
    QString text(content);
    ui->codeEdit->setPlainText(text);
    ui->codeEdit->setTitle(fileName);
    isNewFile = false;
    fileChanged = false;
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
            return;
        QString text = ui->codeEdit->toPlainText();
        QTextStream stream(&file);
        stream << text;
        stream.atEnd();
        file.close();
    }
}

void MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "另存为", "../input", "*.risc");
    currentFileName = fileName;
    isNewFile = false;
    saveFile();
}

void MainWindow::updateText()
{
    fileChanged = true;
}
