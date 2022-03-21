#include <signupform.h>

signUpForm::signUpForm(QWidget *widget, int formID, int w, int h)
    {wWidth = w;
     wHeight = h;
     this->setParent(widget);
     this->setGeometry(w/20,h*3/20,w*23/40,h*19/20);
     for (const field &currentField : formDetails[formID])
        {switch(currentField.type)
            {case string:
                {QLineEdit *aLineEdit = new QLineEdit;
                 aLineEdit->setFixedSize(wWidth*23/40,wHeight/20);
                 aLineEdit->setAlignment(Qt::AlignHCenter);
                 aLineEdit->setPlaceholderText(QString::fromStdString("Enter your " + currentField.name));
                 aLineEdit->setStyleSheet("QLineEdit { border-radius: 7px; background-color : white;}");
                 layout->addWidget(aLineEdit);
                 layout->addSpacing(20);
                 break;}
             case email:
                 {QLineEdit *aLineEdit = new QLineEdit;
                  aLineEdit->setFixedSize(wWidth*23/40,wHeight/20);
                  aLineEdit->setAlignment(Qt::AlignHCenter);
                  aLineEdit->setPlaceholderText(QString::fromStdString("Enter your " + currentField.name));
                  aLineEdit->setStyleSheet("QLineEdit { border-radius: 7px; background-color : white;}");
                  layout->addWidget(aLineEdit);
                  layout->addSpacing(20);
                  break;}
             case password:
                 {QLineEdit *aLineEdit = new QLineEdit;
                  aLineEdit->setFixedSize(wWidth*23/40,wHeight/20);
                  aLineEdit->setAlignment(Qt::AlignHCenter);
                  aLineEdit->setPlaceholderText(QString::fromStdString("Enter your " + currentField.name));
                  aLineEdit->setStyleSheet("QLineEdit { border-radius: 7px; background-color : white;}");
                  layout->addWidget(aLineEdit);
                  layout->addSpacing(20);
                  break;}
             case date:
                 {QLineEdit *aLineEdit = new QLineEdit;
                  aLineEdit->setFixedSize(wWidth*23/40,wHeight/20);
                  aLineEdit->setAlignment(Qt::AlignHCenter);
                  aLineEdit->setPlaceholderText(QString::fromStdString("Enter your " + currentField.name));
                  aLineEdit->setStyleSheet("QLineEdit { border-radius: 7px; background-color : white;}");
                  layout->addWidget(aLineEdit);
                  layout->addSpacing(20);
                  break;}
             case confirm:
                 {QLineEdit *aLineEdit = new QLineEdit;
                  aLineEdit->setFixedSize(wWidth*23/40,wHeight/20);
                  aLineEdit->setAlignment(Qt::AlignHCenter);
                  aLineEdit->setPlaceholderText(QString::fromStdString("Confirm your " + currentField.name));
                  aLineEdit->setStyleSheet("QLineEdit { border-radius: 7px; background-color : white;}");
                  layout->addWidget(aLineEdit);
                  layout->addSpacing(20);
                  break;}
             case checkbox: break;
        }}
      layout->setContentsMargins(0,0,0,0);
      groupBox->setStyleSheet("border: 0px solid black;");
      groupBox->setLayout(layout);
      scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      scrollArea->resize(w*23/40,h/2);
      scrollArea->setStyleSheet("background-color: transparent; border-width: 10px;");
      scrollArea->setFrameShape(QFrame::NoFrame);
//      scrollArea->setFocusProxy(this);
      scrollArea->setWidget(groupBox);
    this->show();
    }
