#include "supprimercompteinterface.h"
#include <qmessagebox.h>

SupprimerCompteInterface::SupprimerCompteInterface(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton_supprimerCompte, SIGNAL(clicked()), this,
		SLOT(validerSuppression()));
}

SupprimerCompteInterface::~SupprimerCompteInterface()
{

}

void SupprimerCompteInterface::validerSuppression()
{
	if (ui.spinBox_noCompte->value() < 0)
	{
		QString message("Le no de compte doit etre positif.");
		QMessageBox::warning(this, "Erreur", message);
		return;
	}
	else
	{
		accept();
	}
}

int SupprimerCompteInterface::reqNoCompte() const
{
	return ui.spinBox_noCompte->value();
}
