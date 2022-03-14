#ifndef SIGNINPAGE_H
#define SIGNINPAGE_H

#include <QObject>
#include <QWidget>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QRegularExpression>


class signInPage : public QWidget
{
    Q_OBJECT

    public:
        signInPage(QWidget *widget);
        QPushButton *switchButton = new QPushButton("Sign Up");

    private:
        QWidget *Parent;
        QVBoxLayout *layout = new QVBoxLayout;
        QLineEdit *emailTextBox = new QLineEdit();
        QLineEdit *passwordTextBox = new QLineEdit();
        QLabel *emailLabel = new QLabel("Email");
        QLabel *passwordLabel = new QLabel("Password");
        QPushButton *submitButton = new QPushButton("Submit");

        QRegularExpression *emailRegex = new QRegularExpression("([a-zA-Z0-9.-])*@(([a-zA-Z0-9])*\\.){1,}([a-z]){1,}");

        void initGUI();
        bool validateData();

    private slots:
        void submitSignIn();

    signals:
        void signInAttempt(Process process);

};

#endif // SIGNINPAGE_H
