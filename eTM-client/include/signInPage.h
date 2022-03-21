#ifndef SIGNINPAGE_H
#define SIGNINPAGE_H

#include <QObject>
#include <QWidget>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QRegularExpression>


class signInPage : public QWidget
{
    Q_OBJECT

    public:
        signInPage(QWidget *widget, QSize size);
        QVBoxLayout *layout = new QVBoxLayout;
        QLineEdit *emailTextBox = new QLineEdit();
        QLineEdit *passwordTextBox = new QLineEdit();
        QPushButton *submitButton = new QPushButton("Sign In");
        QPushButton *switchButton = new QPushButton("Sign Up");

    private:
        int wWidth;
        int wHeight;

        QRegularExpression *emailRegex = new QRegularExpression("([a-zA-Z0-9.-]){1,}@(([a-zA-Z0-9])*\\.){1,}([a-z]){1,}");

        void initGUI();

    private slots:
        void submitSignIn();

    signals:
        void errorMessage(QString error);
        void signInAttempt(Process process);

};

#endif // SIGNINPAGE_H
