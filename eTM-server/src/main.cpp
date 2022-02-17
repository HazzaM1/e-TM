#include <QCoreApplication>
#include "servertest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerTest cTest;
//    qDebug() << cTest.ReadDB("drivers");

    return a.exec();
}
