#include "sockettest.h"

        //      Constructor
SocketTest::SocketTest()
    {   //  Fetch server address - IMPORTANT
    connect_url =  GET(placeholder_url);
        //  error handling
    // connect( socket, &QTcpSocket::errorOccurred ,
    //          this,   &SocketTest::tcpError);
     connect( socket, &QTcpSocket::readyRead,
              this,   &SocketTest::tcpReady);}

        //      Destructor
SocketTest::~SocketTest()
    {socket->disconnectFromHost();
    socket->waitForDisconnected();}



        //      Test connection to server
void SocketTest::Connect()
    {   //  Connect to LocalHost for TEST
    socket->connectToHost(QHostAddress::LocalHost , 80);
        //  Will connect remote server
    //  socket->connectToHost(connect_url, 80);
    if(socket->waitForConnected(6000))
        {qDebug() << "Connected!";
            //  Sending client IP
        socket->write( socket->localAddress().toString().toUtf8() + ":" ); // + userID
        socket->waitForBytesWritten(1000);}
    else
        qDebug() << "Not connected!";}



    //      Reads incoming message from server
void SocketTest::tcpReady()
    {auto message = socket->readAll();
     qDebug() << message;}



    //      Perform a GET Request to HTTP server
QString SocketTest::GET(QString url)
    {response = manager.get(QNetworkRequest(QUrl(url)));
    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    return response->readAll();}



// Perform a DATABASE test operation
// through an HTTP GET request
//QString ServerTest::ReadDB(QString args)
//    {return GET("https://" + connect_url + "/DBtest.php?arg=" + args) ;}
//
