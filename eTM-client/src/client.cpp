#include "client.h"

client::client(QSize size)
{
    width = size.width();
    height = size.height();

    processManager->moveToThread(&processorThread);
    queueFlag = false;

//    initGUI();
    connect(welcome->signIn, &signInPage::signInAttempt, this, &client::queueProcess);
    connect(this, &client::pQueuePending, processManager, &manager::treatProcess);
    this->show();
}

void client::queueProcess(Process process)
    {processQueue.enqueue(process);
     if (!queueFlag)
        {queueFlag = true;
         processorThread.start();
         emit pQueuePending();}}

//void client::initGUI()
//    {this->setWindowFlags(Qt::FramelessWindowHint);
//     this->setAttribute(Qt::WA_TranslucentBackground);
//     this->setGeometry(0, 0, width, height-1);}
