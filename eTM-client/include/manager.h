#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QWidget>

#include <QThread>
#include <QQueue>

#include <vector>

#include <sockettest.h>

//#include <process.h>

class manager : public QObject
{
    Q_OBJECT

    public:
        manager(QObject *object, QQueue<Process> *pQueue);
        bool getQueueFlag();
        SocketTest *socket = new SocketTest;

    private:
            template <class T>
            using Directive = bool(T::*)(QString);
        std::vector<Directive<SocketTest>> socketDirectives;

        QObject *parent;
        QQueue<Process> *processQueue;
        bool queueFlag;

    signals:
        void pQueueEmpty();

    public slots:
        void treatProcess();

};
#endif // MANAGER_H
