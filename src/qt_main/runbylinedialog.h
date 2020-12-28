#ifndef RUNBYLINEDIALOG_H
#define RUNBYLINEDIALOG_H

#include <QDialog>

namespace Ui {
class RunByLineDialog;
}

class RunByLineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RunByLineDialog(QWidget *parent = nullptr);
    ~RunByLineDialog();

private slots:
    void done1();
    void done2();

private:
    Ui::RunByLineDialog *ui;
};

#endif // RUNBYLINEDIALOG_H
