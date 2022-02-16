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
        explicit SocketTest(QObject *parent = 0);
        QString ReadDB(QString args);
        void Connect();

    signals:
    public slots:

    private:
        void tcpReady();
        const QString placeholder_url = "https://pastebin.com/raw/YjYEUC6K";
        QString GET(QString url), connect_url;
        QTcpSocket* socket = new QTcpSocket(this);
        QNetworkAccessManager manager;
        QNetworkReply *response;
        QEventLoop event;
};

#endif
