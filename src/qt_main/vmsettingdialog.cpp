#include "vmsettingdialog.h"
#include "ui_vmsettingdialog.h"

#include <QFile>

VMSettingDialog::VMSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VMSettingDialog)
{
    ui->setupUi(this);
    QFile file("vm.vmcfg");
    file.open(QIODevice::ReadOnly);
    int n = 0;
    file.read((char*)&n, sizeof(n));
    ui->spinBox->setValue(n);
    file.close();
    connect(ui->ok, SIGNAL(clicked()), this, SLOT(ok()));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->apply, SIGNAL(clicked()), this, SLOT(apply()));
}

VMSettingDialog::~VMSettingDialog()
{
    delete ui;
}

void VMSettingDialog::apply()
{
    QFile file("vm.vmcfg");
    file.open(QIODevice::WriteOnly);
    int n = ui->spinBox->value();
    file.write((char*)&n, sizeof(n));
    file.close();
}

void VMSettingDialog::ok()
{
    apply();
    done(1);
}

void VMSettingDialog::cancel()
{
    done(0);
}
