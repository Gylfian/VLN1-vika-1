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
    computerscientist.cpp

HEADERS += \
    data.h \
    domain.h \
    presentation.h \
    main.h \
    computerscientist.h

