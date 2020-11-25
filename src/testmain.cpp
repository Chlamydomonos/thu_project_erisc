#include "testmain.h"
#include "exception/exception.h"
#include "command/command.h"
#include <iostream>
using namespace std;
int testMain()
{
    int n = 3;
    const char* x = " zero -100 0x1000";
    char* a = new char[1000];
    for (int i = 0; i < 1000; i++)
        a[i] = 0;
    for (int i = 0; i <= strlen(x); i++)
        a[i] = x[i];
    try
    {
        Command* c = new Command(n, a);
    }
    catch (Exception e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
