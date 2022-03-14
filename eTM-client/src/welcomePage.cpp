#include "welcomePage.h"

welcomePage::welcomePage(QWidget *widget)
    {this->setParent(widget);
     this->setFixedWidth(500);
     this->setFixedHeight(500);

     connect(signIn->switchButton, &QPushButton::clicked, this, &welcomePage::switchTab);
     connect(signUp->switchButton, &QPushButton::clicked, this, &welcomePage::switchTab);
     switchTab();
     this->show();}

void welcomePage::switchTab()
    {signIn->setVisible(!switchFlag);
     signUp->setVisible(switchFlag);
     switchFlag = !switchFlag;}
