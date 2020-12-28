#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(w.size());
    w.show();
    w.setApp(&a);

    QFile configFile("skin.cfg");
    configFile.open(QIODevice::ReadOnly);

    int skin = 0;

    if(configFile.isReadable())
        configFile.read((char*)&skin, sizeof (skin));

    configFile.close();
    w.setSkin(skin);
    return a.exec();
}
