#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QObject>
#include <QSslSocket>
#include <QDebug>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>

class SocketTest : public QSslSocket
{   Q_OBJECT

    public:
        SocketTest();
//        ~SocketTest();
        void Connect();
        bool sendRequest(QString string);

//        // TEST FUNCTION
//        //      Perform a DATABASE test operation
//        //      through an HTTP GET request
//        QString ReadDB(QString args);

    private:
        //      Reads incoming message from server
        void tcpReady();

        //      Third-party server holding the eTM server address
        const QString placeholder_url = "https://pastebin.com/raw/YjYEUC6K";

        //      Perform a GET Request to HTTP server
        QString GET(QString url), connect_url;

        //      Private Data struct
        QNetworkAccessManager manager;
        QNetworkReply *response;
        QEventLoop event;
};

#endif
