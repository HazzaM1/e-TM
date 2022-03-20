#include <QApplication>
#include <QtWidgets>

#include <mqttClient.h>
#include <client.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSize screenSize = a.screens().at(0)->size();
    client *myWin = new client(screenSize.width(), screenSize.height());
    return a.exec();
}
