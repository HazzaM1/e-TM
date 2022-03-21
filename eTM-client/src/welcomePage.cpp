#include "welcomePage.h"

welcomePage::welcomePage(int w, int h)
    {rWidth = w;
     rHeight = h;
     div->setStyleSheet("background-color: qlineargradient(x1:0.5,y1:0, x2:0.5,y2:1, stop:0 white, stop:0.92 white, stop:0.93 rgba(50,50,50,1), stop:1 rgba(50,50,50,0));");
     div->setGeometry(0,0,wWidth,wHeight*0.3);
     logo_label->setPixmap(QPixmap("../res/img/eTM-icon_1.jpg"));
     logo_label->setScaledContents(true);
     logo_label->setGeometry((wWidth-wWidth*0.46)/2,(wHeight*0.3-wHeight*0.2)/2, wWidth*0.46, wHeight*0.2);
     connect(signIn->switchButton, &QPushButton::clicked, this, &welcomePage::switchTab);
     connect(signUp->switchButton, &QPushButton::clicked, this, &welcomePage::switchTab);
     connect(signIn, &signInPage::errorMessage, this, &welcomePage::errorMessage);
     switchTab();
     this->setGeometry((w-wWidth)/2,(h-wHeight)/2, wWidth, wHeight);
     this->setStyleSheet("welcomePage {background-color: qlineargradient(x1:0,y1:0.2, x2:0.8,y2:1, stop:0 rgba(0,101,18,1), stop:1 rgba(118,212,44,1) );}");
     this->setFocusPolicy(Qt::ClickFocus);
     this->show();}

void welcomePage::switchTab()
    {signIn->setVisible(!switchFlag);
     signUp->setVisible(switchFlag);
     switchFlag = !switchFlag;}

void welcomePage::errorMessage(QString error)
    {qDebug() << error;
     QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect();
     QLabel *authLabel = new QLabel(this);
     authLabel->setText(error);
     authLabel->setAlignment(Qt::AlignCenter);
     authLabel->setStyleSheet("background-color : rgba(255,0,0,0.3); color : rgba(150,0,0,1); font-weight: bold; border: 2px solid rgba(150,0,0,0.6); border-radius: 7px;");
     authLabel->setGraphicsEffect(opacityEffect);
     authLabel->setGeometry(wWidth/6, wHeight*17.5/25, wWidth*4/6, wHeight/15);
     opacityEffect->setOpacity(0);
     authLabel->show();
     QPropertyAnimation *animy = new QPropertyAnimation(opacityEffect, "opacity");
     animy->setDuration(1500);
     animy->setKeyValueAt(0, 0);
     animy->setKeyValueAt(.2, 1);
     animy->setKeyValueAt(.8, 1);
     animy->setKeyValueAt(1, 0);
     animy->start();
     connect(animy, &QParallelAnimationGroup::finished, authLabel, &QLabel::deleteLater);}

void welcomePage::signInSuccess()
    {qDebug() << "Authentication Success!";
     QGraphicsOpacityEffect *opac_authL = new QGraphicsOpacityEffect();
      opac_authL->setOpacity(1);
     QGraphicsOpacityEffect *opac_email = new QGraphicsOpacityEffect();
      opac_email->setOpacity(1);
     QGraphicsOpacityEffect *opac_passd = new QGraphicsOpacityEffect();
      opac_passd->setOpacity(1);
     QGraphicsOpacityEffect *opac_signin = new QGraphicsOpacityEffect();
      opac_signin->setOpacity(1);
     QGraphicsOpacityEffect *opac_signup = new QGraphicsOpacityEffect();
      opac_signup->setOpacity(1);
     signIn->emailTextBox->setGraphicsEffect(opac_email);
     signIn->passwordTextBox->setGraphicsEffect(opac_passd);
     signIn->submitButton->setGraphicsEffect(opac_signin);
     signIn->switchButton->setGraphicsEffect(opac_signup);
     QLabel *authLabel = new QLabel(this);
     authLabel->setText("Authentication success");
     authLabel->setAlignment(Qt::AlignCenter);
     authLabel->setStyleSheet("background-color : rgba(0,145,25,0.3); color: rgba(0,102,17,1); font-weight: bold; border: 2px solid rgba(0,102,17,0.6); border-radius: 7px;");
     authLabel->setGraphicsEffect(opac_authL);
     authLabel->setGeometry(wWidth/6, wHeight*17.5/25, wWidth*4/6, wHeight/15);
     authLabel->show();
         QPropertyAnimation *animy = new QPropertyAnimation(opac_authL, "opacity");
         animy->setDuration(2000);
         animy->setKeyValueAt(0, 0);
         animy->setKeyValueAt(.05, 1);
         animy->setKeyValueAt(.95, 1);
         animy->setKeyValueAt(1, 0);
         animy->setEasingCurve(QEasingCurve::InOutCubic);
         QPropertyAnimation *animf = new QPropertyAnimation(opac_email, "opacity");
         animf->setDuration(150);
         animf->setEndValue(0);
         QPropertyAnimation *animg = new QPropertyAnimation(opac_passd, "opacity");
         animg->setDuration(150);
         animg->setEndValue(0);
         QPropertyAnimation *animh = new QPropertyAnimation(opac_signin, "opacity");
         animh->setDuration(150);
         animh->setEndValue(0);
         QPropertyAnimation *animi = new QPropertyAnimation(opac_signup, "opacity");
         animi->setDuration(150);
         animi->setEndValue(0);
         QPropertyAnimation *anima = new QPropertyAnimation(div, "geometry");
         anima->setDuration(300);
         anima->setEndValue(QRect(div->pos().x(), div->pos().y(), wWidth, wHeight+100));
         anima->setEasingCurve(QEasingCurve::InQuart);
         QPropertyAnimation *animb = new QPropertyAnimation(logo_label, "geometry");
         animb->setDuration(1500);
         animb->setKeyValueAt(0, QRect(logo_label->pos().x(), logo_label->pos().y(), logo_label->width(), logo_label->height()));
         animb->setKeyValueAt(0.3, QRect(logo_label->pos().x()-50, logo_label->pos().y(), logo_label->width(), logo_label->height()));
         animb->setKeyValueAt(0.7, QRect(logo_label->pos().x()-50, logo_label->pos().y(), logo_label->width(), logo_label->height()));
         animb->setKeyValueAt(1, QRect(logo_label->pos().x()+300, logo_label->pos().y(), logo_label->width(), logo_label->height()));
         QPropertyAnimation *animk = new QPropertyAnimation(this, "geometry");
         animk->setDuration(500);
         animk->setEndValue(QRect(15,50, rWidth-30, rHeight-100));
         animk->setEasingCurve(QEasingCurve::InQuart);
     QSequentialAnimationGroup *anime = new QSequentialAnimationGroup();
     anime->addAnimation(animy);
     anime->addAnimation(animf);
     anime->addAnimation(animg);
     anime->addAnimation(animh);
     anime->addAnimation(animi);
     anime->addPause(500);
     anime->addAnimation(animb);
     anime->addAnimation(anima);
     anime->addAnimation(animk);
     anime->start();
     connect(anima, &QSequentialAnimationGroup::finished, authLabel, &QLabel::deleteLater);
     connect(anima, &QSequentialAnimationGroup::finished, logo_label, &QLabel::deleteLater);
     connect(anima, &QSequentialAnimationGroup::finished, div, &QWidget::deleteLater);
     connect(anima, &QSequentialAnimationGroup::finished, signIn, &QLabel::deleteLater);
     connect(anima, &QSequentialAnimationGroup::finished, signUp, &QLabel::deleteLater);
     connect(anima, &QSequentialAnimationGroup::finished, [this](){this->setStyleSheet("background-color: white;");});
     connect(anime, &QSequentialAnimationGroup::finished, [this](){this->setWindowState(Qt::WindowMaximized);});}

