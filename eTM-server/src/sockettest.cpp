#include "sockettest.h"
#include <QIODevice>
#include <iostream>

struct ServerTest::Request {
    QString clientIP = {};
    QString clientID = {};
    QString request = {};
};

ServerTest::ServerTest() : QTcpServer()
    {qDebug() << "Starting server" ;
//    qDebug() << socket->bind(QHostAddress::LocalHost,80,QAbstractSocket::ShareAddress);
    this->listen(QHostAddress::LocalHost ,80);
    qDebug() << this->errorString();
    connect( this,   &QTcpServer::newConnection,
             this,   &ServerTest::onConnect);
//    Connect();
    }

ServerTest::~ServerTest()
    {socket->disconnectFromHost();
    socket->waitForDisconnected();}

//QString ServerTest::getClientIP(QString header)
//    {QString res = {};
//     std::string temp = header.toStdString();
//     int i = temp.find("Forwarded")+9;
//     bool flag(false);
//     while(true)
//        {if((isalnum(temp[i]) || temp[i] == '.' || temp[i] == ':') && flag)     res.append(temp[i]);
//         if(temp[i] == ':')                                                     flag = true;
//         if(temp[i] == ',' || temp[i] == '\r')                                  break;
//         i++;}
//      return res;}

// TODO:receiveMessage
// messageToRequest()
// push request into TODO:requestStack
// emit signal TODO:pendingRequest

// TODO:processRequest
// access requestStack
// pull latest request
// implement directives TODO:resquestDirectives
// ***


// runs 1# in TODO:receiveMessage
// message format <ClientIP:ClientID:Request>
ServerTest::Request ServerTest::messageToRequest(QString message)
    {Request req;
     std::string temp = message.toStdString();
     bool IPflag(false), IDflag(false);
     for(auto &c : temp)
        {if(isalnum(c) || c == '.' || c == ':')
            {if(!IPflag)    req.clientIP.append(c);
             if(!IDflag)    req.clientID.append(c);
             else           req.request.append(c);}
         if(c == ':')
             {if(!IPflag)   IPflag = true;
              if(!IDflag)   IDflag = true;}}
     return {};}

//void ServerTest::tcpReady()
//    { QByteArray array = socket->read(socket->bytesAvailable());
//      qDebug() << array; }

void ServerTest::tcpReady()
    {auto message = socket->readAll();

//     QString ip = getClientIP(message);

//     qDebug() << message ;
//     qDebug() << ip ;

//     socket->write("hey"); // Implement SIGNATURE KEY
//     socket->waitForBytesWritten(1000);

//    QByteArray *buffer = buffers.value(socket);
//    while (socket->bytesAvailable() > 0)
//        {buffer->append(socket->readAll());}
//    std::cout << buffer << " TEST " ;
    }

void ServerTest::tcpError(QTcpSocket::SocketError error)
    { qDebug() << error ; }

bool ServerTest::start_listen(int port_no)
    {if (!this->listen(QHostAddress::LocalHost, 80))
        {qDebug() << "Error : Cannot listen to port ";
        return false;}
    else
        return true;}

void ServerTest::onConnect()
    {qDebug() << "CONNECTION" ;
    while (this->hasPendingConnections())
        {qDebug() << "has pending connections" ;
         socket = this->nextPendingConnection();
//         qDebug() << socket->peerAddress();
         connect( socket, &QTcpSocket::errorOccurred,
                  this,   &ServerTest::tcpError);
         connect( socket, &QTcpSocket::readyRead,
                  this,   &ServerTest::receiveMessage);
         socket->setSocketOption(QAbstractSocket::KeepAliveOption, true );

         QByteArray *buffer = new QByteArray();
         buffers.insert(socket, buffer);}
          }
void ServerTest::receiveMessage()
    {requestQueue.enqueue(messageToRequest(socket->readAll()));
    emit d;}
// use threads

////////////////////////////////////////////////////////

//QString ServerTest::GET(QString url)
//    {response = manager.get(QNetworkRequest(QUrl(url)));
//    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
//    event.exec();
//    return response->readAll();}

//QString ServerTest::ReadDB(QString args)
//    {return GET("https://" + connect_url + "/DBtest.php?arg=" + args) ;}
