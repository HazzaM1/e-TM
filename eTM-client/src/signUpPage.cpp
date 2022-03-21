#include "signUpPage.h"

signUpPage::signUpPage(QWidget *widget, QSize size)
    {layout->setAlignment(Qt::AlignHCenter);
     layout->addWidget(driverButton);
     layout->addWidget(companyButton);
     layout->addWidget(cargoOwnerButton);
     layout->addWidget(switchButton);
     driverButton->setFixedSize(size.width()/2, size.height()/10);
     cargoOwnerButton->setFixedSize(size.width()/2, size.height()/10);
     companyButton->setFixedSize(size.width()/2, size.height()/10);
     switchButton->setFixedSize(size.width()/2, size.height()/10);
     this->setParent(widget);
     this->setLayout(layout);
     this->adjustSize();
     this->move(size.width()/2-this->width()/2, size.height()/2-this->height()/4);
     connect(driverButton, &QPushButton::clicked, [this](int){emit formSelected(0);});
     connect(companyButton, &QPushButton::clicked, [this](int){emit formSelected(1);});
     connect(cargoOwnerButton, &QPushButton::clicked, [this](int){emit formSelected(3);});}
