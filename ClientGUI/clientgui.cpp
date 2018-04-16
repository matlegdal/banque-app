#include "clientgui.h"
#include "ajoutchequeinterface.h"
#include "Cheque.h"
#include "CompteException.h"
#include <qmessagebox.h>
#include "Client.h"
#include <iostream>

ClientGUI::ClientGUI(QWidget *parent)
	: QMainWindow(parent), client(1000, "Dalcourt", "Mathieu", "819 640-1681",
		util::Date(8, 10, 1990))
{
	ui.setupUi(this);
	QObject::connect(ui.actionCheque, SIGNAL(triggered()), this, SLOT(dialogAjoutCheque()));
}

ClientGUI::~ClientGUI()
{

}

void ClientGUI::dialogAjoutCheque()
{
	AjoutChequeInterface saisieCheque(this);
	if (saisieCheque.exec())
	{
		// todo: ajout le facultatif de la description
		ajoutCheque(saisieCheque.reqNoCompte(), saisieCheque.reqTauxInteret(),
			saisieCheque.reqSolde(), saisieCheque.reqNombreTransactions(),
			saisieCheque.reqTauxInteretMinimum(), saisieCheque.reqDescription().toStdString());
	}
}

void ClientGUI::ajoutCheque(int p_noCompte, double p_tauxInteret, double p_solde,
	int p_nombreTransactions, double p_tauxInteretMinimum, const std::string& p_description)
{
	try
	{
		banque::Cheque compteCheque(p_noCompte, p_tauxInteret, p_solde, p_nombreTransactions,
			p_tauxInteretMinimum, p_description);
		client.ajouterCompte(compteCheque);
	} catch (banque::CompteDejaPresentException e)
	{
		QString message = e.what();
		QMessageBox::information(this, "Erreur", message);
	}
}
