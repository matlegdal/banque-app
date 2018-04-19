#ifndef CLIENTGUI_H
#define CLIENTGUI_H

#include <QtGui/QMainWindow>
#include "ui_clientgui.h"
#include "Client.h"

class ClientGUI: public QMainWindow
{
Q_OBJECT

public:
	ClientGUI(QWidget *parent = 0);
	~ClientGUI();

	void ajoutCheque(int p_noCompte, double p_tauxInteret, double p_solde, int p_nombreTransactions,
		double p_tauxInteretMinimum, const std::string& p_description);
	void supprimerCompte(int p_noCompte);
	void ajoutEpargne(int p_noCompte, double p_tauxInteret, double p_solde,
		const std::string& p_description);

public slots:
	void dialogAjoutCheque();
	void dialogSupprimerCompte();
	void dialogAjoutEpargne();

private:
	Ui::ClientGUIClass ui;
	banque::Client client;
};

#endif // CLIENTGUI_H
