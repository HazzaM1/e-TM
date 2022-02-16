#ifndef SOCKETTEST_H
#define SOCKETTEST_H

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
        explicit ServerTest();
        ~ServerTest();
        struct Request;
        void onConnect(), receiveMessage();

    signals:
        void requestPending(Request req);

    public slots:
        void tcpReady();
        void tcpError(QAbstractSocket::SocketError error);
        bool start_listen(int port_no = 80);

    private:
//        QString GET(QString url);
        QQueue<Request> requestQueue;

        Request messageToRequest(QString header);

        QTcpSocket* socket = new QTcpSocket(this);
        QNetworkAccessManager manager;
        QNetworkReply *response;
        QEventLoop event;
        QHash<QTcpSocket*, QByteArray*> buffers;

        QString requestDirectives[2] = {"g","h"};
};

#endif
