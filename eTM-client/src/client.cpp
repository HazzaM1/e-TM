#include "client.h"

client::client(int w, int h)
    {width = w;
     height = h;
     processManager = new manager(w, h, &processQueue);
     processManager->moveToThread(&processorThread);
     processManager->mqtt->moveToThread(&processorThread);
     processorThread.start();
     // CONNECTIONS
     connect(&processorThread, &QThread::started, processManager->mqtt, &mqttClient::init);
     connect(processManager->welcome->signIn, &signInPage::signInAttempt, this, &client::queueProcess);
     connect(processManager->mqtt, &mqttClient::incomingProcess, this, &client::queueProcess);
     connect(this, &client::pQueuePending, processManager, &manager::treatProcess);
     connect(processManager, &manager::signInFail, processManager->welcome, &welcomePage::signInFailed);
     connect(processManager, &manager::signInSuccess, processManager->welcome, &welcomePage::signInSuccess);}

void client::queueProcess(Process process)
  {processQueue.enqueue(process);
   if (!processManager->queueFlag)
      emit pQueuePending();}

