#include "testmain.h"
#include "io/output.h"
#include "vm/vm.h"
#include <iostream>
using namespace std;
using namespace output;
using namespace vm;
int testMain()
{
    try 
    {
        VM* vm = new VM(100);
        outputText(vm);
            delete vm;
    }
    catch (Exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
