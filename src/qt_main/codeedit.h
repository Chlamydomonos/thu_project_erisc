#ifndef CODEEDIT_H
#define CODEEDIT_H

#include <QWidget>
#include "codehighlighter.h"

namespace Ui {
class CodeEdit;
}

class CodeEdit : public QWidget
{
    Q_OBJECT
signals:
    void textChanged();
public:
    explicit CodeEdit(QWidget *parent = nullptr);
    ~CodeEdit();
    QString toPlainText();
    QString title();
    void setReadOnly(bool readOnly);
    QString getLine(int line);

    void setFormats(TextFormats* format);

public slots:
    void cut();
    void copy();
    void paste();
    void undo();
    void redo();
    void clear();
    void setPlainText(const QString &text);
    void setTitle(const QString &title);

private slots:
    void updateLineNumbers();
    void updateLineIdList();
    void emitTextChanged();

private:
    Ui::CodeEdit *ui;
    CodeHighlighter* highlighter;
    int oldLineAmount;
};

#endif // CODEEDIT_H
