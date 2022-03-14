QT += \
    network \
    widgets

HEADERS += \
    include/client.h \
    include/signInPage.h \
    include/signUpPage.h \
    include/sockettest.h \
    include/welcomePage.h \
    include/process.h \
    include/manager.h

SOURCES += \
    src/client.cpp \
    src/manager.cpp \
    src/signInPage.cpp \
    src/main.cpp \
    src/signUpPage.cpp \
    src/sockettest.cpp \
    src/welcomePage.cpp

INCLUDEPATH += \
    headers/ include \

OBJECTS_DIR = $$_PRO_FILE_PWD_/bin/
DESTDIR = $$_PRO_FILE_PWD_/bin/
