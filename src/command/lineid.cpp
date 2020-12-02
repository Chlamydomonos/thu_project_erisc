#include "lineid.h"

#define HEAD_LEN 40
#define BUFFER_LEN 66

#define CAPITAL(a) ((a) >= 'A' && (a) <= 'Z')
#define GET_CAPITAL(a) (CAPITAL(a) ? (a) : (a) - ('a' - 'A'))
#define SAME(a, b) (GET_CAPITAL(a) == GET_CAPITAL(b))
#define LTRBGR(a, b) (SAME(a, b) ? (a > b) : (GET_CAPITAL(a) > GET_CAPITAL(b)))
#define LTRSMR(a, b) (SAME(a, b) ? (a < b) : (GET_CAPITAL(a) < GET_CAPITAL(b)))
#define CHRBGR(a, b) ((a) == 0 ? false : ((b) == 0 ? true : LTRBGR(a, b)))
#define CHRSMR(a, b) ((b) == 0 ? false : ((a) == 0 ? true : LTRSMR(a, b)))
namespace
{
    const char* exceptionHead = "Found conflict line identifier at lines ";

    char buffer[BUFFER_LEN] = { 0 };

    char* genExceptionStr(int a, int b)
    {
        if (buffer[0] != 'F')
            for (int i = 0; i < HEAD_LEN; i++)
                buffer[i] = exceptionHead[i];
        char* i = buffer + HEAD_LEN;
        while (a > 0)
        {
            *i = a % 10 + '0';
            a /= 10;
            i++;
        }
        *i = ' ';
        i++;
        *i = 'a';
        i++;
        *i = 'n';
        i++;
        *i = 'd';
        i++;
        *i = ' ';
        i++;
        while (b > 0)
        {
            *i = b % 10 + '0';
            b /= 10;
            i++;
        }
        *i = 0;
        return buffer;
    }
}

erisc::LineId::LineId(const char* name, int line) : Command()
{
    int len = strlen(name);
    this->name = new char[len + 1];
    for (int i = 0; i < len; i++)
        this->name[i] = name[i];
    this->name[len] = 0;
    this->line = line;
}

erisc::LineId::~LineId()
{
    delete[] name;
}

char* erisc::LineId::getName()
{
    return name;
}

int erisc::LineId::getLine()
{
    return line;
}

bool erisc::LineId::strSame(const char* a, const char* b)
{
    if (strlen(a) != strlen(b))
        return false;
    for (int i = 0; i < strlen(a); i++)
        if (a[i] != b[i])
            return false;
    return true;
}

bool erisc::LineId::strBigger(const char* a, const char* b)
{
    if (*a == *b && *a != 0)
        return strBigger(a + 1, b + 1);
    return CHRBGR(*a, *b);
}

bool erisc::LineId::strSmaller(const char* a, const char* b)
{
    if (*a == *b && *a != 0)
        return strSmaller(a + 1, b + 1);
    return CHRSMR(*a, *b);
}

bool erisc::LineId::operator==(const LineId& b)
{
    if (strSame(this->name, b.name))
    {
        if (this->line != b.line)
            throw Exception(genExceptionStr(this->line - 1, b.line - 1));
        return true;
    }
    return false;
}

bool erisc::LineId::operator>(const LineId& b)
{
    if(strSame(this->name, b.name) && this->line != b.line)
        throw Exception(genExceptionStr(this->line - 1, b.line - 1));
    return strBigger(this->name, b.name);
}

bool erisc::LineId::operator<(const LineId& b)
{
    if (strSame(this->name, b.name) && this->line != b.line)
        throw Exception(genExceptionStr(this->line - 1, b.line - 1));
    return strSmaller(this->name, b.name);
}

bool erisc::LineId::operator>=(const LineId& b)
{
    if (strSame(this->name, b.name) && this->line != b.line)
        throw Exception(genExceptionStr(this->line - 1, b.line - 1));
    return !strSmaller(this->name, b.name);
}

bool erisc::LineId::operator<=(const LineId& b)
{
    if (strSame(this->name, b.name) && this->line != b.line)
        throw Exception(genExceptionStr(this->line - 1, b.line - 1));
    return !strBigger(this->name, b.name);
}
