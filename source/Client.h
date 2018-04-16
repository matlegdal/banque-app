/**
 * @file Client.h
 * @brief Interface de la classe Client pour le tp de GIF-1003
 * @author Mathieu Leger-Dalcourt
 * @date 16 avril 2018
 * @version 2.1
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include <vector>
#include <sstream>
#include "Date.h"
#include "validationFormat.h"
#include "Compte.h"
#include "CompteException.h"


namespace banque
{
/**
 * @class Client
 * @brief Cette classe permet de modéliser des clients d'une banque.
 * Un client a des informations personnelles et une liste de comptes de type Compte.
 */
class Client
{
public:
	Client(int p_noFolio, const std::string &p_nom, const std::string &p_prenom,
			const std::string &p_telephone, const util::Date& p_dateNaissance);

	int reqNoFolio() const;
	const std::string& reqNom() const;
	const std::string& reqPrenom() const;
	const std::string& reqTelephone() const;
	const util::Date& reqDateNaissance() const;
	std::string reqClientFormate() const;
	std::string reqReleves() const;

	void asgTelephone(const std::string &p_telephone);
	void ajouterCompte (const Compte& p_nouveauCompte);

	bool operator==(const Client &p_client) const;
	bool operator<(const Client &p_client) const;

	~Client();

private:
	int m_noFolio;
	std::string m_nom;
	std::string m_prenom;
	std::string m_telephone;
	util::Date m_dateNaissance;
	std::vector<Compte*> m_vComptes;

	bool compteEstDejaPresent(int p_noCompte) const;
	void verifieInvariant() const;

	// Methodes interdites - non implantees
	Client(const Client& p_client);
	const Client& operator= (const Client& p_client);
};
}

#endif /* CLIENT_H_ */
