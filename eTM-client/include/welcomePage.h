#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

#include <signInPage.h>
#include <signUpPage.h>
#include <navigationtab.h>

#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>

class welcomePage : public QWidget
{
    Q_OBJECT

    private:
        const int wWidth = 300;
        const int wHeight = 400;
        int rWidth;
        int rHeight;
        QLabel *div = new QLabel(this);
        QLabel *logo_label = new QLabel(this);

    public:
        welcomePage(int w, int h);
        signInPage *signIn = new signInPage(this, QSize(wWidth, wHeight));
        signUpPage *signUp = new signUpPage(this, QSize(wWidth, wHeight));
        navigationTab *navTab;
        bool switchFlag = false;

    public slots:
        void switchTab();
        void signInFailed();
        void signInSuccess();
};

#endif // WELCOMEPAGE_H

