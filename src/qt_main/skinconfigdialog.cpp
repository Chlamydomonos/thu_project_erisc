#include "skinconfigdialog.h"
#include "ui_skinconfigdialog.h"

SkinConfigDialog::SkinConfigDialog(int defaultValue, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SkinConfigDialog)
{
    ui->setupUi(this);
    this->defaultValue = defaultValue;
    if(defaultValue == 0)
    {
        ui->d->setChecked(true);
        ui->h->setChecked(false);
        ui->c->setChecked(false);
    }
    else if(defaultValue == 1)
    {
        ui->d->setChecked(false);
        ui->h->setChecked(true);
        ui->c->setChecked(false);
    }
    else if(defaultValue == 2)
    {
        ui->d->setChecked(false);
        ui->h->setChecked(false);
        ui->c->setChecked(true);
    }
    connect(ui->ok, SIGNAL(clicked()), this, SLOT(ok()));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancel()));
}

SkinConfigDialog::~SkinConfigDialog()
{
    delete ui;
}

void SkinConfigDialog::ok()
{
    if(ui->d->isChecked())
        done(0);
    if(ui->h->isChecked())
        done(1);
    if(ui->c->isChecked())
        done(2);
}

void SkinConfigDialog::cancel()
{
    done(defaultValue);
}
