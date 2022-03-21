#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QWidget>
#include <QQueue>
#include <vector>

#include <mqttClient.h>
#include <welcomePage.h>

//#include <process.h>

class manager : public QObject
{
    Q_OBJECT

private:
        int width;
        int height;

        int appID = 0;
        int clientID = 0;
        QString QappID = QString::fromStdString(std::to_string(appID));

        template <class T>
            using vectorDirective = bool(T::*)(std::vector<std::string>);
        template <class T>
            using stringDirective = bool(T::*)(std::string);
        template <class T>
            using intDirective = void(T::*)(int);
        std::vector<std::vector<vectorDirective<mqttClient>>> mqttDirectives;
        std::vector<std::vector<intDirective<manager>>> managerDirectives;

        QQueue<Process> *processQueue;

    public:
        manager(int w, int h, QQueue<Process> *pQueue);

        bool queueFlag = false;

        // ---------
        mqttClient *mqtt = new mqttClient(&appID, &clientID);
        welcomePage *welcome;

        // ---------

    signals:
        void pQueueEmpty();
        void signInFail(QString error);
        void signInSuccess();

    public slots:
        void treatProcess();
        void setAppID(int aID);
        void authValidated(int cID);
        void authFailed(int empty);

};
#endif // MANAGER_H
