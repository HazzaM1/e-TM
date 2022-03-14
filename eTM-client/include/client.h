#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>

#include <process.h>
#include <welcomePage.h>
#include <manager.h>

class client : public QWidget
{
    Q_OBJECT

    public:
        client(QSize size);

    private:
        int width;
        int height;
        bool queueFlag;
        QQueue<Process> processQueue;
        QThread processorThread;

        manager *processManager = new manager(this, &processQueue, &queueFlag);
        welcomePage *welcome = new welcomePage(this);
        void initGUI();

    signals:
        void pQueuePending();

    public slots:
        void queueProcess(Process process);
};

#endif // CLIENT_H
