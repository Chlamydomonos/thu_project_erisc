#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../vm/vm.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    QString currentFileName;
    bool fileChanged;
    bool isNewFile;
    vm::VM* vm;
    bool handleUnsavedChanges();
};

#endif // MAINWINDOW_H
