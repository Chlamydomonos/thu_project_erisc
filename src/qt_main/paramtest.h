#ifndef PARAMTEST_H
#define PARAMTEST_H
#include <QString>

bool paramTest(QString commandName, QString param, int paramIndex);
bool isRegister(QString param);
bool isNumber(QString param);
int paramAmount(QString commandName);
#endif // PARAMTEST_H
