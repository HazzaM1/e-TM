#include <QApplication>

#include <server.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    server *myWin = new server;
    return a.exec();
}
