#include "testmain.h"
#include "exception/exception.h"
#include "command/commands/mov.h"
#include <iostream>
#include <exception>
using namespace std;
using namespace erisc;
int testMain()
{
    try {
        char* str = new char[1024];
        *str = ' ';
        cin >> str + 1;
        VM* vm = new VM(1024);
        Command* mov = new Mov(str);
        mov->run(vm);
        cout << vm->getRegister(5)->read();
        delete[] str;
        delete vm;
        delete mov;
    }
    catch (Exception& e)
    {
        cout << e.what();
    }
    return 0;
}
