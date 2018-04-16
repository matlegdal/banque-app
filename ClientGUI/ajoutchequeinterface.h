#ifndef AJOUTCHEQUEINTERFACE_H
#define AJOUTCHEQUEINTERFACE_H

#include <QtGui/QDialog>
#include "ui_ajoutchequeinterface.h"

class AjoutChequeInterface: public QDialog
{
Q_OBJECT

public:
	AjoutChequeInterface(QWidget *parent = 0);
	~AjoutChequeInterface();

	int reqNoCompte() const;
	double reqTauxInteret() const;
	double reqSolde() const;
	int reqNombreTransactions() const;
	double reqTauxInteretMinimum() const;
	QString reqDescription() const;

public slots:
	void validerEnregistrement();

private:
	Ui::AjoutChequeInterfaceClass ui;
};

#endif // AJOUTCHEQUEINTERFACE_H
