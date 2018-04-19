/********************************************************************************
** Form generated from reading UI file 'supprimercompteinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERCOMPTEINTERFACE_H
#define UI_SUPPRIMERCOMPTEINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SupprimerCompteInterfaceClass
{
public:
    QLabel *label_titre;
    QLabel *label_noCompte;
    QSpinBox *spinBox_noCompte;
    QPushButton *pushButton_supprimerCompte;

    void setupUi(QDialog *SupprimerCompteInterfaceClass)
    {
        if (SupprimerCompteInterfaceClass->objectName().isEmpty())
            SupprimerCompteInterfaceClass->setObjectName(QString::fromUtf8("SupprimerCompteInterfaceClass"));
        SupprimerCompteInterfaceClass->resize(333, 184);
        label_titre = new QLabel(SupprimerCompteInterfaceClass);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));
        label_titre->setGeometry(QRect(90, 20, 181, 21));
        QFont font;
        font.setPointSize(12);
        label_titre->setFont(font);
        label_noCompte = new QLabel(SupprimerCompteInterfaceClass);
        label_noCompte->setObjectName(QString::fromUtf8("label_noCompte"));
        label_noCompte->setGeometry(QRect(30, 70, 141, 31));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label_noCompte->setFont(font1);
        spinBox_noCompte = new QSpinBox(SupprimerCompteInterfaceClass);
        spinBox_noCompte->setObjectName(QString::fromUtf8("spinBox_noCompte"));
        spinBox_noCompte->setGeometry(QRect(170, 70, 121, 27));
        spinBox_noCompte->setFont(font1);
        spinBox_noCompte->setMinimum(1);
        spinBox_noCompte->setMaximum(99);
        pushButton_supprimerCompte = new QPushButton(SupprimerCompteInterfaceClass);
        pushButton_supprimerCompte->setObjectName(QString::fromUtf8("pushButton_supprimerCompte"));
        pushButton_supprimerCompte->setGeometry(QRect(70, 140, 161, 27));

        retranslateUi(SupprimerCompteInterfaceClass);

        QMetaObject::connectSlotsByName(SupprimerCompteInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *SupprimerCompteInterfaceClass)
    {
        SupprimerCompteInterfaceClass->setWindowTitle(QApplication::translate("SupprimerCompteInterfaceClass", "SupprimerCompteInterface", 0, QApplication::UnicodeUTF8));
        label_titre->setText(QApplication::translate("SupprimerCompteInterfaceClass", "Supprimer un compte", 0, QApplication::UnicodeUTF8));
        label_noCompte->setText(QApplication::translate("SupprimerCompteInterfaceClass", "No du compte", 0, QApplication::UnicodeUTF8));
        pushButton_supprimerCompte->setText(QApplication::translate("SupprimerCompteInterfaceClass", "Supprimer le compte", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SupprimerCompteInterfaceClass: public Ui_SupprimerCompteInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERCOMPTEINTERFACE_H
