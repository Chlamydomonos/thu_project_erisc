#include "testmain.h"
#include "command/commands/jal.h"
#include <iostream>
#include "command/lineid.h"
using namespace std;
using namespace erisc;
using namespace vm;
int testMain()
{
    try 
    {
        VM* vm = new VM(1000);
        LineId* id = new LineId("hello", 2);
        vm->getLineIdList()->add(id);
        Command* jal = new Jal(" hello");
        jal->run(vm);
        vm = vm;
    }
    catch (Exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
