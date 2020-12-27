#include "paramtest.h"
#include <QRegularExpression>
#include <QRegularExpressionMatchIterator>
#include <QRegularExpressionMatch>

namespace
{
    QString _registerParam("x([1-2]?[0-9]|30|31)|zero|ra|sp|gp|tp|t[0-6]|fp|s[1-9]|s10|s11|a[0-7]");
    QString _bigIntParam("-2147483648|(-)?(214748364[0-7]|21474836[0-3][0-9]|2147483[0-5][0-9]{2}|214748[0-2][0-9]{3}|21474[0-7][0-9]{4}|2147[0-3][0-9]{5}|214[0-6][0-9]{6}|21[0-3][0-9]{7}|20[0-9]{8}|1[0-9]{9})");
    QString _numberParam = "0x0*[0-9A-Fa-f]{0,8}+|" + _bigIntParam + "|(-)?[1-9][0-9]{0,8}|0";
    QRegularExpression registerParam(_registerParam);
    QRegularExpression numberParam(_numberParam);
    bool testSingleParam(QString commandName, bool isRegister, bool isNumber, int paramIndex)
    {
        bool isLineId = !(isRegister || isNumber);
        if(commandName == "load" || commandName == "store")
        {
            if(paramIndex == 0)
                return isRegister;
            else if(paramIndex == 1)
                return isRegister;
            else
                return false;
        }
        else if(commandName == "push" || commandName == "pop")
        {
            if(paramIndex == 0)
                return isRegister;
            else
                return false;
        }
        else if(commandName == "mov")
        {
            if(paramIndex == 0)
                return isRegister;
            else if(paramIndex == 1)
                return isRegister || isNumber;
            else
                return false;
        }
        else if(commandName == "add" || commandName == "sub" || commandName == "mul" || commandName == "div" || commandName == "rem" || commandName == "and" || commandName == "or")
        {
            if(paramIndex == 0)
                return isRegister;
            else if(paramIndex == 1)
                return isRegister;
            else if(paramIndex == 2)
                return isRegister || isNumber;
        }
        else if(commandName == "jal")
        {
            if(paramIndex == 0)
                return isLineId;
            else
                return false;
        }
        else if(commandName == "beq" || commandName == "bne" || commandName == "blt" || commandName == "bge")
        {
            if(paramIndex == 0)
                return isRegister;
            else if(paramIndex == 1)
                return isRegister;
            else if(paramIndex == 2)
                return isLineId;
            else
                return false;
        }
        else if(commandName == "call")
        {
            if(paramIndex == 0)
                return isLineId;
            else
                return false;
        }
        return false;
    }
}

bool paramTest(QString commandName, QString param, int paramIndex)
{
    bool isRegister = false;
    bool isNumber = false;

    QRegularExpressionMatchIterator i1 = registerParam.globalMatch(param);
    if(i1.hasNext())
    {
        QRegularExpressionMatch match = i1.next();
        if(match.capturedStart() == 0 && match.capturedLength() == param.length())
            isRegister = true;
    }

    QRegularExpressionMatchIterator i2 = numberParam.globalMatch(param);
    if(i2.hasNext())
    {
        QRegularExpressionMatch match = i2.next();
        if(match.capturedStart() == 0 && match.capturedLength() == param.length())
            isNumber = true;
    }

    return testSingleParam(commandName, isRegister, isNumber, paramIndex);
}

bool isRegister(QString param)
{
    QRegularExpressionMatchIterator i = registerParam.globalMatch(param);
    if(i.hasNext())
    {
        QRegularExpressionMatch match = i.next();
        return match.capturedStart() == 0 && match.capturedLength() == param.length();
    }
    return false;
}

bool isNumber(QString param)
{
    QRegularExpressionMatchIterator i = numberParam.globalMatch(param);
    if(i.hasNext())
    {
        QRegularExpressionMatch match = i.next();
        return match.capturedStart() == 0 && match.capturedLength() == param.length();
    }
    return false;
}

int paramAmount(QString commandName)
{
    if(commandName == "load" || commandName == "store")
        return 2;
    else if(commandName == "push" || commandName == "pop")
        return 1;
    else if(commandName == "mov")
        return 2;
    else if(commandName == "add" || commandName == "sub" || commandName == "mul" || commandName == "div" || commandName == "rem" || commandName == "and" || commandName == "or")
        return 3;
    else if(commandName == "jal")
        return 1;
    else if(commandName == "beq" || commandName == "bne" || commandName == "blt" || commandName == "bge")
        return 3;
    else if(commandName == "call")
        return 1;
    return 0;
}
