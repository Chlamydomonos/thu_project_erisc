#ifndef TEXTFORMATS_H
#define TEXTFORMATS_H

#include <QTextCharFormat>



class TextFormats
{
public:
    TextFormats();
    QTextCharFormat commandName;
    QTextCharFormat registerText;
    QTextCharFormat numberText;
    QTextCharFormat lineIdName;
    QTextCharFormat errorText;
    QTextCharFormat commentText;
    QTextCharFormat errorCommand;
    void setToDefault();
    void setToHighContrast();
    void setToChlamydomonos();
};

#endif // TEXTFORMATS_H
