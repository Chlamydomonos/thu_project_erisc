#include "codetext.h"

CodeText::CodeText(QWidget* parent) : QPlainTextEdit (parent)
{

}

void CodeText::setLineNumberWidget(LineNumberWidget *widget)
{
    lineNumbers = widget;
}

void CodeText::updateLineNumbers()
{
    QTextBlock block = firstVisibleBlock();
    lineNumbers->clearY();
    lineNumbers->setFirstLineNum(block.blockNumber());
    int y1 = contentOffset().y();
    while(block.isValid())
    {
        lineNumbers->addYPosition(y1);
        y1 += blockBoundingRect(block).height();
        block = block.next();
    }
}
