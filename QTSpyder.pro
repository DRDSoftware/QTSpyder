#-------------------------------------------------
#
# Project created by QtCreator 2011-11-30T09:45:06
#
#-------------------------------------------------

QT       += core gui

TARGET = QTSpyder
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    about.cpp \
    wizard_1.cpp \
    wizard_2.cpp \
    config.cpp

HEADERS  += \
    mainwindow.h \
    about.h \
    wizard_1.h \
    wizard_2.h \
    config.h

FORMS    += \
    mainwindow.ui \
    about.ui \
    wizard_1.ui \
    wizard_2.ui

RESOURCES += \
    gpl3.qrc \
    spyder3image.qrc \
    locale.qrc \
    icons.qrc

TRANSLATIONS = qtspyder_en_US.ts \
                qtspyder_it_IT.ts








































