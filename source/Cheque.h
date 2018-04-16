/**
 * @file Cheque.h
 * @brief Interface de la classe Cheque pour le tp de GIF-1003
 * @author Mathieu Leger-Dalcourt
 * @date 12 avril 2018
 * @version 1.0
 */

#ifndef CHEQUE_H_
#define CHEQUE_H_

#include "Compte.h"

namespace banque
{
/**
 * @class Cheque
 * @brief Cette classe permet de modéliser des comptes cheques.
 */
class Cheque: public Compte
{
public:
	Cheque(int p_noCompte, double p_tauxInteret, double p_solde,
			int p_nombreTransactions, double p_tauxInteretMinimum = 0.1,
			const std::string& p_description = "Cheque");

	int reqNombreTransactions() const;
	double reqTauxInteretMinimum() const;
	virtual std::string reqCompteFormate() const;

	void asgNombreTransactions(int p_nombreTransactions);

	virtual double calculerInteret() const;
	virtual Cheque* clone() const;

private:
	void verifieInvariant() const;

	int m_nombreTransactions;
	double m_tauxInteretMinimum;

};
}
#endif /* CHEQUE_H_ */
