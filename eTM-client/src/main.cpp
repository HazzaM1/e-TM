#include <QApplication>
#include <QtWidgets>

#include <sockettest.h>
#include <client.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSize screenSize = a.screens().at(0)->size();

//    SocketTest cTest;
//    cTest.Connect();
//    qDebug() << cTest.ReadDB("drivers");

    client *myWin = new client(screenSize);
    return a.exec();
}
