QT += \
    network

HEADERS += \
    include/servertest.h

SOURCES += \
    src/main.cpp \
    src/servertest.cpp

INCLUDEPATH += \
    headers/ include \

OBJECTS_DIR = $$_PRO_FILE_PWD_/bin/
DESTDIR = $$_PRO_FILE_PWD_/bin/
