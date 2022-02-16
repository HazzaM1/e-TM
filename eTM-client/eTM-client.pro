QT += \
    network

HEADERS += \
    include/sockettest.h

SOURCES += \
    src/main.cpp \
    src/sockettest.cpp

INCLUDEPATH += \
    headers/ include \

OBJECTS_DIR = $$_PRO_FILE_PWD_/bin/
DESTDIR = $$_PRO_FILE_PWD_/bin/
