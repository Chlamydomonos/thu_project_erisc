#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QLabel>
#include <QWidget>
#include "../vm/vm.h"

namespace Ui {
class DrawArea;
}

class DrawArea : public QWidget
{
    Q_OBJECT

public:
    explicit DrawArea(QWidget *parent = nullptr);
    void draw(vm::VM* vm);
    ~DrawArea();

private:
    Ui::DrawArea *ui;
    QLabel** registers;
    QLabel** memory;
    QLabel* stack;
};

#endif // DRAWAREA_H
