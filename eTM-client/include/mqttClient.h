#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <QObject>

#include <QMqttClient>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>

#include <QThread>

#include <QRegularExpression>

class mqttClient : public QObject
{   Q_OBJECT

    public:
        mqttClient(int *aID, int *cID);
        QMqttClient *client;

    private:
        int *appID;
        int *clientID;

        const QString placeholder_url = "https://pastebin.com/raw/YjYEUC6K";
        QHostAddress serverAddress = QHostAddress::LocalHost;
        Process requestToProcess(QString message);

        QRegularExpression *requestRegex = new QRegularExpression("([0-9]{1,3}):(.*)");
        QRegularExpression *paramsRegex = new QRegularExpression("([^:]+)");

    signals:
        void connected();
        void incomingProcess(Process process);

    public slots:
        bool sendRequest(std::vector<std::string> requestParam);
        void init();
        void firstHandshake();
        void incomingRequest(const QByteArray &message, const QMqttTopicName &topic);
};

#endif
