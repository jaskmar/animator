#-------------------------------------------------
#
# Project created by QtCreator 2013-02-14T21:36:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QAnimator
TEMPLATE = app

LIBS += -ltbb
LIBS += -LC:/tbb/lib
INCLUDEPATH += C:/tbb/include


SOURCES += main.cpp\
        mainwindow.cpp \
    VPrzejscia.cpp \
    przejscie.cpp \
    controller.cpp \
    P/PTesty.cpp \
    P/PRGB.cpp \
    P/PPrzylot.cpp \
    P/PPrzepychanie_up.cpp \
    P/PPrzepychanie_right.cpp \
    P/PPrzepychanie_left.cpp \
    P/PPrzepychanie_down.cpp \
    P/PPrzenikanie.cpp \
    P/PPaski.cpp \
    P/POkno.cpp \
    P/POdwrot.cpp \
    P/POdswiezanie_up.cpp \
    P/POdlot.cpp \
    P/POdkrywanie_up.cpp \
    P/PNajazd_up.cpp \
    P/PKostka.cpp \
    P/PKolejnoscJasnosc.cpp \
    P/PFarba.cpp \
    P/PCzern.cpp \
    P/PBoks_out.cpp \
    P/PBoks_in.cpp \
    tbbsaveworker.cpp \
    savethreadworker.cpp \
    generatethreadworker.cpp

HEADERS  += mainwindow.h \
    VPrzejscia.h \
    przejscie.h \
    controller.h \
    P/PTesty.h \
    P/PRGB.h \
    P/PPrzylot.h \
    P/PPrzepychanie_up.h \
    P/PPrzepychanie_right.h \
    P/PPrzepychanie_left.h \
    P/PPrzepychanie_down.h \
    P/PPrzenikanie.h \
    P/PPaski.h \
    P/POkno.h \
    P/POdwrot.h \
    P/POdswiezanie_up.h \
    P/POdlot.h \
    P/POdkrywanie_up.h \
    P/PNajazd_up.h \
    P/PKostka.h \
    P/PKolejnoscJasnosc.h \
    P/PFarba.h \
    P/PCzern.h \
    P/PBoks_out.h \
    P/PBoks_in.h \
    tbbsaveworker.h \
    savethreadworker.h \
    generatethreadworker.h

FORMS    += mainwindow.ui
