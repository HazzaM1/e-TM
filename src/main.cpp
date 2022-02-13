#include <QCoreApplication>
#include "sockettest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SocketTest cTest;
    qDebug() << cTest.ReadDB("drivers");

    return a.exec();
}
