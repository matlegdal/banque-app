#ifndef CLIENTGUI_H
#define CLIENTGUI_H

#include <QtGui/QMainWindow>
#include "ui_clientgui.h"

class ClientGUI : public QMainWindow
{
    Q_OBJECT

public:
    ClientGUI(QWidget *parent = 0);
    ~ClientGUI();

private:
    Ui::ClientGUIClass ui;
};

#endif // CLIENTGUI_H
