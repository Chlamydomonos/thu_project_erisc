#ifndef LINENUMBERWIDGET_H
#define LINENUMBERWIDGET_H

#include <QPainter>
#include <QWidget>
#include <QVector>

class LineNumberWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LineNumberWidget(QWidget *parent = nullptr);
    ~LineNumberWidget();
    void setFirstLineNum(int firstNumber);
    void clearY();
    void addYPosition(int yPosition);

protected:
    void paintEvent(QPaintEvent* event) override;
private:
    QVector<int> yPositions;
    int firstLineNumber;
};

#endif // LINENUMBERWIDGET_H
