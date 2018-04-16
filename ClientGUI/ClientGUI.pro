TEMPLATE = app
TARGET = ClientGUI
QT += core \
    gui
HEADERS += ajoutchequeinterface.h \
    clientgui.h
SOURCES += ajoutchequeinterface.cpp \
    main.cpp \
    clientgui.cpp
FORMS += ajoutchequeinterface.ui \
    clientgui.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
