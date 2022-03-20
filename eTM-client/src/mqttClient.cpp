#include "mqttClient.h"


mqttClient::mqttClient(int *aID, int *cID)
    {appID = aID;
     clientID = cID;}


void mqttClient::init()
    {client = new QMqttClient;
     client->setHostname("127.0.0.1");
     client->setPort(1883);
     client->connectToHost();
     connect(client, &QMqttClient::connected, this, &mqttClient::firstHandshake);
     connect(client, &QMqttClient::messageReceived, this, &mqttClient::incomingRequest);
     connect(client, &QMqttClient::pingResponseReceived, this, [](){});}


void mqttClient::firstHandshake()
    {if (client->publish(QMqttTopicName("CtS/first"), client->clientId().toUtf8()) != -1)
        if (client->subscribe(QMqttTopicFilter("StC/"+client->clientId().toUtf8())))
            qDebug() << "Broker handshake successful !"; }


// request <appID:clientID:requestCode:requestParams>
bool mqttClient::sendRequest(std::vector<std::string> requestParam)
    {QByteArray message = QByteArray::fromStdString(std::to_string(*appID) +":"+ std::to_string(*clientID));
     for (const std::string &param : requestParam) message.append(":"+param);
     const QMqttTopicName topic = QMqttTopicName("CtS/"+client->clientId());
     qDebug() << "Sending " << topic.name() << " " << message;
     if (client->publish(topic, message) != -1) {return true;}
     return false;}


void mqttClient::incomingRequest(const QByteArray &message, const QMqttTopicName &topic)
    {qDebug() << "Receiving " <<topic.name() << " " << message;
    emit incomingProcess(requestToProcess(message));}


Process mqttClient::requestToProcess(QString message)
    {Process process;
     QRegularExpressionMatch match = requestRegex->match(message);
     if (match.hasMatch() || match.hasPartialMatch())
        {std::strcpy(process.processCode, match.captured(1).toStdString().c_str());
         QRegularExpressionMatchIterator paramMatch = paramsRegex->globalMatch(match.captured(2));
         while (paramMatch.hasNext())
              process.processParam.push_back(paramMatch.next().captured(1).toStdString());}
     return process;}
