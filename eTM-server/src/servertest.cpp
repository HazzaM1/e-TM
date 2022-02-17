#include "servertest.h"
#include <QIODevice>
#include <iostream>

// Data Struct Definition
struct ServerTest::Request
    {QString clientIP = {};
    QString clientID = {};
    QString request = {};};

        // TODO:receiveMessage  - pending
        // messageToRequest()   - DONE
        // push request into TODO:requestQueue   -
        // emit signal TODO:pendingRequest

        // TODO:processRequest
        // access requestStack
        // pull latest request
        // implement directives TODO:resquestDirectives
        //      ***

    // Constructor
ServerTest::ServerTest() : QTcpServer()
    {qDebug() << "Starting server" ;
        // Listen to request on localhost:80
     this->listen(QHostAddress::LocalHost ,80);
        // If error while listening, display error message
     if( !this->isListening() ) qDebug() << this->errorString();
        // Handles connection -> onConnect()
     connect( this,   &QTcpServer::newConnection,
             this,   &ServerTest::onConnect);}

    // Destructor
ServerTest::~ServerTest()
    {this->disconnect();
    socket->disconnectFromHost();
    socket->waitForDisconnected();}



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
     return req;}



    //      Handles socket errors :
    //      displaying error received
void ServerTest::tcpError(QTcpSocket::SocketError error)
    { qDebug() << error ; }



    //      Handling incoming connections
    //      if error            -> tcpError()
    //      if incoming message -> receiveMessage()
void ServerTest::onConnect()
    {qDebug() << "CONNECTION" ;
    while (this->hasPendingConnections())
        {socket = this->nextPendingConnection();
            //  Because of ngrok tunneling
            //  Cannot access client IP trhough socket
        //         qDebug() << socket->peerAddress();
            // Error Handler -> tcpError()
         connect( socket, &QTcpSocket::errorOccurred,
                  this,   &ServerTest::tcpError);
            // Incoming message ready to be handled -> receiveMessage()
         connect( socket, &QTcpSocket::readyRead,
                  this,   &ServerTest::receiveMessage);
            // Keep connection alive
         socket->setSocketOption(QAbstractSocket::KeepAliveOption, true );
            //  Data handlers not needed at the moment / not here
        //         QByteArray *buffer = new QByteArray();
        //         buffers.insert(socket, buffer);
    }}


//          WORK IN PROGRESS
//
void ServerTest::receiveMessage()
    {
    requestQueue.enqueue(messageToRequest(socket->readAll()));
    // emit requestPending(messageToRequest(socket->readAll()));
    }
// use threads


////////////////////////////////////////////////////////

        // CODE CEMETARY
        // May be brought to life again

    //  Handles socket connection :
    //  Displays message in socket
//void ServerTest::displayMessage()
//    {auto message = socket->readAll();
//    qDebug() << message ;}
//

    // Perform a GET Request to HTTP server
    // Not needed with TCP server
//QString ServerTest::GET(QString url)
//    {response = manager.get(QNetworkRequest(QUrl(url)));
//    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
//    event.exec();
//    return response->readAll();}
//

    // Perform a DATABASE test operation
    // through an HTTP GET request
//QString ServerTest::ReadDB(QString args)
//    {return GET("https://" + connect_url + "/DBtest.php?arg=" + args) ;}
//

    // Parse GET request and extracts client IP
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
//

    // From tcpReady()
//  In the case of receiving a GET HTTP request
//  getClientIP() function parses the request
//  And extracts the client IP address
//          QString ip = getClientIP(message);
//          qDebug() << ip ;
//
//  Test writing to the client
//      socket->write("hey"); // Implement SIGNATURE KEY
//      socket->waitForBytesWritten(1000);
//
//  Test reading the message in socket 1#
//  With QByteArray
//      QByteArray *buffer = buffers.value(socket);
//      while (socket->bytesAvailable() > 0)
//          { buffer->append(socket->readAll()); }
//      std::cout << buffer << " TEST " ;
//
//  Test reading the message in socket 2#
//      void ServerTest::tcpReady()
//          { QByteArray array = socket->read(socket->bytesAvailable());
//          qDebug() << array; }
