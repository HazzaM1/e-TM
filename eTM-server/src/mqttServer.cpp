#include <mqttServer.h>

enum topics { auth, recon, users };

mqttServer::mqttServer(std::vector<clientDetails> *clientList)
    {clients = clientList;}

void mqttServer::init()
    {client = new QMqttClient;
     client->setHostname("127.0.0.1");
     client->setPort(1883);
     client->connectToHost();
     connect(client, &QMqttClient::connected, this, &mqttServer::brokerHandshake);
     connect(client, &QMqttClient::messageReceived, this, &mqttServer::incomingRequest);}


void mqttServer::brokerHandshake()
    {if (client->subscribe(QMqttTopicFilter("CtS/#")))
            qDebug() << "Broker handshake successful !"; }


void mqttServer::firstHandshake(QString channelID)
    {clients->push_back({int(clients->size()), 0,{channelID.toStdString()}});
     std::vector<std::string> params = {"900", std::to_string(clients->size()-1)};
     if (sendRequest(channelID, params)) qDebug() << "Client handshaked !";}


bool mqttServer::sendRequest(QString channelID, std::vector<std::string> requestParam)
    {QByteArray message;
     for (const std::string &param : requestParam) message.append(":"+param);
     message.remove(0,1);
     const QMqttTopicName topic = QMqttTopicName("StC/"+channelID);
     if (client->publish(topic, message) != -1) {qDebug() << "Sending " << topic.name() << " " << message; return true;}
     return false;}


void mqttServer::incomingRequest(const QByteArray &message, const QMqttTopicName &topic)
    {qDebug() << "Receiving " <<topic.name() << " " << message;
     if (topic.name() == "CtS/first")   firstHandshake(message);
//   if (topic.name() == "CtS/recon")   emit testFlag(message);
     else emit incomingProcess(requestToProcess(message));}


Process mqttServer::requestToProcess(QString message)
    {Process process;
     QRegularExpressionMatch match = requestRegex->match(message);
     if (match.hasMatch() || match.hasPartialMatch())
        {process.appID = match.captured(1).toInt();
         process.clientID = match.captured(2).toInt();
         std::strcpy(process.processCode, match.captured(3).toStdString().c_str());
         QRegularExpressionMatchIterator paramMatch = paramsRegex->globalMatch(match.captured(4));
         while (paramMatch.hasNext())
              process.processParam.push_back(paramMatch.next().captured(1).toStdString());}
     return process;}
