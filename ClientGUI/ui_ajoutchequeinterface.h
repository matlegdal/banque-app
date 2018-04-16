/********************************************************************************
** Form generated from reading UI file 'ajoutchequeinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTCHEQUEINTERFACE_H
#define UI_AJOUTCHEQUEINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutChequeInterfaceClass
{
public:
    QLabel *label_titre;
    QLabel *label_noCompte;
    QSpinBox *spinBox_noCompte;
    QLabel *label_tauxInteret;
    QDoubleSpinBox *doubleSpinBox_tauxInteret;
    QLabel *label_solde;
    QDoubleSpinBox *doubleSpinBox_solde;
    QLabel *label_nombreTransactions;
    QSpinBox *spinBox_nombreTransactions;
    QLabel *label_tauxInteretMinimum;
    QDoubleSpinBox *doubleSpinBox_tauxInteretMinimum;
    QLabel *label_description;
    QPushButton *pushButton_ajoutCheque;
    QLineEdit *lineEdit_description;

    void setupUi(QDialog *AjoutChequeInterfaceClass)
    {
        if (AjoutChequeInterfaceClass->objectName().isEmpty())
            AjoutChequeInterfaceClass->setObjectName(QString::fromUtf8("AjoutChequeInterfaceClass"));
        AjoutChequeInterfaceClass->resize(400, 419);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        AjoutChequeInterfaceClass->setFont(font);
        label_titre = new QLabel(AjoutChequeInterfaceClass);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));
        label_titre->setGeometry(QRect(80, 20, 231, 21));
        QFont font1;
        font1.setPointSize(12);
        label_titre->setFont(font1);
        label_noCompte = new QLabel(AjoutChequeInterfaceClass);
        label_noCompte->setObjectName(QString::fromUtf8("label_noCompte"));
        label_noCompte->setGeometry(QRect(40, 70, 141, 31));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        label_noCompte->setFont(font2);
        spinBox_noCompte = new QSpinBox(AjoutChequeInterfaceClass);
        spinBox_noCompte->setObjectName(QString::fromUtf8("spinBox_noCompte"));
        spinBox_noCompte->setGeometry(QRect(210, 70, 121, 27));
        spinBox_noCompte->setFont(font2);
        spinBox_noCompte->setMinimum(1);
        spinBox_noCompte->setMaximum(99);
        label_tauxInteret = new QLabel(AjoutChequeInterfaceClass);
        label_tauxInteret->setObjectName(QString::fromUtf8("label_tauxInteret"));
        label_tauxInteret->setGeometry(QRect(40, 110, 141, 31));
        label_tauxInteret->setFont(font2);
        doubleSpinBox_tauxInteret = new QDoubleSpinBox(AjoutChequeInterfaceClass);
        doubleSpinBox_tauxInteret->setObjectName(QString::fromUtf8("doubleSpinBox_tauxInteret"));
        doubleSpinBox_tauxInteret->setGeometry(QRect(210, 110, 121, 27));
        doubleSpinBox_tauxInteret->setFont(font2);
        doubleSpinBox_tauxInteret->setMinimum(-100);
        doubleSpinBox_tauxInteret->setMaximum(100);
        doubleSpinBox_tauxInteret->setValue(2);
        label_solde = new QLabel(AjoutChequeInterfaceClass);
        label_solde->setObjectName(QString::fromUtf8("label_solde"));
        label_solde->setGeometry(QRect(40, 150, 141, 31));
        label_solde->setFont(font2);
        doubleSpinBox_solde = new QDoubleSpinBox(AjoutChequeInterfaceClass);
        doubleSpinBox_solde->setObjectName(QString::fromUtf8("doubleSpinBox_solde"));
        doubleSpinBox_solde->setGeometry(QRect(210, 150, 121, 27));
        doubleSpinBox_solde->setFont(font2);
        doubleSpinBox_solde->setMinimum(-1e+06);
        doubleSpinBox_solde->setMaximum(1e+06);
        doubleSpinBox_solde->setSingleStep(100);
        doubleSpinBox_solde->setValue(-100);
        label_nombreTransactions = new QLabel(AjoutChequeInterfaceClass);
        label_nombreTransactions->setObjectName(QString::fromUtf8("label_nombreTransactions"));
        label_nombreTransactions->setGeometry(QRect(40, 190, 141, 31));
        label_nombreTransactions->setFont(font2);
        spinBox_nombreTransactions = new QSpinBox(AjoutChequeInterfaceClass);
        spinBox_nombreTransactions->setObjectName(QString::fromUtf8("spinBox_nombreTransactions"));
        spinBox_nombreTransactions->setGeometry(QRect(210, 190, 121, 27));
        spinBox_nombreTransactions->setFont(font2);
        spinBox_nombreTransactions->setMinimum(0);
        spinBox_nombreTransactions->setMaximum(40);
        spinBox_nombreTransactions->setValue(5);
        label_tauxInteretMinimum = new QLabel(AjoutChequeInterfaceClass);
        label_tauxInteretMinimum->setObjectName(QString::fromUtf8("label_tauxInteretMinimum"));
        label_tauxInteretMinimum->setGeometry(QRect(40, 230, 161, 31));
        label_tauxInteretMinimum->setFont(font2);
        doubleSpinBox_tauxInteretMinimum = new QDoubleSpinBox(AjoutChequeInterfaceClass);
        doubleSpinBox_tauxInteretMinimum->setObjectName(QString::fromUtf8("doubleSpinBox_tauxInteretMinimum"));
        doubleSpinBox_tauxInteretMinimum->setGeometry(QRect(210, 230, 121, 27));
        doubleSpinBox_tauxInteretMinimum->setFont(font2);
        doubleSpinBox_tauxInteretMinimum->setMinimum(-100);
        doubleSpinBox_tauxInteretMinimum->setMaximum(100);
        doubleSpinBox_tauxInteretMinimum->setValue(1);
        label_description = new QLabel(AjoutChequeInterfaceClass);
        label_description->setObjectName(QString::fromUtf8("label_description"));
        label_description->setGeometry(QRect(40, 270, 141, 31));
        label_description->setFont(font2);
        pushButton_ajoutCheque = new QPushButton(AjoutChequeInterfaceClass);
        pushButton_ajoutCheque->setObjectName(QString::fromUtf8("pushButton_ajoutCheque"));
        pushButton_ajoutCheque->setGeometry(QRect(100, 370, 161, 27));
        lineEdit_description = new QLineEdit(AjoutChequeInterfaceClass);
        lineEdit_description->setObjectName(QString::fromUtf8("lineEdit_description"));
        lineEdit_description->setGeometry(QRect(40, 310, 291, 31));

        retranslateUi(AjoutChequeInterfaceClass);

        QMetaObject::connectSlotsByName(AjoutChequeInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *AjoutChequeInterfaceClass)
    {
        AjoutChequeInterfaceClass->setWindowTitle(QApplication::translate("AjoutChequeInterfaceClass", "AjoutChequeInterface", 0, QApplication::UnicodeUTF8));
        label_titre->setText(QApplication::translate("AjoutChequeInterfaceClass", "Ajout d'un compte ch\303\250que", 0, QApplication::UnicodeUTF8));
        label_noCompte->setText(QApplication::translate("AjoutChequeInterfaceClass", "No du compte", 0, QApplication::UnicodeUTF8));
        label_tauxInteret->setText(QApplication::translate("AjoutChequeInterfaceClass", "Taux d'int\303\251r\303\252t (%)", 0, QApplication::UnicodeUTF8));
        label_solde->setText(QApplication::translate("AjoutChequeInterfaceClass", "Solde ($)", 0, QApplication::UnicodeUTF8));
        label_nombreTransactions->setText(QApplication::translate("AjoutChequeInterfaceClass", "Nombre de transactions", 0, QApplication::UnicodeUTF8));
        label_tauxInteretMinimum->setText(QApplication::translate("AjoutChequeInterfaceClass", "Taux d'int\303\251r\303\252t minimum (%)", 0, QApplication::UnicodeUTF8));
        label_description->setText(QApplication::translate("AjoutChequeInterfaceClass", "Description (facultatif)", 0, QApplication::UnicodeUTF8));
        pushButton_ajoutCheque->setText(QApplication::translate("AjoutChequeInterfaceClass", "Enregistrer le compte", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AjoutChequeInterfaceClass: public Ui_AjoutChequeInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTCHEQUEINTERFACE_H
