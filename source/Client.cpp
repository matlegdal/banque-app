/**
 * @file Client.cpp
 * @brief Implementation de la classe Client pour le tp de GIF-1003
 * @author Mathieu Leger-Dalcourt
 * @date 16 avril 2018
 * @version 2.1
 */

#include "Client.h"

namespace banque
{
/**
 * @brief Constructeur avec parametres
 * @param[in] p_noFolio est un entier qui represente le numero de folio du client
 * @param[in] p_nom est une string qui represente le nom du client
 * @param[in] p_prenom est une string qui represente le prenom du client
 * @param[in] p_telephone est une string qui represente le numero de telephone du client
 * @param[in] p_dateNaissance est une Date qui represente la date de naissance du client
 * @pre le numero de folio est entre [1000, 10000[
 * @pre le nom et le prenom sont valides
 * @pre le numero de telephone est valide sous le format XXX 000-0000
 * @pre la date de naissance est entre [1973, 2037]
 * @post les parametres ont ete assignes correctement
 */
Client::Client(int p_noFolio, const std::string &p_nom, const std::string &p_prenom,
	const std::string &p_telephone, const util::Date& p_dateNaissance)
	: m_noFolio(p_noFolio), m_nom(p_nom), m_prenom(p_prenom), m_telephone(p_telephone), m_dateNaissance(
		p_dateNaissance)
{
	PRECONDITION(m_noFolio >= 1000 && m_noFolio < 10000);
	PRECONDITION(util::validerFormatNom(m_nom) && util::validerFormatNom(m_prenom));
	PRECONDITION(util::validerTelephone(m_telephone));
	PRECONDITION(m_dateNaissance.reqAnnee() >= 1970 && m_dateNaissance.reqAnnee() <= 2037);
	POSTCONDITION(
		m_noFolio == p_noFolio && m_nom == p_nom && m_prenom == m_prenom
			&& m_telephone == p_telephone && m_dateNaissance == p_dateNaissance);
	INVARIANTS();
}

/**
 * @brief Accesseur du numero de folio
 * @return un entier qui represente le numero de folio du client
 */
int Client::reqNoFolio() const
{
	return m_noFolio;
}

/**
 * @brief Accesseur du nom du client
 * @return une string qui represente le nom du client
 */
const std::string& Client::reqNom() const
{
	return m_nom;
}

/**
 * @brief Accesseur du prenom du client
 * @return une string qui represente le prenom du client
 */
const std::string& Client::reqPrenom() const
{
	return m_prenom;
}

/**
 * @brief Accesseur du numero de telephone du client
 * @return une string qui represente le numero de telephone du client
 */
const std::string& Client::reqTelephone() const
{
	return m_telephone;
}

/**
 * @brief Accesseur de la date d'ouverture du compte
 * @return une date de type util::Date qui represente la date d'ouverture du compte du client
 */
const util::Date& Client::reqDateNaissance() const
{
	return m_dateNaissance;
}

/**
 * @brief presente les differentes informations du client sous la forme suivante:
 * Client no de folio : 5000
 * Joe Blo
 * Date de naissance : Samedi le 12 mai 1979
 * 418 656-2131
 * @return une string qui represente les informations du clients avec le format requis
 */
std::string Client::reqClientFormate() const
{
	std::ostringstream os;
	os << "Client no de folio : " << m_noFolio << "\n" << m_prenom << " " << m_nom << "\n"
		<< "Date de naissance : " << m_dateNaissance.reqDateFormatee() << "\n" << m_telephone;
	return os.str();
}

/**
 * @brief Cette méthode parcourt tous les comptes du client et retourne dans une string
 * les informations sur ceux-ci. Retourne les infos du client suivi de tous ses comptes.
 * @return une string contenant les informations du client et de ses comptes avec le format requis
 */
std::string Client::reqReleves() const
{
	std::ostringstream os;
	os << reqClientFormate() << "\n";
	std::vector<Compte*>::const_iterator it;
	for (it = m_vComptes.begin(); it < m_vComptes.end(); it++)
	{
		os << (*it)->reqCompteFormate() << "\n";
	}
	return os.str();
}

/**
 * @brief Assignateur du numero de telephone
 * @param[in] p_telephone est une string qui represente le nouveau numero de telephone du client
 * @pre le numero de telephone est valide au format xxx 000-0000
 * @post le numero de telephone a ete modifie
 */
void Client::asgTelephone(const std::string &p_telephone)
{
	PRECONDITION(util::validerTelephone(p_telephone));
	m_telephone = p_telephone;
	POSTCONDITION(m_telephone == p_telephone);
	INVARIANTS();
}

/**
 * @brief Ajoute un compte a un client
 * @param p_nouveauCompte est un objet de type Compte a ajouter au client
 * @post le compte est ajoute a la liste des comptes du client
 * @throw CompteDejaPresentException si le compte a ajouter est deja present dans la liste des comptes du client
 */
void Client::ajouterCompte(const Compte& p_nouveauCompte)
{
	if (compteEstDejaPresent(p_nouveauCompte.reqNoCompte()))
	{
		throw CompteDejaPresentException(p_nouveauCompte.reqCompteFormate());
	}
	m_vComptes.push_back(p_nouveauCompte.clone());
	POSTCONDITION(compteEstDejaPresent(p_nouveauCompte.reqNoCompte()));
	INVARIANTS();
}

/**
 * @brief Supprime un compte de la liste des comptes d'un client
 * @param p_noCompte est un entier représentant le numero du compte a supprimer
 * @post le compte a ete supprime de la liste des comptes du client
 * @throw CompteAbsentException si le compte a supprimer n'est pas dans la liste des comptes du client
 */
void Client::supprimerCompte(int p_noCompte)
{
	bool estPresent = false;
	std::vector<Compte*>::iterator it;
	for (it = m_vComptes.begin(); it < m_vComptes.end(); it++)
	{
		if (p_noCompte == (*it)->reqNoCompte())
		{
			estPresent = true;
			delete (*it);
			m_vComptes.erase(it);
		}
	}

	if (!estPresent)
	{
		std::ostringstream os;
		os << "Le compte No " << p_noCompte << " est absent de la liste des comptes du client.";
		throw CompteAbsentException(os.str());
	}

	POSTCONDITION(!compteEstDejaPresent(p_noCompte));
	INVARIANTS();
}

/**
 * @brief surcharge de l'operateur ==. La comparaison se fait sur tous les attributs.
 * @param p_client qui est un client valide
 * @return un booleen qui represente si les deux clients sont égaux
 */
bool Client::operator==(const Client &p_client) const
{
	return m_noFolio == p_client.m_noFolio && m_nom == p_client.m_nom
		&& m_prenom == p_client.m_prenom && m_telephone == p_client.m_telephone
		&& m_dateNaissance == p_client.m_dateNaissance;
}

/**
 * @brief surcharge de l'operateur <. La comparaison se fait sur m_noFolio.
 * @param[in] p_client qui est un client valide
 * @return un booleen qui represente si le client a gauche a un plus petit numero de folio que le client de droite.
 */
bool Client::operator<(const Client &p_client) const
{
	return m_noFolio < p_client.m_noFolio;
}

/**
 * @brief Destructeur de Client. Desalloue la memoire des comptes du client.
 */
Client::~Client()
{
	std::vector<Compte*>::iterator it;
	for (it = m_vComptes.begin(); it < m_vComptes.end(); it++)
	{
		delete (*it);
	}
}

/**
 * @brief verifie si le client a deja un compte
 * @return vrai si le client possede un compte, faux sinon.
 */
bool Client::compteEstDejaPresent(int p_noCompte) const
{
	bool estPresent = false;
	std::vector<Compte*>::const_iterator it;
	for (it = m_vComptes.begin(); it < m_vComptes.end(); it++)
	{
		if (p_noCompte == (*it)->reqNoCompte())
		{
			estPresent = true;
			break;
		}
	}
	return estPresent;
}

/**
 * @brief verifie les invariants de classe
 */
void Client::verifieInvariant() const
{
	INVARIANT(m_noFolio >= 1000 && m_noFolio < 10000);
	INVARIANT(util::validerFormatNom(m_nom) && util::validerFormatNom(m_prenom));
	INVARIANT(util::validerTelephone(m_telephone));
	INVARIANT(m_dateNaissance.reqAnnee() >= 1970 && m_dateNaissance.reqAnnee() <= 2037);
}
}
