#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
    {connect_url =  GET(placeholder_url);}

void SocketTest::Connect()
    {socket->connectToHost(connect_url, 80);
    if(socket->waitForConnected(6000))
        {qDebug() << "Connected!";
        socket->close();}
    else
        {qDebug() << "Not connected!";}}

QString SocketTest::GET(QString url)
    {response = manager.get(QNetworkRequest(QUrl(url)));
    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    return response->readAll();}

QString SocketTest::ReadDB(QString args)
    {return GET("https://" + connect_url + "/DBtest.php?arg=" + args) ;}
