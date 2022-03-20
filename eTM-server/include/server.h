#ifndef SERVER_H
#define SERVER_H

#include <QThread>

#include <QObject>

#include <manager.h>
#include <dbmanager.h>

class server : public QObject
{   Q_OBJECT

    public:
        server();

    private:
        QThread processorThread;
        QThread DBThread;
        manager *processManager;

        QQueue<Process> processQueue;

    signals:
        void pQueuePending();

    public slots:
        void queueProcess(Process process);

};

#endif // SERVER_H
