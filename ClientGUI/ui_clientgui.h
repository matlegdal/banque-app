/********************************************************************************
** Form generated from reading UI file 'clientgui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTGUI_H
#define UI_CLIENTGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientGUIClass
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClientGUIClass)
    {
        if (ClientGUIClass->objectName().isEmpty())
            ClientGUIClass->setObjectName(QString::fromUtf8("ClientGUIClass"));
        ClientGUIClass->resize(800, 600);
        centralwidget = new QWidget(ClientGUIClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ClientGUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClientGUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        ClientGUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(ClientGUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ClientGUIClass->setStatusBar(statusbar);

        retranslateUi(ClientGUIClass);

        QMetaObject::connectSlotsByName(ClientGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *ClientGUIClass)
    {
        ClientGUIClass->setWindowTitle(QApplication::translate("ClientGUIClass", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClientGUIClass: public Ui_ClientGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTGUI_H
