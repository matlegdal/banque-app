TEMPLATE = app
TARGET = ClientGUI
QT += core \
    gui
HEADERS += supprimercompteinterface.h \
    ajoutchequeinterface.h \
    clientgui.h
SOURCES += supprimercompteinterface.cpp \
    ajoutchequeinterface.cpp \
    main.cpp \
    clientgui.cpp
FORMS += supprimercompteinterface.ui \
    ajoutchequeinterface.ui \
    clientgui.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
