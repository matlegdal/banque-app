#include "ajoutepargneinterface.h"
#include <qmessagebox.h>

ajoutepargneinterface::ajoutepargneinterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton_ajoutEpargne, SIGNAL(clicked()), this,
		SLOT(validerEnregistrement()));
}

ajoutepargneinterface::~ajoutepargneinterface()
{

}

void ajoutepargneinterface::validerEnregistrement()
{
	accept();
}

int ajoutepargneinterface::reqNoCompte() const
{
	return ui.spinBox_noCompte->value();
}
double ajoutepargneinterface::reqTauxInteret() const
{
	return ui.doubleSpinBox_tauxInteret->value();
}
double ajoutepargneinterface::reqSolde() const
{
	return ui.doubleSpinBox_solde->value();
}
QString ajoutepargneinterface::reqDescription() const
{
	return ui.lineEdit_description->text();
}
