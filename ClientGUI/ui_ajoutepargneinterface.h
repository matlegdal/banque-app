/********************************************************************************
** Form generated from reading UI file 'ajoutepargneinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTEPARGNEINTERFACE_H
#define UI_AJOUTEPARGNEINTERFACE_H

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

class Ui_ajoutepargneinterfaceClass
{
public:
    QLabel *label_ajouterEpargne;
    QLabel *label_noCompte;
    QLabel *label_tauxInteret;
    QLabel *label_solde;
    QLabel *label_description;
    QLineEdit *lineEdit_description;
    QSpinBox *spinBox_noCompte;
    QDoubleSpinBox *doubleSpinBox_tauxInteret;
    QDoubleSpinBox *doubleSpinBox_solde;
    QPushButton *pushButton_ajoutEpargne;

    void setupUi(QDialog *ajoutepargneinterfaceClass)
    {
        if (ajoutepargneinterfaceClass->objectName().isEmpty())
            ajoutepargneinterfaceClass->setObjectName(QString::fromUtf8("ajoutepargneinterfaceClass"));
        ajoutepargneinterfaceClass->resize(400, 300);
        label_ajouterEpargne = new QLabel(ajoutepargneinterfaceClass);
        label_ajouterEpargne->setObjectName(QString::fromUtf8("label_ajouterEpargne"));
        label_ajouterEpargne->setGeometry(QRect(90, 30, 221, 21));
        label_noCompte = new QLabel(ajoutepargneinterfaceClass);
        label_noCompte->setObjectName(QString::fromUtf8("label_noCompte"));
        label_noCompte->setGeometry(QRect(20, 70, 121, 17));
        label_tauxInteret = new QLabel(ajoutepargneinterfaceClass);
        label_tauxInteret->setObjectName(QString::fromUtf8("label_tauxInteret"));
        label_tauxInteret->setGeometry(QRect(20, 110, 111, 17));
        label_solde = new QLabel(ajoutepargneinterfaceClass);
        label_solde->setObjectName(QString::fromUtf8("label_solde"));
        label_solde->setGeometry(QRect(20, 150, 101, 17));
        label_description = new QLabel(ajoutepargneinterfaceClass);
        label_description->setObjectName(QString::fromUtf8("label_description"));
        label_description->setGeometry(QRect(20, 190, 141, 17));
        lineEdit_description = new QLineEdit(ajoutepargneinterfaceClass);
        lineEdit_description->setObjectName(QString::fromUtf8("lineEdit_description"));
        lineEdit_description->setGeometry(QRect(20, 220, 361, 27));
        spinBox_noCompte = new QSpinBox(ajoutepargneinterfaceClass);
        spinBox_noCompte->setObjectName(QString::fromUtf8("spinBox_noCompte"));
        spinBox_noCompte->setGeometry(QRect(250, 70, 131, 27));
        spinBox_noCompte->setMinimum(1);
        spinBox_noCompte->setValue(1);
        doubleSpinBox_tauxInteret = new QDoubleSpinBox(ajoutepargneinterfaceClass);
        doubleSpinBox_tauxInteret->setObjectName(QString::fromUtf8("doubleSpinBox_tauxInteret"));
        doubleSpinBox_tauxInteret->setGeometry(QRect(250, 110, 131, 27));
        doubleSpinBox_tauxInteret->setValue(1);
        doubleSpinBox_solde = new QDoubleSpinBox(ajoutepargneinterfaceClass);
        doubleSpinBox_solde->setObjectName(QString::fromUtf8("doubleSpinBox_solde"));
        doubleSpinBox_solde->setGeometry(QRect(250, 150, 131, 27));
        doubleSpinBox_solde->setMaximum(1e+06);
        doubleSpinBox_solde->setValue(400);
        pushButton_ajoutEpargne = new QPushButton(ajoutepargneinterfaceClass);
        pushButton_ajoutEpargne->setObjectName(QString::fromUtf8("pushButton_ajoutEpargne"));
        pushButton_ajoutEpargne->setGeometry(QRect(110, 260, 171, 27));

        retranslateUi(ajoutepargneinterfaceClass);

        QMetaObject::connectSlotsByName(ajoutepargneinterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *ajoutepargneinterfaceClass)
    {
        ajoutepargneinterfaceClass->setWindowTitle(QApplication::translate("ajoutepargneinterfaceClass", "ajoutepargneinterface", 0, QApplication::UnicodeUTF8));
        label_ajouterEpargne->setText(QApplication::translate("ajoutepargneinterfaceClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Ajout d'un compte \303\251pargne</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:600;\"></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        label_noCompte->setText(QApplication::translate("ajoutepargneinterfaceClass", "Num\303\251ro de compte", 0, QApplication::UnicodeUTF8));
        label_tauxInteret->setText(QApplication::translate("ajoutepargneinterfaceClass", "Taux d'int\303\251r\303\252t (%)", 0, QApplication::UnicodeUTF8));
        label_solde->setText(QApplication::translate("ajoutepargneinterfaceClass", "Solde ($)", 0, QApplication::UnicodeUTF8));
        label_description->setText(QApplication::translate("ajoutepargneinterfaceClass", "Description (facultative)", 0, QApplication::UnicodeUTF8));
        pushButton_ajoutEpargne->setText(QApplication::translate("ajoutepargneinterfaceClass", "Enregistrer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ajoutepargneinterfaceClass: public Ui_ajoutepargneinterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTEPARGNEINTERFACE_H
