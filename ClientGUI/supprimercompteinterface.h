#ifndef SUPPRIMERCOMPTEINTERFACE_H
#define SUPPRIMERCOMPTEINTERFACE_H

#include <QtGui/QDialog>
#include "ui_supprimercompteinterface.h"

class SupprimerCompteInterface: public QDialog
{
Q_OBJECT

public:
	SupprimerCompteInterface(QWidget *parent = 0);
	~SupprimerCompteInterface();

	int reqNoCompte() const;

public slots:
	void validerSuppression();

private:
	Ui::SupprimerCompteInterfaceClass ui;
};

#endif // SUPPRIMERCOMPTEINTERFACE_H
