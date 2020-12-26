#include "linenumberwidget.h"

#include <QPainter>
#include <qdebug.h>

LineNumberWidget::LineNumberWidget(QWidget *parent) : QWidget(parent)
{

}

void LineNumberWidget::setMinLine(int line)
{
    minLine = line;
}

void LineNumberWidget::setMaxLine(int line)
{
    maxLine = line;
}

void LineNumberWidget::setLineHeight(int height)
{
    lineHeight = height;
}

void LineNumberWidget::setPaintOffset(int offset)
{
    paintOffset = offset;
}

void LineNumberWidget::paintEvent(QPaintEvent *event)
{
    int y0 = paintOffset + fontMetrics().ascent() - lineHeight;
    QPainter painter(this);
    for(int i = minLine; i <= maxLine; i++)
    {
        if(i > 0)
            painter.drawText(0, y0, QString::number(i));
        y0 += lineHeight;
    }
}
