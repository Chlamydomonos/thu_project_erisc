#include "codeedit.h"
#include "ui_codeedit.h"
#include <QScrollBar>

CodeEdit::CodeEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CodeEdit)
{
    ui->setupUi(this);
    ui->text->setLineNumberWidget(ui->lineNumbers);
    connect(ui->text, SIGNAL(textChanged()), this, SLOT(updateLineNumbers()));
    connect(ui->text->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(updateLineNumbers()));
}

CodeEdit::~CodeEdit()
{
    delete ui;
}

void CodeEdit::updateLineNumbers()
{
    ui->text->updateLineNumbers();
    ui->lineNumbers->update();
}
