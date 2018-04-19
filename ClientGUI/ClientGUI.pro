TEMPLATE = app
TARGET = ClientGUI
QT += core \
    gui
HEADERS += ajoutepargneinterface.h \
    supprimercompteinterface.h \
    ajoutchequeinterface.h \
    clientgui.h
SOURCES += ajoutepargneinterface.cpp \
    supprimercompteinterface.cpp \
    ajoutchequeinterface.cpp \
    main.cpp \
    clientgui.cpp
FORMS += ajoutepargneinterface.ui \
    supprimercompteinterface.ui \
    ajoutchequeinterface.ui \
    clientgui.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
