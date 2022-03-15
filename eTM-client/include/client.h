#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>

#include <process.h>
#include <welcomePage.h>
#include <manager.h>
#include <sockettest.h>


class client : public QObject
{
    Q_OBJECT

    public:
        client(QSize size);

    private:
        int width;
        int height;
        QQueue<Process> processQueue;
        QThread processorThread;

        manager *processManager = new manager(this, &processQueue);
        welcomePage *welcome = new welcomePage(this);

        void initGUI();

    signals:
        void pQueuePending();

    public slots:
        void queueProcess(Process process);
};

#endif // CLIENT_H
