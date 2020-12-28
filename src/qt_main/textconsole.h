#ifndef TEXTCONSOLE_H
#define TEXTCONSOLE_H

#include <QPlainTextEdit>



class TextConsole : public QPlainTextEdit
{
    Q_OBJECT
signals:
    void commandInputed(const QString&);
public:
    TextConsole(QWidget* parent = nullptr);
    void deleteFirstLine();
protected:
    void keyPressEvent(QKeyEvent *e) override;
};

#endif // TEXTCONSOLE_H
