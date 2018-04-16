/**
 * @file Compte.cpp
 * @brief Implementation de la classe Compte pour le tp de GIF-1003
 * @author Mathieu Leger-Dalcourt
 * @date 12 avril 2018
 * @version 1.0
 */

#include "Compte.h"

namespace banque
{
/**
 * @brief Constructeur avec parametres
 * @param[in] p_noCompte est un entier positif qui represente le numero du compte
 * @param[in] p_tauxInteret d'interet est un double representant le taux d'interet du compte en pourcentage
 * @param[in] p_solde est un double representant le solde du compte
 * @param[in] p_description est une string donnant une description du compte
 * @pre p_noCompte est positif
 * @pre p_description n'est pas vide
 * @post verification de l'assignation des parametres d'entre
 */
Compte::Compte(int p_noCompte, double p_tauxInteret, double p_solde,
	const std::string &p_description)
	: m_noCompte(p_noCompte), m_tauxInteret(p_tauxInteret), m_solde(p_solde), m_description(
		p_description), m_dateOuverture(util::Date())
{
	PRECONDITION(m_noCompte > 0 && m_description != "");
	POSTCONDITION(
		m_noCompte == p_noCompte && m_tauxInteret == p_tauxInteret && m_solde == p_solde
			&& m_description == p_description);
	INVARIANTS();
}

/**
 * @brief Accesseur du numero de compte
 * @return un entier qui represente le numero de compte
 */
int Compte::reqNoCompte() const
{
	return m_noCompte;
}

/**
 * @brief Accesseur du taux d'interet
 * @return un double qui represente le taux d'interet du compte
 */
double Compte::reqTauxInteret() const
{
	return m_tauxInteret;
}

/**
 * @brief Accesseur du solde du compte
 * @return un double qui represente le solde du compte
 */
double Compte::reqSolde() const
{
	return m_solde;
}

/**
 * @brief Accesseur de la description du compte
 * @return une reference constante d'une string qui represente la description du compte
 */
const std::string& Compte::reqDescription() const
{
	return m_description;
}

/**
 * @brief Accesseur de la date d'ouverture du compte
 * @return une reference constante d'un objet Date
 */
const util::Date& Compte::reqDateOuverture() const
{
	return m_dateOuverture;
}

/**
 * @brief Assignateur du taux d'interet du compte
 * @param[in] p_tauxInteret est un double qui represente le nouveau taux d'interet du compte
 * @post verification de l'assignation correcte du parametre d'entre
 */
void Compte::asgTauxInteret(double p_tauxInteret)
{
	m_tauxInteret = p_tauxInteret;
	POSTCONDITION(m_tauxInteret == p_tauxInteret);
	INVARIANTS();
}

/**
 * @brief Assignateur du solde du compte
 * @param[in] p_solde est un double qui represente le nouveau solde du compte
 * @post verification de l'assignation correcte du parametre d'entre
 */
void Compte::asgSolde(double p_solde)
{
	m_solde = p_solde;
	POSTCONDITION(m_solde == p_solde);
	INVARIANTS();
}

/**
 * @brief Assignateur de la description du compte
 * @param[in] p_description est un string qui represente la nouvelle description du compte
 * @pre p_description n'est pas vide.
 * @post verification de l'assignation correcte du parametre d'entre
 */
void Compte::asgDescription(const std::string& p_description)
{
	PRECONDITION(p_description != "");
	m_description = p_description;
	POSTCONDITION(m_description == p_description);
	INVARIANTS();
}

/**
 * @brief Presente les differentes informations du compte sous la forme suivante:
 * numero 			: 12345
 * Description 		: compte courant
 * Date d'ouverture : Mercredi le 07 mars 2018
 * Taux d'interet 	: 0.2
 * Solde 			: 3000 $
 * @return une string qui represente les informations du compte sous le format requis
 */
std::string Compte::reqCompteFormate() const
{
	std::ostringstream os;
	os << "numero                 : " << m_noCompte << "\n" << "Description            : "
		<< m_description << "\n" << "Date d'ouverture       : " << m_dateOuverture.reqDateFormatee()
		<< "\n" << "Taux d'interet         : " << m_tauxInteret << "\n"
		<< "Solde                  : " << m_solde << " $";

	return os.str();
}

/**
 * @brief verifie les invariants de classe
 */
void Compte::verifieInvariant() const
{
	INVARIANT(m_noCompte >= 0);
	INVARIANT(m_description != "");
}
}
