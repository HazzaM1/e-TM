#include "signUpPage.h"

signUpPage::signUpPage(QWidget *widget)
    {this->setParent(widget);
     this->setLayout(layout);
     layout->setAlignment(Qt::AlignHCenter);
     layout->addWidget(driverButton);
     layout->addWidget(cargoOwnerButton);
     layout->addWidget(companyButton);
     layout->addWidget(switchButton);
     this->adjustSize();
     this->move(this->parentWidget()->width()/2-this->width(), this->parentWidget()->height()/2-this->height()/2);}
