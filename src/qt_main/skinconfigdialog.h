#ifndef SKINCONFIGDIALOG_H
#define SKINCONFIGDIALOG_H

#include <QDialog>

namespace Ui {
class SkinConfigDialog;
}

class SkinConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SkinConfigDialog(int defaultValue, QWidget *parent = nullptr);
    ~SkinConfigDialog();

private slots:
    void ok();
    void cancel();

private:
    Ui::SkinConfigDialog *ui;
    int defaultValue;
};

#endif // SKINCONFIGDIALOG_H
