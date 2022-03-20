#include "dbmanager.h"

DBmanager::DBmanager(std::vector<clientDetails> *clientList)
    {clients = clientList;}

QString DBmanager::GET(QString url)
    {QNetworkAccessManager manager;
     QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));
     QEventLoop event;
     connect(response, &QNetworkReply::finished, &event, &QEventLoop::quit);
     event.exec();
     return response->readAll();}

void DBmanager::authQuery(int appID, std::vector<std::string> args)
    {QString dbReply = GET("http://127.0.0.1:8008/scripts/authQuery.php?email="+ QString::fromStdString(args[0]) +"&password="+QString::fromStdString(args[1]));
     if (dbReply != "000")
        {clients->at(appID).clientID = dbReply.toInt();
         emit authReply({appID, dbReply.toInt(), {'9','0','0'}, {"901", dbReply.toStdString()}});}
    else {emit authReply({appID, 0, {'9','0','0'}, {"910", "0"}});}}
