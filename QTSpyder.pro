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
    config.cpp \
    cameraenumerator.cpp \
    camera.cpp \
    capturedimage.cpp

HEADERS  += \
    mainwindow.h \
    about.h \
    wizard_1.h \
    wizard_2.h \
    config.h \
    cameraenumerator.h \
    camera.h \
    capturedimage.h

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

win32: LIBS += -L$$PWD/contrib/lib/ \
                -lCyCamLib \
                -lCyComLib \
                -lCyDispExLib \
                -lCyEngineLib \
                -lCyGigEVisionLib \
                -lCyImgLib \
                -lCyMediumLib \
                -lCyUtilsLib \
                -lEbSetupLib \
                -lPtPublic \
                -lSpyder3DLL \
                -lSpyderGigE

INCLUDEPATH += $$PWD/contrib/include
DEPENDPATH += $$PWD/contrib/include

DEFINES += CY_UTILS_LIB_STATIC CY_COM_LIB_STATIC CY_CAM_LIB_STATIC
