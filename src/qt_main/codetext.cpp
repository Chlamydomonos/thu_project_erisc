#include "codetext.h"

CodeText::CodeText(QWidget* parent) : QTextEdit (parent)
{

}

void CodeText::setLineNumberWidget(LineNumberWidget *widget)
{
    lineNumbers = widget;
}

void CodeText::updateLineNumbers()
{
    int lineHeight = cursorRect().height();
    int lineNum = textCursor().block().blockNumber() + 1;
    int cursorY = cursorRect().top();
    int offset = cursorY % lineHeight;
    int minLine = lineNum - (cursorY / lineHeight) - 1;
    int maxLine = geometry().height() / lineHeight + lineNum;
    if(maxLine > document()->lineCount())
        maxLine = document()->lineCount();
    lineNumbers->setLineHeight(lineHeight);
    lineNumbers->setPaintOffset(offset);
    lineNumbers->setMinLine(minLine);
    lineNumbers->setMaxLine(maxLine);
    lineNumbers->update();
}
