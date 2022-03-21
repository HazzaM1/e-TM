#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QObject>
#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QRegularExpression>
#include <vector>

enum type{string, email, confirm, checkbox, date, password};

struct field
    {std::string name;
     std::string ID;
     type type;};

class signUpForm : public QWidget
{
    Q_OBJECT

    private:
        const std::vector<field> driverFormDetails =
          {{"first name", "name1", string},
           {"last name", "name2", string},
           {"date of birth", "birthDate", date},
           {"country of birth", "birthCountry", string},
           {"phone number", "phone", string},
           {"address", "address", string},
           {"driving license number", "drivingLicenseNumber", string},
           {"DQC date of issue", "dqcIssueDate", date},
           {"DQC date of expiration", "dqcExpiryDate", date},
           {"DQC issuing authority", "issuingAuthority", string},
           {"DQC issue number", "issueNumber", string},
           {"employment status", "companyDriver", checkbox},
           {"employer's company name", "companyRelated", checkbox},
           {"email address", "email", email},
           {"email address", "emailConfirm", confirm},
           {"password", "password", password},
           {"password", "passwordConfirm", confirm}};
        const std::vector<field> companyFormDetails =
          {{"company name", "name", string},
           {"company phone number", "phone", string},
           {"company address", "address", string},
           {"company registration number", "companyNumber", string},
           {"company status", "status", date},
           {"company type", "type", date},
           {"company incorporation date", "incorporatedOn", string},
           {"company nature of business", "natureOfBusiness", string},
           {"email address", "email", email},
           {"email address", "emailConfirm", confirm},
           {"password", "password", password},
           {"password", "passwordConfirm", confirm}};
        const std::vector<field> cargoOwnerFormDetails =
          {{"company name", "name", string},
           {"phone number", "phone", string},
           {"address", "address", string},
           {"email address", "email", email},
           {"email address", "emailConfirm", confirm},
           {"password", "password", password},
           {"password", "passwordConfirm", confirm}};
        const std::vector<std::vector<field>> formDetails = {driverFormDetails, companyFormDetails, cargoOwnerFormDetails};
        const std::vector<QObject> fieldList;
        int wWidth;
        int wHeight;

    public:
        signUpForm(QWidget *widget, int formID, int w, int h);
        QScrollArea *scrollArea = new QScrollArea(this);
        QVBoxLayout *layout = new QVBoxLayout();
        QGroupBox *groupBox = new QGroupBox();

};

#endif // SIGNUPFORM_H
