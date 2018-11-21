#-------------------------------------------------
#
# Project created by QtCreator 2018-11-08T19:34:00
#
#-------------------------------------------------
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 # ~~~~~~~~~~~~~~~~~~~~`PROGRAM DONE BY ABHISHEK BALASUBRAMANIAM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
 # ~~~~~~~~~~~~~~~~~~~~ FOR MORE INFORMATION CONTACT (abhisheklokesh6008@gmail.com) ~~~~~~~~~~~~~~~~~
 # ~~~~~~~~~~~~~~~~~~~~ VISIT ME AT www.abhishekbalu.com ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 # ~~~~~~~~~~~~~~~~~~~~
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = mcalib_V-2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mcalib.cpp \
    qcustomplot.cpp \


HEADERS += \
        mcalib.h \
    qcustomplot.h \


FORMS += \
        mcalib.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    mcalib.qrc
