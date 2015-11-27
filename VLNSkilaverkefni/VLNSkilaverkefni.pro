QT += core
QT -= gui

TARGET = VLNSkilaverkefni
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    data.cpp \
    domain.cpp \
    presentation.cpp \
    cscientist.cpp

HEADERS += \
    data.h \
    domain.h \
    presentation.h \
    cscientist.h

