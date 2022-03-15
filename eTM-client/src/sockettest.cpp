#include "sockettest.h"

        //      Constructor
SocketTest::SocketTest()
    {   //  Fetch server address - IMPORTANT
    connect_url =  GET(placeholder_url);
        //  error handling
    // connect( this, &QTcpSocket::errorOccurred ,
    //          this,   &SocketTest::tcpError);
     connect( this, &QSslSocket::readyRead,
              this, &SocketTest::tcpReady);}

//        //      Destructor
//SocketTest::~SocketTest()
//    {this->disconnectFromHost();
//    this->waitForDisconnected();}



        //      Test connection to server
void SocketTest::Connect()
    {   //  Connect to LocalHost for TEST
    this->connectToHost(QHostAddress::LocalHost , 80);
//    this->connectToHost("6.tcp.ngrok.io" , 12730);
//    this->write(this->localAddress().toString().toUtf8()+ ":" + QString::number(this->localPort()).toUtf8());
        //  Will connect remote server
    //  this->connectToHost(connect_url, 80);
    if(this->waitForConnected(6000))
        {qDebug() << "Connected!";
            //  Sending client IP
//        this->write( this->localAddress().toString().toUtf8() + ":" ); // + userID
//        this->waitForBytesWritten(1000);
        this->setSocketOption(QAbstractSocket::KeepAliveOption, true );
        }
    else
        qDebug() << "Not connected!";}



    //      Reads incoming message from server
void SocketTest::tcpReady()
    {this->waitForBytesWritten(2000);
    auto message = this->readAll();
     qDebug() << message;}



    //      Perform a GET Request to HTTP server
QString SocketTest::GET(QString url)
    {response = manager.get(QNetworkRequest(QUrl(url)));
    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    return response->readAll();}


bool SocketTest::sendRequest(QString string)
    {if (this->waitForConnected(2000))
        {this->write(this->localAddress().toString().toUtf8()+ ":" + QString::number(this->localPort()).toUtf8() + " : " + string.toUtf8()); // + userID
         this->waitForBytesWritten(2000);
         qDebug() << "Message Sent";
         return true;}
    qDebug() << "Message Not Sent";
    return false;}

// Perform a DATABASE test operation
// through an HTTP GET request
//QString ServerTest::ReadDB(QString args)
//    {return GET("https://" + connect_url + "/DBtest.php?arg=" + args) ;}
//
