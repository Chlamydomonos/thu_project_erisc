#ifndef CODETEXT_H
#define CODETEXT_H

#include "linenumberwidget.h"
#include <QPlainTextEdit>
#include <QTextBlock>

class CodeText : public QPlainTextEdit
{
public:
    CodeText(QWidget* parent = nullptr);
    void setLineNumberWidget(LineNumberWidget* widget);
    void updateLineNumbers();

private:
    LineNumberWidget* lineNumbers;
};

#endif // CODETEXT_H
