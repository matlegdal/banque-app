TEMPLATE = app
TARGET = ClientGUI 

QT        += core gui 

HEADERS   += clientgui.h
SOURCES   += main.cpp \
    clientgui.cpp
FORMS     += clientgui.ui    
RESOURCES +=
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."