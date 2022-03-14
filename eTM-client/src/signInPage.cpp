#include "signInPage.h"

signInPage::signInPage(QWidget *widget)
    {Parent = widget;
    initGUI();
    connect(submitButton, &QPushButton::clicked , this, &signInPage::submitSignIn);}

void signInPage::initGUI()
    {this->setParent(Parent);
     this->setLayout(layout);
     passwordTextBox->setEchoMode(QLineEdit::Password);
     layout->addWidget(emailLabel);
     layout->addWidget(emailTextBox);
     layout->addWidget(passwordLabel);
     layout->addWidget(passwordTextBox);
     layout->addWidget(submitButton);
     layout->addWidget(switchButton);
     this->adjustSize();
     this->move(Parent->width()/2-this->width(), Parent->height()/2-this->height()/2);}

void signInPage::submitSignIn()
    {if (emailRegex->match(emailTextBox->text()).hasMatch()) emit signInAttempt({{'1','1','1'},emailTextBox->text().toStdString()+","+passwordTextBox->text().toStdString()});
    else qDebug() << "Email no good!";}

bool signInPage::validateData()
    {return emailRegex->match(emailTextBox->text()).isValid();}
