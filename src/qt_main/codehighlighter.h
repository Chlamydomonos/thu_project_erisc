#ifndef CODEHIGHLIGHTER_H
#define CODEHIGHLIGHTER_H

#include "textformats.h"

#include <QSyntaxHighlighter>

class CodeHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    CodeHighlighter(QTextDocument* parent);
    void highlightBlock(const QString& text) override;
    void updateLineIdList(const QString& allText);

    void setFormats(TextFormats* format);

private:
    QSet<QString> lineIdList;
    QTextCharFormat commandName;
    QTextCharFormat registerText;
    QTextCharFormat numberText;
    QTextCharFormat lineIdName;
    QTextCharFormat errorText;
    QTextCharFormat commentText;
    QTextCharFormat errorCommand;
};

#endif // CODEHIGHLIGHTER_H
