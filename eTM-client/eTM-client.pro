QT += \
    network \
    widgets \
    mqtt

HEADERS += \
    include/mqttClient.h \
    include/signInPage.h \
    include/signUpPage.h \
    include/welcomePage.h \
    include/process.h \
    include/manager.h \
    include/client.h \
    include/navigationtab.h \
    include/listtab.h \
    include/signupform.h

SOURCES += \
    src/signupform.cpp \
    src/listtab.cpp \
    src/navigationtab.cpp \
    src/client.cpp \
    src/manager.cpp \
    src/mqttClient.cpp \
    src/signInPage.cpp \
    src/main.cpp \
    src/signUpPage.cpp \
    src/welcomePage.cpp

INCLUDEPATH += \
    headers/ include \

OBJECTS_DIR = $$_PRO_FILE_PWD_/bin/
DESTDIR = $$_PRO_FILE_PWD_/bin/
