#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
    {connect_url =  GET(placeholder_url);
//     connect( socket, &QTcpSocket::errorOccurred ,
//              this,   &SocketTest::tcpError);
     connect( socket, &QTcpSocket::readyRead,
              this,   &SocketTest::tcpReady);}

void SocketTest::Connect()
    {

    socket->connectToHost(QHostAddress::LocalHost , 80);
//    socket->connectToHost(connect_url, 80);

    if(socket->waitForConnected(6000))
        {qDebug() << "Connected!";
        socket->write( socket->localAddress().toString().toUtf8() + ":" ); // + userID
        socket->waitForBytesWritten(1000);}
    else
        {qDebug() << "Not connected!";}}

QString SocketTest::GET(QString url)
    {response = manager.get(QNetworkRequest(QUrl(url)));
    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    return response->readAll();}

QString SocketTest::ReadDB(QString args)
    {return GET("https://" + connect_url + "/DBtest.php?arg=" + args) ;}

void SocketTest::tcpReady()
    {auto message = socket->readAll();
     qDebug() << message;
//    socket->write("y");

//    QByteArray *buffer = buffers.value(socket);
//    while (socket->bytesAvailable() > 0)
//        {buffer->append(socket->readAll());}
//    std::cout << buffer << " TEST " ;
    }
