#include "testmain.h"
#include "command/lineid.h"
#include "vm/lineidlist.h"
#include <iostream>
using namespace std;
using namespace erisc;
using namespace vm;
int testMain()
{
    try 
    {
        const char* params = "      asdfg, x5";
        Command* test = new Command(2, params);
        test = test;
    }
    catch (Exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
