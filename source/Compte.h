/**
 * @file Compte.h
 * @brief Interface de la classe Compte pour le tp de GIF-1003
 * @author Mathieu Leger-Dalcourt
 * @date 12 avril 2018
 * @version 1.0
 */

#ifndef COMPTE_H_
#define COMPTE_H_

#include <iostream>
#include <string>
#include <sstream>
#include "ContratException.h"
#include "Date.h"

namespace banque
{
/**
 * @class Compte
 * @brief Classe abstraite qui permet de modéliser des comptes de clients d'une banque.
 */
class Compte
{
public:
	Compte(int p_noCompte, double p_tauxInteret, double p_solde,
			const std::string &p_description);

	int reqNoCompte() const;
	double reqTauxInteret() const;
	double reqSolde() const;
	const std::string& reqDescription() const;
	const util::Date& reqDateOuverture() const;

	void asgTauxInteret(double p_tauxInteret);
	void asgSolde(double p_solde);
	void asgDescription(const std::string& p_description);

	virtual std::string reqCompteFormate() const;
	virtual ~Compte (){};

	virtual double calculerInteret() const =0;
	virtual Compte* clone() const =0;


private:
	void verifieInvariant() const;

	int m_noCompte;
	double m_tauxInteret;
	double m_solde;
	std::string m_description;
	util::Date m_dateOuverture;

};
}

#endif /* COMPTE_H_ */
