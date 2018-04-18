#include "ajoutchequeinterface.h"
#include <qmessagebox.h>

AjoutChequeInterface::AjoutChequeInterface(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton_ajoutCheque, SIGNAL(clicked()), this,
		SLOT(validerEnregistrement()));
}

AjoutChequeInterface::~AjoutChequeInterface()
{

}

void AjoutChequeInterface::validerEnregistrement()
{
	if (ui.doubleSpinBox_tauxInteret->value() < ui.doubleSpinBox_tauxInteretMinimum->value())
	{
		QString message("Le taux d'interet doit etre superieur au taux d'interet minimum.");
		QMessageBox::information(this, "Erreur", message);
		return;
	}
	else
	{
		accept();
	}
}

int AjoutChequeInterface::reqNoCompte() const
{
	return ui.spinBox_noCompte->value();
}
double AjoutChequeInterface::reqTauxInteret() const
{
	return ui.doubleSpinBox_tauxInteret->value();
}
double AjoutChequeInterface::reqSolde() const
{
	return ui.doubleSpinBox_solde->value();
}
int AjoutChequeInterface::reqNombreTransactions() const
{
	return ui.spinBox_nombreTransactions->value();
}
double AjoutChequeInterface::reqTauxInteretMinimum() const
{
	return ui.doubleSpinBox_tauxInteretMinimum->value();
}
QString AjoutChequeInterface::reqDescription() const
{
	return ui.lineEdit_description->text();
}
