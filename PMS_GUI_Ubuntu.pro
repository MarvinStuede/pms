#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T17:24:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#INCLUDEPATH +=../wiringPI/wiringPI
#LIBS   += -L../wiringPI/wiringPI -lwiringPi
TARGET = PMS_GUI_Ubuntu
TEMPLATE = app
DESTDIR = ./bin
OBJECTS_DIR = ./temp
MOC_DIR = ./temp
RCC_DIR = ./temp
UI_DIR = ./temp

SOURCES += main.cpp\
        mainwindow.cpp \
    controlsystem.cpp \
    mobileplatform.cpp \
    dcmotor.cpp

HEADERS  += mainwindow.h \
    controlsystem.h \
    mobileplatform.h \
    dcmotor.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources/images.qrc
