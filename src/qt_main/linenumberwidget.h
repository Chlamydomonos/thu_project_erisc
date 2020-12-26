#ifndef LINENUMBERWIDGET_H
#define LINENUMBERWIDGET_H

#include <QPainter>
#include <QWidget>

class LineNumberWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LineNumberWidget(QWidget *parent = nullptr);
    void setMinLine(int line);
    void setMaxLine(int line);
    void setLineHeight(int height);
    void setPaintOffset(int offset);
protected:
    void paintEvent(QPaintEvent* event) override;
private:
    int minLine;
    int maxLine;
    int lineHeight;
    int paintOffset;
};

#endif // LINENUMBERWIDGET_H
