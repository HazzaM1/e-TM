#include "manager.h"
#include <QDebug> //

manager::manager(QObject *object, QQueue<Process> *pQueue)
    {parent = object;
     processQueue = pQueue;
     queueFlag = false;
     socket->Connect();
     socketDirectives = {&SocketTest::sendRequest};}

void manager::treatProcess()
    {queueFlag = true;
    while(!processQueue->isEmpty())
        {Process currentProcess = processQueue->dequeue();
        if (currentProcess.processCode[0] == '1')
            {(*socket.*socketDirectives[0])(QString::fromStdString(currentProcess.processParam));}

//        for (const directive &Directive : Directives)
//            {
//                qDebug() << currentProcess.processCode << " : " << Directive.code;
//                if (currentProcess.processCode == Directive.code) Directive.directive(QString::fromStdString(currentProcess.processParam));
//            }
//                 TEST CODE
//                  QString text = QString::fromStdString(std::string(currentProcess.processCode) + " : " + currentProcess.processParam);
//                  this->thread()->sleep(2);
//                  qDebug() <<  text;
        }
     queueFlag = false;
     emit pQueueEmpty();
    }


bool manager::getQueueFlag()
    {return queueFlag;}
