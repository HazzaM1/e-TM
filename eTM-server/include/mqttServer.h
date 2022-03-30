//#include <QObject>
//#include <QDebug>

//#include <QtNetwork>
//#include <QEventLoop>

//#include <process.h>

//#include <QMqttClient>

//#include <string>


//class mqttServer : public QMqttClient
//{   Q_OBJECT

//    public:
//        mqttServer();
//        void sendRequest(QString string, QString clientID);
//// Working on signals
////    signals:
////        void requestPending(Request req);


//    private:

//        QHostAddress serverAddress = QHostAddress::LocalHost;
//        QString GET(QString url);
//        QString ReadDB(QString args);
//        Process requestToProcess(QString message);

//        //      TEST DATA STRUCT
//        //QString requestDirectives[2] = {"g","h"};

//    signals:
//        void requestReceived(Process);

//    public slots:
//        void incomingRequest(const QByteArray &message);

//        //  TEMPORARY TEST
//        void receiveMessage(const QByteArray &message);
//        //  TEMPORARY TEST

////        //      Handles socket errors :
////        //      displaying error received
////        void error(QAbstractSocket::SocketError error);
//};

//#endif






#ifndef MQTTSERVER_H
#define MQTTSERVER_H

#include <QObject>

#include <QMqttClient>

#include <QRegularExpression>

#include <vector>
#include <process.h>
#include <QHostAddress>



class mqttServer : public QObject
{   Q_OBJECT

    public:
        mqttServer(std::vector<clientDetails> *clientList);
        QMqttClient *client;

    private:
        const QString placeholder_url = "https://pastebin.com/raw/YjYEUC6K";
        QHostAddress serverAddress = QHostAddress::LocalHost;

        std::vector<clientDetails> *clients;

        QRegularExpression *requestRegex = new QRegularExpression("([0-9]+):([0-9]+):([0-9]{1,3}):(.*)");
        QRegularExpression *paramsRegex = new QRegularExpression("([^:]+)");
        Process requestToProcess(QString message);

    signals:
        void connected();
        void testFlag(QString);
        void authRequest(QString string);
        void incomingProcess(Process process);

    public slots:
        bool sendRequest(QString channelID, std::vector<std::string> requestParam);
        void init();
        void brokerHandshake();
        void firstHandshake(QString channelID);
        void incomingRequest(const QByteArray &message, const QMqttTopicName &topic);
};

#endif
