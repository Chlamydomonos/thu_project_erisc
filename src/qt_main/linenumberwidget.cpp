#include "linenumberwidget.h"

#include <QPainter>

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

int LineNumberWidget::getRequiredWidth()
{
    return fontMetrics().width(QString::number(maxLine)) + 4;
}

void LineNumberWidget::paintEvent(QPaintEvent *event)
{
    int y0 = paintOffset - lineHeight;
    y0 += (lineHeight - fontMetrics().height()) / 2;
    QPainter painter(this);
    for(int i = minLine; i <= maxLine; i++)
    {
        if(i > 0)
            painter.drawText(2, y0, fontMetrics().width(QString::number(maxLine)), fontMetrics().height(), Qt::AlignRight, QString::number(i));
        y0 += lineHeight;
    }
}
