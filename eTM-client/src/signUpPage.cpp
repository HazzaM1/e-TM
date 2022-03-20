#include "signUpPage.h"

signUpPage::signUpPage(QWidget *widget, QSize size)
    {layout->setAlignment(Qt::AlignHCenter);
     layout->addWidget(driverButton);
     layout->addWidget(cargoOwnerButton);
     layout->addWidget(companyButton);
     layout->addWidget(switchButton);
     driverButton->setFixedSize(size.width()/2, size.height()/10);
     cargoOwnerButton->setFixedSize(size.width()/2, size.height()/10);
     companyButton->setFixedSize(size.width()/2, size.height()/10);
     switchButton->setFixedSize(size.width()/2, size.height()/10);
     this->setParent(widget);
     this->setLayout(layout);
     this->adjustSize();
     this->move(size.width()/2-this->width()/2, size.height()/2-this->height()/4);}
