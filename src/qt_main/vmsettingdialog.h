#ifndef VMSETTINGDIALOG_H
#define VMSETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class VMSettingDialog;
}

class VMSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VMSettingDialog(QWidget *parent = nullptr);
    ~VMSettingDialog();

private slots:
    void apply();
    void ok();
    void cancel();

private:
    Ui::VMSettingDialog *ui;
};

#endif // VMSETTINGDIALOG_H
