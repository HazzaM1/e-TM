#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>

#include <process.h>

class DBmanager : public QObject
{
    Q_OBJECT

    public:
        DBmanager(std::vector<clientDetails> *clientList);

    private:
        QString GET(QString url);
        std::vector<clientDetails> *clients;

    public slots:
        void authQuery(int appID, std::vector<std::string> args);

    signals:
        void authReply(Process);
};

#endif // DBMANAGER_H
