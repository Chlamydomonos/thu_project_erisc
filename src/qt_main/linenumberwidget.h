#ifndef LINENUMBERWIDGET_H
#define LINENUMBERWIDGET_H

#include <QWidget>

class LineNumberWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LineNumberWidget(QWidget *parent = nullptr);
public slots:
    void drawLineNumbers(int lineAmount, int firstNumber);
};

#endif // LINENUMBERWIDGET_H
