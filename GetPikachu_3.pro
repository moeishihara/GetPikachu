#-------------------------------------------------
#
# Project created by QtCreator 2016-05-28T18:16:59
#
#-------------------------------------------------

QT       += core gui\
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GetPikachu_3
TEMPLATE = app


SOURCES += main.cpp\
        game.cpp \
    ash.cpp \
    pikachu.cpp \
    score.cpp \
    tile.cpp \
    snorlax.cpp \
    muk.cpp \
    health.cpp \
    beedril.cpp

HEADERS  += game.h \
    ash.h \
    pikachu.h \
    score.h \
    tile.h \
    snorlax.h \
    muk.h \
    health.h \
    beedril.h

FORMS    += game.ui

RESOURCES += \
    images.qrc
