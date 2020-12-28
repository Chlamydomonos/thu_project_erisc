#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    QString currentFileName;
    bool fileChanged;
    bool isNewFile;
};

#endif // MAINWINDOW_H
