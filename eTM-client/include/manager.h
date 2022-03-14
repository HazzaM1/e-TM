#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QWidget>

#include <QThread>
#include <QQueue>


//#include <process.h>

class manager : public QObject
{
    Q_OBJECT

    public:
        manager(QWidget *widget, QQueue<Process> *pQueue, bool *flag);

    private:
        QWidget *parent;
        bool *queueFlag;
        QQueue<Process> *processQueue;

    signals:
        void pQueueEmpty();

    public slots:
        void treatProcess();

};

#endif // MANAGER_H
