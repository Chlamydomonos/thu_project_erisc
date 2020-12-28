#include "codehighlighter.h"

#include <QRegularExpression>
#include "paramtest.h"

CodeHighlighter::CodeHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent)
{

}

void CodeHighlighter::highlightBlock(const QString &text)
{
    QRegularExpression commandNames("\\s*((add|and|beq|bge|blt|bne|call|div|jal|load|mov|mul|or|pop|push|rem|store|sub)\\s+)");
    QRegularExpression commandsWithoutParams("\\s*(draw|end|ret)\\s*");
    QRegularExpressionMatchIterator i0 = commandNames.globalMatch(text);
    if(i0.hasNext())
    {
        QRegularExpressionMatch match0 = i0.next();
        if(match0.capturedStart() != 0)
            setFormat(0, match0.capturedStart(), errorText);
        setFormat(match0.capturedStart(), match0.capturedLength(), commandName);

        QRegularExpression commandNameText("[a-z]+");
        QString commandType = commandNameText.globalMatch(match0.captured()).next().captured();

        QRegularExpression mayValidParams("([^,\\s]+\\s*,\\s*)*[^,\\s]+\\s*");

        QString text2 = text.mid(match0.capturedEnd());
        int text2Begin = match0.capturedEnd();
        QRegularExpressionMatchIterator i1 = mayValidParams.globalMatch(text2);

        if(i1.hasNext())
        {
            QRegularExpressionMatch match1 = i1.next();
            if(match1.capturedStart() != 0)
                setFormat(text2Begin, match1.capturedStart() - 1, errorText);
            if(match1.capturedEnd() != text2.length())
                setFormat(match1.capturedEnd() + text2Begin, text.length() - match1.capturedEnd(), errorText);
            QString text3 = match1.captured();
            int text3Begin = text2Begin + match1.capturedStart();

            QRegularExpression maybeParam("[^,\\s]+");
            QRegularExpressionMatchIterator i2 = maybeParam.globalMatch(text3);
            QVector<QString> params;
            QVector<int> paramStartPositions;
            while(i2.hasNext())
            {
                QRegularExpressionMatch match2 = i2.next();
                params.append(match2.captured());
                paramStartPositions.append(match2.capturedStart() + text3Begin);
            }

            for(int i = 0; i < params.length(); i++)
            {
                if(paramTest(commandType, params[i], i))
                {
                    if(isRegister(params[i]))
                        setFormat(paramStartPositions[i], params[i].length(), registerText);
                    else if(isNumber(params[i]))
                        setFormat(paramStartPositions[i], params[i].length(), numberText);
                    else if(lineIdList.contains(params[i]))
                        setFormat(paramStartPositions[i], params[i].length(), lineIdName);
                    else
                        setFormat(paramStartPositions[i], params[i].length(), errorText);
                }
                else
                    setFormat(paramStartPositions[i], params[i].length(), errorText);
            }

            if(paramAmount(commandType) > params.length())
                setFormat(match0.capturedStart(), match0.capturedLength(), errorCommand);
        }
        else
            setFormat(text2Begin, text2.length(), errorText);
    }
    else
    {
        QRegularExpression lineIDDeclaraiton("\\s*[A-Za-z]+:\\s*");
        QRegularExpressionMatchIterator i1 = lineIDDeclaraiton.globalMatch(text);
        if(i1.hasNext())
        {
            QRegularExpressionMatch match1 = i1.next();
            QRegularExpression temp("[A-Za-z]+");
            QRegularExpressionMatch tempMatch = temp.globalMatch(text).next();
            if(match1.capturedStart() == 0 && match1.capturedLength() == text.length())
                setFormat(tempMatch.capturedStart(), tempMatch.capturedLength(), lineIdName);
            else if(match1.capturedStart() == 0)
            {
                setFormat(tempMatch.capturedStart(), tempMatch.capturedLength(), lineIdName);
                setFormat(tempMatch.capturedEnd() + 1, text.length() - tempMatch.capturedLength(), errorText);
            }
            else
                setFormat(0, text.length(), errorText);
        }
        else
        {
            QRegularExpression comment("\\s*//");
            QRegularExpressionMatchIterator i2 = comment.globalMatch(text);
            if(i2.hasNext())
            {
                QRegularExpressionMatch match2 = i2.next();
                if(match2.capturedStart() == 0)
                    setFormat(0, text.length(), commentText);
                else
                    setFormat(0, text.length(), errorText);
            }
            else
            {
                QRegularExpressionMatchIterator i3 = commandsWithoutParams.globalMatch(text);
                if(i3.hasNext())
                {
                    QRegularExpressionMatch match3 = i3.next();
                    setFormat(0, text.length(), errorText);
                    setFormat(match3.capturedStart(), match3.capturedLength(), commandName);
                }
                else
                    setFormat(0, text.length(), errorText);
            }
        }
    }
}

void CodeHighlighter::updateLineIdList(const QString& allText)
{
    lineIdList.clear();
    QStringList lines = allText.split('\n');
    while(lines.size() > 0)
    {
        QString line = lines.first();
        lines.pop_front();
        QRegularExpression lineID("\\s*[A-Za-z]+:\\s*");
        QRegularExpression lineIDText("[A-Za-z]+");
        QRegularExpressionMatchIterator i = lineID.globalMatch(line);
        if(i.hasNext())
        {
            QRegularExpressionMatch match = i.next();
            if(match.capturedStart() == 0 && match.capturedLength() == line.length())
            {
                QRegularExpressionMatch text = lineIDText.globalMatch(line).next();
                lineIdList.insert(text.captured());
            }
        }
    }
}

void CodeHighlighter::setFormats(TextFormats *format)
{
    commandName = format->commandName;
    registerText = format->registerText;
    numberText = format->numberText;
    lineIdName = format->lineIdName;
    errorText = format->errorText;
    commentText = format->commentText;
    errorCommand = format->errorCommand;
}
