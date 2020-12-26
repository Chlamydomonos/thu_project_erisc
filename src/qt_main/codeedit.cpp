#include "codeedit.h"
#include "ui_codeedit.h"

CodeEdit::CodeEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CodeEdit)
{
    ui->setupUi(this);
    ui->text->setLineNumberWidget(ui->lineNums);
    connect(ui->text, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumbers()));
}

CodeEdit::~CodeEdit()
{
    delete ui;
}

void CodeEdit::updateLineNumbers()
{
    ui->text->updateLineNumbers();
    ui->lineNums->update();
}
