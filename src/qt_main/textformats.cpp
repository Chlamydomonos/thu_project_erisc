#include "textformats.h"

TextFormats::TextFormats()
{

}

void TextFormats::setToDefault()
{
    commandName.setFontFamily("Courier New");
    registerText.setFontFamily("Courier New");
    numberText.setFontFamily("Courier New");
    lineIdName.setFontFamily("Courier New");
    errorText.setFontFamily("Courier New");
    commentText.setFontFamily("Courier New");
    errorCommand.setFontFamily("Courier New");
    commandName.setFontPointSize(10);
    registerText.setFontPointSize(10);
    numberText.setFontPointSize(10);
    lineIdName.setFontPointSize(10);
    errorText.setFontPointSize(10);
    commentText.setFontPointSize(10);
    errorCommand.setFontPointSize(10);
    commandName.setFontWeight(QFont::Bold);
    commandName.setForeground(QBrush(Qt::blue));
    registerText.setForeground(QBrush(Qt::black));
    numberText.setForeground(QBrush(Qt::blue));
    lineIdName.setFontItalic(true);
    lineIdName.setForeground(QBrush(Qt::green));
    errorText.setForeground(QBrush(Qt::black));
    errorText.setFontUnderline(true);
    errorText.setUnderlineColor(Qt::red);
    errorText.setUnderlineStyle(QTextCharFormat::WaveUnderline);
    commentText.setForeground(QBrush(Qt::gray));
    errorCommand.setFontWeight(QFont::Bold);
    errorCommand.setForeground(QBrush(Qt::red));
}

void TextFormats::setToHighContrast()
{
    commandName.setFontFamily("Courier New");
    registerText.setFontFamily("Courier New");
    numberText.setFontFamily("Courier New");
    lineIdName.setFontFamily("Courier New");
    errorText.setFontFamily("Courier New");
    commentText.setFontFamily("Courier New");
    errorCommand.setFontFamily("Courier New");
    commandName.setFontPointSize(10);
    registerText.setFontPointSize(10);
    numberText.setFontPointSize(10);
    lineIdName.setFontPointSize(10);
    errorText.setFontPointSize(10);
    commentText.setFontPointSize(10);
    errorCommand.setFontPointSize(10);
    commandName.setFontWeight(QFont::Bold);
    commandName.setForeground(QBrush(QColor(0, 255, 255)));
    registerText.setForeground(QBrush(Qt::white));
    numberText.setForeground(QBrush(QColor(0, 255, 255)));
    lineIdName.setFontItalic(true);
    lineIdName.setForeground(QBrush(Qt::green));
    errorText.setForeground(QBrush(Qt::white));
    errorText.setFontUnderline(true);
    errorText.setUnderlineColor(Qt::red);
    errorText.setUnderlineStyle(QTextCharFormat::WaveUnderline);
    commentText.setForeground(QBrush(Qt::gray));
    errorCommand.setFontWeight(QFont::Bold);
    errorCommand.setForeground(QBrush(Qt::red));
}

void TextFormats::setToChlamydomonos()
{
    commandName.setFontFamily("consolas");
    registerText.setFontFamily("consolas");
    numberText.setFontFamily("consolas");
    lineIdName.setFontFamily("consolas");
    errorText.setFontFamily("consolas");
    commentText.setFontFamily("consolas");
    errorCommand.setFontFamily("consolas");
    commandName.setFontPointSize(10);
    registerText.setFontPointSize(10);
    numberText.setFontPointSize(10);
    lineIdName.setFontPointSize(10);
    errorText.setFontPointSize(10);
    commentText.setFontPointSize(10);
    errorCommand.setFontPointSize(10);
    commandName.setFontWeight(QFont::Bold);
    commandName.setForeground(QBrush(QColor(0x80d4ff)));
    registerText.setForeground(QBrush(QColor(200, 200, 200)));
    numberText.setForeground(QBrush(QColor(0x9999ff)));
    lineIdName.setFontItalic(true);
    lineIdName.setForeground(QBrush(0xcca329));
    errorText.setForeground(QBrush(QColor(200, 200, 200)));
    errorText.setFontUnderline(true);
    errorText.setUnderlineColor(Qt::red);
    errorText.setUnderlineStyle(QTextCharFormat::WaveUnderline);
    commentText.setForeground(QBrush(Qt::gray));
    errorCommand.setFontWeight(QFont::Bold);
    errorCommand.setForeground(QBrush(Qt::red));
}
