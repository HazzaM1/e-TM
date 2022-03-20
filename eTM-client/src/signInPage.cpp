#include "signInPage.h"

signInPage::signInPage(QWidget *widget, QSize size)
    {wWidth = size.width();
     wHeight = size.height();
     this->setParent(widget);
     initGUI();
     connect(submitButton, &QPushButton::clicked , this, &signInPage::submitSignIn);}

void signInPage::initGUI()
    {layout->addSpacing(20);
     layout->addWidget(emailTextBox);
     layout->addSpacing(10);
     layout->addWidget(passwordTextBox);
     layout->addSpacing(5);
     layout->addWidget(submitButton, 100, Qt::AlignHCenter);
     layout->addSpacing(70);
     layout->addWidget(switchButton, 100, Qt::AlignHCenter);
     layout->setContentsMargins(0,0,0,0);
     layout->setAlignment(Qt::AlignHCenter);
     emailTextBox->setFixedSize(wWidth/1.5,wHeight/10);
     emailTextBox->setAlignment(Qt::AlignHCenter);
     emailTextBox->setPlaceholderText("Enter your email");
     passwordTextBox->setFixedSize(wWidth/1.5,wHeight/10);
     passwordTextBox->setAlignment(Qt::AlignHCenter);
     passwordTextBox->setPlaceholderText("Enter your password");
     passwordTextBox->setEchoMode(QLineEdit::Password);
     submitButton->setFixedSize(wWidth/2.5,wHeight/13);
     submitButton->setStyleSheet("font-weight: bold;");
     switchButton->setFixedSize(wWidth/2.5,wHeight/13);
     switchButton->setStyleSheet("font-weight: bold;");
     this->setLayout(layout);
     this->setFocus();
     this->setStyleSheet("QLineEdit { border-radius: 7px; }");
     this->adjustSize();
     this->setGeometry(wWidth/2-this->width()/2, wHeight/2-this->height()/3, this->width(), this->height());}

void signInPage::submitSignIn()
    {Process process = {{'8','0','0'}, {"000", emailTextBox->text().toStdString(), passwordTextBox->text().toStdString()}};
    if (emailRegex->match(emailTextBox->text()).hasMatch())
        emit signInAttempt(process);
    else qDebug() << "Email no good!";}
