#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../vm/vm.h"
#include "textformats.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setApp(QApplication* app);
    void setSkin(int skin);

public slots:
    void setFormats(int type);

private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveAs();
    void updateText();
    void run();
    void updateDrawArea();
    void runByLine();
    void loadCommands();
    void handleInput(const QString&);
    void handleRunningByLine();
    void openVMConfig();
    void openSkinConfig();

private:
    Ui::MainWindow *ui;
    QString currentFileName;
    bool fileChanged;
    bool isNewFile;
    vm::VM* vm;
    bool handleUnsavedChanges();
    bool runningByLine;
    QTimer* timer;
    void startRunningByLine();
    void stopRunningByLine();
    QApplication* app;
    TextFormats fDefault;
    TextFormats fHighContrast;
    TextFormats fChlamydomonos;
    int skin;
};

#endif // MAINWINDOW_H
