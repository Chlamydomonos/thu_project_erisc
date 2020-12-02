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
        LineId* testid1 = new LineId("A", 1);
        LineId* testid2 = new LineId("B", 2);
        LineId* testid3 = new LineId("C", 3);
        LineId* testid4 = new LineId("D", 4);
        LineId* testid5 = new LineId("E", 5);
        LineId* testid6 = new LineId("a", 6);
        LineId* testid7 = new LineId("b", 7);
        LineId* testid8 = new LineId("c", 8);
        LineId* testid9 = new LineId("d", 9);
        LineId* testid10 = new LineId("e", 10);
        LineId* testid11 = new LineId("AA", 11);
        LineId* testid12 = new LineId("AB", 12);
        LineId* testid13 = new LineId("AC", 13);
        LineId* testid14 = new LineId("AD", 14);
        LineId* testid15 = new LineId("AE", 15);
        LineId* testid16 = new LineId("Aa", 16);
        LineId* testid17 = new LineId("Ab", 17);
        LineId* testid18 = new LineId("Ac", 18);
        LineId* testid19 = new LineId("Ad", 19);
        LineId* testid20 = new LineId("Ae", 20);
        LineIdList* testList = new LineIdList();
        testList->add(testid1);
        testList->add(testid2);
        testList->add(testid3);
        testList->add(testid4);
        testList->add(testid5);
        testList->add(testid6);
        testList->add(testid7);
        testList->add(testid8);
        testList->add(testid9);
        testList->add(testid10);
        testList->add(testid11);
        testList->add(testid12);
        testList->add(testid13);
        testList->add(testid14);
        testList->add(testid15);
        testList->add(testid16);
        testList->add(testid17);
        testList->add(testid18);
        testList->add(testid19);
        testList->add(testid20);
        LineId* testidout = (*testList)["AE"];
        cout << testidout->getLine();
    }
    catch (Exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
