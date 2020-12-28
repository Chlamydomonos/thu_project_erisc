#include "drawarea.h"
#include "ui_drawarea.h"

DrawArea::DrawArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawArea)
{
    ui->setupUi(this);
    QLabel* _registers[32] = {ui->register0,  ui->register1,  ui->register2,  ui->register3,  ui->register4,  ui->register5,  ui->register6,  ui->register7,
                              ui->register8,  ui->register9,  ui->register10, ui->register11, ui->register12, ui->register13, ui->register14, ui->register15,
                              ui->register16, ui->register17, ui->register18, ui->register19, ui->register20, ui->register21, ui->register22, ui->register23,
                              ui->register24, ui->register25, ui->register26, ui->register27, ui->register28, ui->register29, ui->register30, ui->register31};
    registers = new QLabel*[32];
    for(int i = 0; i < 32; i++)
        registers[i] = _registers[i];

    QLabel* _memory[16] = {ui->memory0,  ui->memory1,  ui->memory2,  ui->memory3,
                           ui->memory4,  ui->memory5,  ui->memory6,  ui->memory7,
                           ui->memory8,  ui->memory9,  ui->memory10, ui->memory11,
                           ui->memory12, ui->memory13, ui->memory14, ui->memory15};
    memory = new QLabel*[16];
    for(int i = 0; i < 16; i++)
        memory[i] = _memory[i];
    stack = ui->stack;
    setAttribute(Qt::WA_StyledBackground);
}

void DrawArea::draw(vm::VM* vm)
{
    for(int i = 0; i < 32; i++)
    {
        bool br = vm->getRegister(i)->getRead();
        bool bw = vm->getRegister(i)->getWritten();
        if(br && bw)
            registers[i]->setStyleSheet("background-color: rgb(255, 0, 255);");
        else if(br)
            registers[i]->setStyleSheet("background-color: rgb(0, 0, 255);");
        else if(bw)
            registers[i]->setStyleSheet("background-color: rgb(255, 0, 0);");
        else
            registers[i]->setStyleSheet("");
    }
    for(int i = 0; i < 16; i++)
    {
        if(vm->getMemory()->getAccessed(i))
            memory[i]->setStyleSheet("background-color: rgb(0, 255, 0);");
        else
            memory[i]->setStyleSheet("");
    }
    if(vm->getStack()->getAccessed())
        stack->setStyleSheet("background-color: rgb(128, 255, 0);");
    else
        stack->setStyleSheet("");
}

DrawArea::~DrawArea()
{
    delete ui;
}
