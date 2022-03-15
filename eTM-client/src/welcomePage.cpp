#include "welcomePage.h"

welcomePage::welcomePage(QObject *object)
    {/*this->setParent(object);*/
     this->setFixedWidth(500);
     this->setFixedHeight(500);

     connect(signIn->switchButton, &QPushButton::clicked, this, &welcomePage::switchTab);
     connect(signUp->switchButton, &QPushButton::clicked, this, &welcomePage::switchTab);
     switchTab();

     this->setStyleSheet("welcomePage {background-color: qlineargradient(x1:0,y1:0, x2:0.8,y2:1, stop:0 rgba(0,101,18,1), stop:1 rgba(19,174,0,1));}");
     this->show();}

void welcomePage::switchTab()
    {signIn->setVisible(!switchFlag);
     signUp->setVisible(switchFlag);
     switchFlag = !switchFlag;}
