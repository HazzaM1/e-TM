#include "server.h"

server::server()
    {processManager = new manager(&processQueue);
     processManager->moveToThread(&processorThread);
     processManager->mqtt->moveToThread(&processorThread);
     processorThread.start();
     processManager->DB->moveToThread(&DBThread);
     DBThread.start();
     qRegisterMetaType<Process>("Process");
     // CONNECTIONS
     connect(&processorThread, &QThread::started, processManager->mqtt, &mqttServer::init);
     connect(processManager->mqtt, &mqttServer::incomingProcess, this, &server::queueProcess);
     connect(this, &server::pQueuePending, processManager, &manager::treatProcess);
     connect(processManager->DB, &DBmanager::authReply, this, &server::queueProcess);
    }

void server::queueProcess(Process process)
  {processQueue.enqueue(process);
    if (!processManager->queueFlag)
      {emit pQueuePending();}}

