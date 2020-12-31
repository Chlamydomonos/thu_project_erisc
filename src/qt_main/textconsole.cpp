#include "textconsole.h"
#include <QTextBlock>

TextConsole::TextConsole(QWidget* parent) : QPlainTextEdit (parent)
{
    setTabStopWidth(fontMetrics().width("a") * 4);
}

void TextConsole::deleteFirstLine()
{
    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::Start);
    cursor.movePosition(QTextCursor::NextBlock);
    while (cursor.position() > 0)
    {
        cursor.deletePreviousChar();
    }
}

void TextConsole::keyPressEvent(QKeyEvent *e)
{
    if(!this->isReadOnly())
    {
        int k = e->key();
        QTextCursor cursor = this->textCursor();
        if(k >= 0x21 && k <= 0x7e)
        {
            if(cursor.block().blockNumber() < this->blockCount() - 1 || cursor.positionInBlock() < 3)
            {
                cursor.movePosition(QTextCursor::End);
                this->setTextCursor(cursor);
            }
            QPlainTextEdit::keyPressEvent(e);
        }
        else if(k == Qt::Key_Backspace)
        {
            if(!(cursor.block().blockNumber() < this->blockCount() - 1 || cursor.positionInBlock() < 3))
                QPlainTextEdit::keyPressEvent(e);
        }
        else if(k == Qt::Key_Delete)
        {
            if(!(cursor.block().blockNumber() < this->blockCount() - 1 || cursor.positionInBlock() < 2))
                QPlainTextEdit::keyPressEvent(e);
        }
        else if(k == Qt::Key_Return)
        {
            cursor.movePosition(QTextCursor::End);
            this->setTextCursor(cursor);
            QString text = this->textCursor().block().text().mid(2);
            emit commandInputed(text);
        }
        else
        {
            QPlainTextEdit::keyPressEvent(e);
        }
    }
}
