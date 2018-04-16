/**
 * @file Epargne.h
 * @brief Interface de la classe Epargne pour le tp de GIF-1003
 * @author Mathieu Leger-Dalcourt
 * @date 12 avril 2018
 * @version 1.0
 */

#ifndef EPARGNE_H_
#define EPARGNE_H_

#include "Compte.h"

namespace banque
{
/**
 * @class Epargne
 * @brief Cette classe permet de modéliser des comptes epargnes.
 */
class Epargne: public Compte
{
public:
	Epargne(int p_noCompte, double p_tauxInteret, double p_solde,
			const std::string& p_description = "Epargne");

	virtual std::string reqCompteFormate() const;
	virtual double calculerInteret() const;
	virtual Epargne* clone() const;

private:
	void verifieInvariant() const;

};
}

#endif /* EPARGNE_H_ */
