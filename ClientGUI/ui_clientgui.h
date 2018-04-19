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
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientGUIClass
{
public:
    QAction *actionQuitter;
    QAction *actionSupprimer_un_compte;
    QAction *actionCompte_Ch_que;
    QAction *actionCompte_pargne;
    QAction *actionCheque;
    QAction *actionEpargne;
    QWidget *centralwidget;
    QTableWidget *tableWidget_comptes;
    QTextBrowser *textBrowser_infoClient;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuActions;
    QMenu *menuAjouter_un_compte;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClientGUIClass)
    {
        if (ClientGUIClass->objectName().isEmpty())
            ClientGUIClass->setObjectName(QString::fromUtf8("ClientGUIClass"));
        ClientGUIClass->resize(800, 600);
        actionQuitter = new QAction(ClientGUIClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionSupprimer_un_compte = new QAction(ClientGUIClass);
        actionSupprimer_un_compte->setObjectName(QString::fromUtf8("actionSupprimer_un_compte"));
        actionCompte_Ch_que = new QAction(ClientGUIClass);
        actionCompte_Ch_que->setObjectName(QString::fromUtf8("actionCompte_Ch_que"));
        actionCompte_pargne = new QAction(ClientGUIClass);
        actionCompte_pargne->setObjectName(QString::fromUtf8("actionCompte_pargne"));
        actionCheque = new QAction(ClientGUIClass);
        actionCheque->setObjectName(QString::fromUtf8("actionCheque"));
        actionEpargne = new QAction(ClientGUIClass);
        actionEpargne->setObjectName(QString::fromUtf8("actionEpargne"));
        centralwidget = new QWidget(ClientGUIClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget_comptes = new QTableWidget(centralwidget);
        if (tableWidget_comptes->columnCount() < 6)
            tableWidget_comptes->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_comptes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_comptes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_comptes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_comptes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_comptes->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_comptes->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget_comptes->setObjectName(QString::fromUtf8("tableWidget_comptes"));
        tableWidget_comptes->setGeometry(QRect(20, 120, 761, 421));
        tableWidget_comptes->setEditTriggers(QAbstractItemView::NoEditTriggers);
        textBrowser_infoClient = new QTextBrowser(centralwidget);
        textBrowser_infoClient->setObjectName(QString::fromUtf8("textBrowser_infoClient"));
        textBrowser_infoClient->setGeometry(QRect(20, 10, 761, 81));
        ClientGUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ClientGUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuActions = new QMenu(menubar);
        menuActions->setObjectName(QString::fromUtf8("menuActions"));
        menuAjouter_un_compte = new QMenu(menuActions);
        menuAjouter_un_compte->setObjectName(QString::fromUtf8("menuAjouter_un_compte"));
        ClientGUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(ClientGUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ClientGUIClass->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuActions->menuAction());
        menuFichier->addAction(actionQuitter);
        menuActions->addAction(menuAjouter_un_compte->menuAction());
        menuActions->addAction(actionSupprimer_un_compte);
        menuAjouter_un_compte->addAction(actionCheque);
        menuAjouter_un_compte->addAction(actionEpargne);

        retranslateUi(ClientGUIClass);
        QObject::connect(actionQuitter, SIGNAL(triggered()), ClientGUIClass, SLOT(close()));

        QMetaObject::connectSlotsByName(ClientGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *ClientGUIClass)
    {
        ClientGUIClass->setWindowTitle(QApplication::translate("ClientGUIClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("ClientGUIClass", "Quitter", 0, QApplication::UnicodeUTF8));
        actionSupprimer_un_compte->setText(QApplication::translate("ClientGUIClass", "Supprimer un compte", 0, QApplication::UnicodeUTF8));
        actionCompte_Ch_que->setText(QApplication::translate("ClientGUIClass", "Compte Cheque", 0, QApplication::UnicodeUTF8));
        actionCompte_pargne->setText(QApplication::translate("ClientGUIClass", "Compte Epargne", 0, QApplication::UnicodeUTF8));
        actionCheque->setText(QApplication::translate("ClientGUIClass", "Compte Ch\303\250que", 0, QApplication::UnicodeUTF8));
        actionEpargne->setText(QApplication::translate("ClientGUIClass", "Compte \303\211pargne", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_comptes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ClientGUIClass", "No Compte", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_comptes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ClientGUIClass", "Type de compte", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_comptes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ClientGUIClass", "Solde", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_comptes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ClientGUIClass", "Taux d'interet", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_comptes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ClientGUIClass", "Nb de transaction", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_comptes->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ClientGUIClass", "Taux minimum", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("ClientGUIClass", "Fichier", 0, QApplication::UnicodeUTF8));
        menuActions->setTitle(QApplication::translate("ClientGUIClass", "Actions", 0, QApplication::UnicodeUTF8));
        menuAjouter_un_compte->setTitle(QApplication::translate("ClientGUIClass", "Ajouter un compte", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClientGUIClass: public Ui_ClientGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTGUI_H
