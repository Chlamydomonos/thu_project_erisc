#include "testmain.h"
#include "image/canvas.h"
#include <iostream>
using namespace std;
using namespace image;
int testMain()
{
    try 
    {
        Canvas* canvas = new Canvas("D:\\dzy\\test.bmp");
        Canvas* canvas2 = new Canvas(20, 20);
        canvas2->setColor(0, 0, 2, 2, 0xffffff);
        canvas2->applyCanvas(2, 2, canvas);
        canvas2->writeToFile("D:\\dzy\\test2.bmp");
    }
    catch (Exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
