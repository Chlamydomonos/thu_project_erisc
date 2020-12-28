#ifndef CODEHIGHLIGHTER_H
#define CODEHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class CodeHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    CodeHighlighter(QTextDocument* parent);
    void highlightBlock(const QString& text) override;
    void updateLineIdList(const QString& allText);
private:
    QSet<QString> lineIdList;
};

#endif // CODEHIGHLIGHTER_H
