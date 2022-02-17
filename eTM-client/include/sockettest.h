#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>

class SocketTest : public QObject
{   Q_OBJECT

    public:
        // Constructor & Destructor
        explicit SocketTest();
        ~SocketTest();

        // TEST FUNCTION
        //      Perform a DATABASE test operation
        //      through an HTTP GET request
        QString ReadDB(QString args);

        //      Test connection to server
        void Connect();

//    signals:
//    public slots:

    private:
        //      Reads incoming message from server
        void tcpReady();

        //      Third-party server holding the eTM server address
        const QString placeholder_url = "https://pastebin.com/raw/YjYEUC6K";

        //      Perform a GET Request to HTTP server
        QString GET(QString url), connect_url;

        //      Private Data struct
        QTcpSocket* socket = new QTcpSocket(this);
        QNetworkAccessManager manager;
        QNetworkReply *response;
        QEventLoop event;
};

#endif
