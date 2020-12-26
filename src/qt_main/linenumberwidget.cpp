#include "linenumberwidget.h"

#include <QPainter>

LineNumberWidget::LineNumberWidget(QWidget *parent) : QWidget(parent)
{

}

LineNumberWidget::~LineNumberWidget()
{

}

void LineNumberWidget::setFirstLineNum(int firstLineNumber)
{
    this->firstLineNumber = firstLineNumber;
}

void LineNumberWidget::clearY()
{
    yPositions.clear();
}

void LineNumberWidget::addYPosition(int yPosition)
{
    yPositions.append(yPosition);
}

void LineNumberWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    int lines = yPositions.size();

    for(int i = 0; i < lines; i++)
    {
        painter.drawText(0, yPositions[i] + fontMetrics().ascent(), QString::number(this->firstLineNumber + i + 1));
    }
}