void welcomePage::signingUp(int formID)
    {QGraphicsOpacityEffect *opac_driver = new QGraphicsOpacityEffect();
      opac_driver->setOpacity(1);
     QGraphicsOpacityEffect *opac_company = new QGraphicsOpacityEffect();
      opac_company->setOpacity(1);
     QGraphicsOpacityEffect *opac_cargoOwner = new QGraphicsOpacityEffect();
      opac_cargoOwner->setOpacity(1);
     QGraphicsOpacityEffect *opac_signin = new QGraphicsOpacityEffect();
      opac_signin->setOpacity(1);
     signUp->driverButton->setGraphicsEffect(opac_driver);
     signUp->companyButton->setGraphicsEffect(opac_company);
     signUp->cargoOwnerButton->setGraphicsEffect(opac_cargoOwner);
     signUp->switchButton->setGraphicsEffect(opac_signin);
         QPropertyAnimation *animf = new QPropertyAnimation(opac_driver, "opacity");
         animf->setDuration(150);
         animf->setEndValue(0);
         QPropertyAnimation *animg = new QPropertyAnimation(opac_company, "opacity");
         animg->setDuration(150);
         animg->setEndValue(0);
         QPropertyAnimation *animh = new QPropertyAnimation(opac_cargoOwner, "opacity");
         animh->setDuration(150);
         animh->setEndValue(0);
         QPropertyAnimation *animi = new QPropertyAnimation(opac_signin, "opacity");
         animi->setDuration(150);
         animi->setEndValue(0);
             QPropertyAnimation *animb = new QPropertyAnimation(logo_label, "geometry");
             animb->setDuration(1000);
             animb->setEndValue(QRect(logo_label->pos().x()+wWidth/4, logo_label->pos().y(), logo_label->width(), logo_label->height()));
             animb->setEasingCurve(QEasingCurve::InOutQuart);
             QPropertyAnimation *animk = new QPropertyAnimation(this, "geometry");
             animk->setDuration(1000);
             animk->setEndValue(QRect((rWidth-wWidth*1.5)/2,(rHeight-wHeight*1.5)/2, wWidth*1.5, wHeight*1.5));
             animk->setEasingCurve(QEasingCurve::InOutQuart);
             QPropertyAnimation *anima = new QPropertyAnimation(div, "geometry");
             anima->setDuration(1000);
             anima->setEndValue(QRect(0,0,wWidth*1.5,div->height()));
             anima->setEasingCurve(QEasingCurve::InOutQuart);
         QParallelAnimationGroup *animc = new QParallelAnimationGroup();
         animc->addAnimation(anima);
         animc->addAnimation(animk);
         animc->addAnimation(animb);
     QSequentialAnimationGroup *anime = new QSequentialAnimationGroup();
     anime->addAnimation(animf);
     anime->addAnimation(animg);
     anime->addAnimation(animh);
     anime->addAnimation(animi);
     anime->addPause(500);
     anime->addAnimation(animc);
     anime->start();
     connect(anime, &QSequentialAnimationGroup::finished,[this](){signupform = new signUpForm(this, 0, this->width()*1.5, this->height()*1.5);});}
