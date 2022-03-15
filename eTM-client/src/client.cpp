#include "client.h"

client::client(QSize size)
    {width = size.width();
    height = size.height();
    // THREAD MANAGEMENT
    processManager->moveToThread(&processorThread);
    processManager->socket->moveToThread(&processorThread);
    // GUI MANAGEMENT
//    initGUI();
    //  CONNECTION MANAGEMENT
        //  PROCESS MANAGEMENT
        connect(welcome->signIn, &signInPage::signInAttempt, this, &client::queueProcess);
        connect(this, &client::pQueuePending, processManager, &manager::treatProcess);
}

void client::queueProcess(Process process)
    {processQueue.enqueue(process);
     if (!processManager->getQueueFlag())
        {processorThread.start();
         emit pQueuePending();}}

//void client::initGUI()
//    {this->setWindowFlags(Qt::FramelessWindowHint);
//     this->setAttribute(Qt::WA_TranslucentBackground);
//     this->setGeometry(0, 0, width, height-1);}
