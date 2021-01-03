QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DataBase
TEMPLATE = app

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountdatabase.cpp \
    database.cpp \
    exposewindow.cpp \
    findwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    vacancyviewwindow.cpp \
    verification.cpp

HEADERS += \
    accountdatabase.h \
    database.h \
    exposewindow.h \
    findwindow.h \
    mainwindow.h \
    vacancyviewwindow.h \
    verification.h

FORMS += \
    exposewindow.ui \
    findwindow.ui \
    mainwindow.ui \
    vacancyviewwindow.ui \
    verification.ui

RESOURCES += \
    image.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Share all project output files by directories
MOC_DIR = moc
RCC_DIR = rcc
UI_DIR = ui
unix:OBJECTS_DIR = unix
win32:OBJECTS_DIR = win32
macx:OBJECTS_DIR = mac

# За допомогою даного коду при збірці Релізу проєкту Qt збире у папку реліз ще й усі необхідні dll-ки, необхідні для запуску проєкту на інших ПК
# If release-buid -> run windeploy applications, that will collect all the dlls
CONFIG(release, debug|release) {
    win32:QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt $$OUT_PWD/release
}


