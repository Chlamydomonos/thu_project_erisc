#include "runbylinedialog.h"
#include "ui_runbylinedialog.h"

RunByLineDialog::RunByLineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RunByLineDialog)
{
    ui->setupUi(this);
    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(done1()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(done2()));
}

RunByLineDialog::~RunByLineDialog()
{
    delete ui;
}

void RunByLineDialog::done1()
{
    done(ui->spinBox->value());
}

void RunByLineDialog::done2()
{
    done(-1);
}
