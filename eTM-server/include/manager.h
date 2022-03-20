#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QWidget>
#include <QQueue>
#include <vector>

#include <mqttServer.h>
#include <dbmanager.h>

//#include <process.h>

class manager : public QObject
{
    Q_OBJECT

    private:
            template <class T>
            using stringDirective = bool(T::*)(QString, std::vector<std::string>);
            template <class T>
            using intDirective = void(T::*)(int, std::vector<std::string>);
        std::vector<std::vector<stringDirective<mqttServer>>> mqttDirectives;
        std::vector<std::vector<intDirective<DBmanager>>> dbDirectives;

        std::vector<clientDetails> *clients = new std::vector<clientDetails>;
        QQueue<Process> *processQueue;

    public:
        manager(QQueue<Process> *pQueue);

        bool queueFlag = false;

        mqttServer *mqtt = new mqttServer(clients);
        DBmanager *DB = new DBmanager(clients);

    signals:
        void pQueueEmpty();

    public slots:
        void treatProcess();

};
#endif // MANAGER_H
