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
    connect(ui->text, SIGNAL(textChanged()), this, SLOT(emitTextChanged()));
    connect(ui->text->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(updateLineNumbers()));
    highlighter = new CodeHighlighter(ui->text->document());
    connect(ui->text,SIGNAL(textChanged()), this, SLOT(updateLineIdList()));
}

CodeEdit::~CodeEdit()
{
    delete ui;
}

QString CodeEdit::toPlainText()
{
    return ui->text->toPlainText();
}

QString CodeEdit::title()
{
    return ui->title->text();
}

void CodeEdit::updateLineNumbers()
{
    ui->text->updateLineNumbers();
    int w1 = ui->lineNumbers->getRequiredWidth();
    int w2 = this->width();
    ui->text->setGeometry(w1, ui->text->geometry().y(), w2 - w1, ui->text->geometry().height());
    ui->lineNumbers->update();
}

void CodeEdit::updateLineIdList()
{
    if(ui->text->document()->lineCount() != oldLineAmount)
    {
        highlighter->updateLineIdList(ui->text->toPlainText());
        oldLineAmount = ui->text->document()->lineCount();
        highlighter->rehighlight();
    }
}

void CodeEdit::emitTextChanged()
{
    emit textChanged();
}

void CodeEdit::cut()
{
    ui->text->cut();
}

void CodeEdit::copy()
{
    ui->text->copy();
}

void CodeEdit::paste()
{
    ui->text->paste();
}

void CodeEdit::undo()
{
    ui->text->undo();
}

void CodeEdit::redo()
{
    ui->text->redo();
}

void CodeEdit::clear()
{
    ui->text->clear();
}

void CodeEdit::setPlainText(const QString &text)
{
    ui->text->setPlainText(text);
}

void CodeEdit::setTitle(const QString &title)
{
    ui->title->setText(title);
}
