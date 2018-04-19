#ifndef AJOUTEPARGNEINTERFACE_H
#define AJOUTEPARGNEINTERFACE_H

#include <QtGui/QDialog>
#include "ui_ajoutepargneinterface.h"

class ajoutepargneinterface : public QDialog
{
    Q_OBJECT

public:
    ajoutepargneinterface(QWidget *parent = 0);
    ~ajoutepargneinterface();

	int reqNoCompte() const;
	double reqTauxInteret() const;
	double reqSolde() const;
	QString reqDescription() const;

public slots:
	void validerEnregistrement();

private:
    Ui::ajoutepargneinterfaceClass ui;
};

#endif // AJOUTEPARGNEINTERFACE_H
