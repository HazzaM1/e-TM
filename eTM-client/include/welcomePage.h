#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

#include "signInPage.h"
#include "signUpPage.h"

class welcomePage : public QWidget
{
    Q_OBJECT

    public:
        welcomePage(QWidget *widget);
        void passProcess();

        signInPage *signIn = new signInPage(this);
        signUpPage *signUp = new signUpPage(this);
        bool switchFlag = false;

    public slots:
        void switchTab();
};

#endif // WELCOMEPAGE_H

