#include "manager.h"
#include <QDebug> //

manager::manager(int w, int h, QQueue<Process> *pQueue)
    {// DATA //
     width = w;
     height = h;
     welcome = new welcomePage(w, h);
     processQueue = pQueue;
     mqttDirectives = {{&mqttClient::sendRequest}, {}};
     managerDirectives = {{&manager::setAppID, &manager::authValidated},
                          {&manager::authFailed}};}


void manager::treatProcess()
    {queueFlag = true;
    while(!processQueue->isEmpty())
        {Process currentProcess = processQueue->dequeue();
        int destCode = currentProcess.processCode[0] - 48;
        int extraCode  = currentProcess.processCode[1] - 48;
        int processCode = currentProcess.processCode[2] - 48;
        switch(destCode)
                {case 0: /* (signInPage->*signInDirectives[extraCode][processCode])( /// ); */ break;
                 case 1: /* (signUpPage->*signUpPageDirectives[extraCode][processCode])( /// ); */ break;
                 case 2: /* (signUpForm->*signUpFormDirectives[extraCode][processCode])( /// ); */ break;
                 case 3: /* (mainPage->*mainDirectives[extraCode][processCode])( /// ); */ break;
                 case 4: /* (listTab->*listTabDirectives[extraCode][processCode])( /// ); */ break;
                 case 5: /* (objectPage->*objectDirectives[extraCode][processCode])( /// ); */ break;
                 case 6: /* (signInPage->*signInDirectives[extraCode][processCode])( /// ); */ break;
                 case 7: /* (signInPage->*signInDirectives[extraCode][processCode])( /// ); */ break;
                    // code 8 : MQTT Directives
                 case 8: (mqtt->*mqttDirectives[extraCode][processCode])(currentProcess.processParam); break;
                    // code 9 : Manager Directives
                 case 9: (this->*managerDirectives[extraCode][processCode])(std::stoi(currentProcess.processParam.at(0))); break;}}
     queueFlag = false;
     emit pQueueEmpty();}

void manager::setAppID(int aID)
    {appID = aID;}

void manager::authValidated(int cID)
    {clientID = cID;
     emit signInSuccess();}

void manager::authFailed(int empty)
    {emit signInFail("Invalid credentials");}
