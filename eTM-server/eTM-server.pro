QT += \
    network \
    mqtt \
    widgets \
    sql

HEADERS += \
    include/dbmanager.h \
    include/mqttServer.h \
    include/server.h \
    include/process.h \
    include/manager.h

SOURCES += \
    src/dbmanager.cpp \
    src/main.cpp \
    src/mqttServer.cpp \
    src/server.cpp \
    src/manager.cpp \

INCLUDEPATH += \
    headers/ include \

OBJECTS_DIR = $$_PRO_FILE_PWD_/bin/
DESTDIR = $$_PRO_FILE_PWD_/bin/

FORMS += \
    src/form.ui
