#include "manager.h"
#include <QDebug> //

manager::manager(QQueue<Process> *pQueue)
    {// DATA //
     processQueue = pQueue;
     mqttDirectives = {{&mqttServer::sendRequest}};
     dbDirectives = {{&DBmanager::authQuery}};}

void manager::treatProcess()
    {queueFlag = true;
    while(!processQueue->isEmpty())
        {Process currentProcess = processQueue->dequeue();
        int destCode = currentProcess.processCode[0] - 48;
        int extraCode  = currentProcess.processCode[1] - 48;
        int processCode = currentProcess.processCode[2] - 48;
        int appID = currentProcess.appID;
        int clientID = currentProcess.clientID; // For Privileges Check
        QString channelID;
        for (const clientDetails &client : *clients)
            {if (client.appID == appID)
                channelID = QString::fromStdString(client.channelID);}
        switch(destCode)
                {   // 0 : Database Directives
                 case 0: (DB->*dbDirectives[extraCode][processCode])(appID, currentProcess.processParam); break;
                 case 1: /* (signUpPage->*signUpPageDirectives[extraCode][processCode])( /// ); */ break;
                 case 2: /* (signUpForm->*signUpFormDirectives[extraCode][processCode])( /// ); */ break;
                 case 3: /* (mainPage->*mainDirectives[extraCode][processCode])( /// ); */ break;
                 case 4: /* (listTab->*listTabDirectives[extraCode][processCode])( /// ); */ break;
                 case 5: /* (objectPage->*objectDirectives[extraCode][processCode])( /// ); */ break;
                 case 6: /* (signInPage->*signInDirectives[extraCode][processCode])( /// ); */ break;
                 case 7: /* (signInPage->*signInDirectives[extraCode][processCode])( /// ); */ break;
                 case 8: /* (signInPage->*signInDirectives[extraCode][processCode])( /// ); */ break;
                    // 9 : MQTT Client Directives
                 case 9: (mqtt->*mqttDirectives[extraCode][processCode])(channelID, currentProcess.processParam); break;}}
     queueFlag = false;
     emit pQueueEmpty();}
