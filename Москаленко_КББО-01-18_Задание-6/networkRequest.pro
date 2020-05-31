TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lpthread
LIBS += -lboost_thread
LIBS += -lboost_system
LIBS += -lboost_iostreams

SOURCES += \
        main.cpp
