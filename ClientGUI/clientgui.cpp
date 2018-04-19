#include "clientgui.h"
#include "ajoutchequeinterface.h"
#include "supprimercompteinterface.h"
#include "Cheque.h"
#include "CompteException.h"
#include <qmessagebox.h>
#include "Client.h"
#include <iostream>
#include "Epargne.h"
#include "ajoutepargneinterface.h"

ClientGUI::ClientGUI(QWidget *parent)
	: QMainWindow(parent), client(1000, "Standard", "Client", "418 123-1234",
		util::Date(1, 1, 1990))
{
	ui.setupUi(this);
	QObject::connect(ui.actionCheque, SIGNAL(triggered()), this, SLOT(dialogAjoutCheque()));
	QObject::connect(ui.actionSupprimer_un_compte, SIGNAL(triggered()), this,
		SLOT(dialogSupprimerCompte()));
	QObject::connect(ui.actionEpargne, SIGNAL(triggered()), this, SLOT(dialogAjoutEpargne()));
	ui.textBrowser_infoClient->setText(client.reqClientFormate().c_str());
	ui.textBrowser_infoClient->setText(client.reqClientFormate().c_str());
}

ClientGUI::~ClientGUI()
{

}

void ClientGUI::dialogAjoutCheque()
{
	AjoutChequeInterface saisieCheque(this);
	if (saisieCheque.exec())
	{
		std::string description = saisieCheque.reqDescription().toStdString();
		if (description.empty())
		{
			description = "Cheque";
		}
		ajoutCheque(saisieCheque.reqNoCompte(), saisieCheque.reqTauxInteret(),
			saisieCheque.reqSolde(), saisieCheque.reqNombreTransactions(),
			saisieCheque.reqTauxInteretMinimum(), description);
	}
}

void ClientGUI::dialogSupprimerCompte()
{
	SupprimerCompteInterface saisieSuppression(this);
	if (saisieSuppression.exec())
	{
		supprimerCompte(saisieSuppression.reqNoCompte());
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

		int rowCount = ui.tableWidget_comptes->rowCount();
		ui.tableWidget_comptes->setRowCount(rowCount + 1);

		ui.tableWidget_comptes->setItem(rowCount, 0,
			new QTableWidgetItem(QString::number(compteCheque.reqNoCompte())));
		ui.tableWidget_comptes->setItem(rowCount, 1, new QTableWidgetItem("Cheque"));
		ui.tableWidget_comptes->setItem(rowCount, 2,
			new QTableWidgetItem(QString::number(compteCheque.reqSolde())));
		ui.tableWidget_comptes->setItem(rowCount, 3,
					new QTableWidgetItem(QString::number(compteCheque.reqTauxInteret())));

	} catch (banque::CompteDejaPresentException &e)
	{
		QString message = e.what();
		QMessageBox::warning(this, "Erreur le compte suivant est deja present", message);
	}
}

void ClientGUI::supprimerCompte(int p_noCompte)
{
	try
	{
		client.supprimerCompte(p_noCompte);

		QString s = QString::number(p_noCompte);
		int rows = ui.tableWidget_comptes->rowCount();
		bool found = false;
		for (int i = 0; !found && i < rows; ++i)
		{
			if (ui.tableWidget_comptes->item(i, 0)->text() == s)
			{
				ui.tableWidget_comptes->removeRow(i);
				found = true;
			}
		}

	} catch (banque::CompteAbsentException &e)
	{
		QString message = e.what();
		QMessageBox::warning(this, "Erreur le compte est absent", message);
	} catch (std::runtime_error &e)
	{
		std::string message = e.what();
		std::cout << message << std::endl;
	}
}

void ClientGUI::dialogAjoutEpargne()
{
	ajoutepargneinterface saisieEpargne(this);
	if (saisieEpargne.exec())
	{
		std::string description = saisieEpargne.reqDescription().toStdString();
		if (description.empty())
		{
			description = "Epargne";
		}
		ajoutEpargne(saisieEpargne.reqNoCompte(), saisieEpargne.reqTauxInteret(),
			saisieEpargne.reqSolde(),description);
	}
}

void ClientGUI::ajoutEpargne(int p_noCompte, double p_tauxInteret, double p_solde,
	const std::string& p_description)
{
	try
	{
		banque::Epargne compteEpargne(p_noCompte, p_tauxInteret, p_solde,
			p_description);
		client.ajouterCompte(compteEpargne);

		int rowCount = ui.tableWidget_comptes->rowCount();
		ui.tableWidget_comptes->setRowCount(rowCount + 1);

		QString s = QString::number(compteEpargne.reqNoCompte());
		ui.tableWidget_comptes->setItem(rowCount, 0, new QTableWidgetItem(s));
		ui.tableWidget_comptes->setItem(rowCount, 1, new QTableWidgetItem("Epargne"));

	} catch (banque::CompteDejaPresentException e)
	{
		QString message = e.what();
		QMessageBox::warning(this, "Erreur le compte suivant est deja present", message);
	}
}
