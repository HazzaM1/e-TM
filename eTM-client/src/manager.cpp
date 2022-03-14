#include "manager.h"
#include <QDebug>

manager::manager(QWidget *widget, QQueue<Process> *pQueue, bool *flag)
    {parent = widget;
    processQueue = pQueue;
    queueFlag = flag;}

void manager::treatProcess()
    {while(!processQueue->isEmpty())
        {Process currentProcess = processQueue->dequeue();

//                 TEST CODE
                  QString text = QString::fromStdString(std::string(currentProcess.processCode) + " : " + currentProcess.processParam);
                  this->thread()->sleep(2);
                  qDebug() <<  text;
        }
     *queueFlag = false;
     emit pQueueEmpty();}
