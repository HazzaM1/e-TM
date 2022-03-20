#ifndef SERVERTEST_H
#define SERVERTEST_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QUrl>
#include <QHostAddress>
#include <QtNetwork>
#include <QEventLoop>
#include <QQueue>
#include <string>


class ServerTest : public QTcpServer
{   Q_OBJECT

    public:
        //      Constructor & Destructor
        explicit ServerTest();
        ~ServerTest();

        //      Public Data Structure
        //      <IP:ID:request>
        struct Request;

// Working on signals
//    signals:
//        void requestPending(Request req);

    public slots:
        //      Handling incoming connections
        //      if error            -> tcpError()
        //      if incoming message -> receiveMessage()
        void onConnect();

        //      WORK IN PROGRESS
        void receiveMessage();

        //      Handles socket errors :
        //      displaying error received
        void tcpError(QAbstractSocket::SocketError error);

    private:
        //      Queue containing Requests to be handled
        QQueue<Request> requestQueue;

        //      runs 1# in TODO:receiveMessage
        //      message format <ClientIP:ClientID:Request>
        Request messageToRequest(QString header);

        //      Private Data struct
        QTcpSocket* socket = new QTcpSocket(this);
        QNetworkAccessManager manager;
        QNetworkReply *response;
        QEventLoop event;
        QHash<QTcpSocket*, QByteArray*> buffers;

        //      TEST DATA STRUCT
        QString requestDirectives[2] = {"NEW ACCOUNT", "function"};

        QString getClientIP(QString header);
};

#endif
