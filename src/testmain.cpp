#include "testmain.h"
#include "exception/exception.h"
#include <iostream>
using namespace std;
int testMain()
{
    Exception a("test");
    Exception b("test2", a);
    cout << b.what() << endl;
    return 0;
}
