/**
 * @file Cheque.cpp
 * @brief Implementation de la classe Cheque pour le tp de GIF-1003
 * @author Mathieu Leger-Dalcourt
 * @date 12 avril 2018
 * @version 1.0
 */

#include "Cheque.h"
#include <cmath>

namespace banque
{
/**
 * @brief Constructeur avec parametres
 * @param[in] p_noCompte est un entier positif qui represente le numero du compte
 * @param[in] p_tauxInteret d'interet est un double representant le taux d'interet du compte en pourcentage
 * @param[in] p_solde est un double representant le solde du compte
 * @param[in] p_nombreTransactions est un int representant le nombre de transactions du compte
 * @param[in] p_tauxInteretMinimum est un double representant le taux d'interet minimum du compte. 0.1 par defaut
 * @param[in] p_description est une string donnant une description du compte. "Cheque" par defaut.
 * @pre p_tauxInteret est plus grand ou egal a p_tauxInteretMinimum
 * @pre p_nombreTransactions est inferieur a 40
 * @post les parametres ont ete assignes correctement
 */
Cheque::Cheque(int p_noCompte, double p_tauxInteret, double p_solde, int p_nombreTransactions,
	double p_tauxInteretMinimum, const std::string& p_description)
	: Compte(p_noCompte, p_tauxInteret, p_solde, p_description), m_nombreTransactions(
		p_nombreTransactions), m_tauxInteretMinimum(p_tauxInteretMinimum)
{
	PRECONDITION(p_tauxInteret >= p_tauxInteretMinimum);
	PRECONDITION(p_nombreTransactions <= 40);
	POSTCONDITION(
		m_nombreTransactions == p_nombreTransactions
			&& m_tauxInteretMinimum == p_tauxInteretMinimum);
	INVARIANTS();
}

/**
 * @brief Accesseur du nombre de transactions
 * @return un entier qui represente le nombre de transactions
 */

int Cheque::reqNombreTransactions() const
{
	return m_nombreTransactions;
}

/**
 * @brief Accesseur du taux d'interet minimum
 * @return un double qui represente le taux d'interet minimum du compte
 */

double Cheque::reqTauxInteretMinimum() const
{
	return m_tauxInteretMinimum;
}

/**
 * @brief Presente les differentes informations du compte sous la forme suivante:
 * Compte Cheque
 * Numero 				  : 12345
 * Description 			  : compte courant
 * Date d'ouverture 	  : Mercredi le 07 mars 2018
 * Taux d'interet 		  : 0.2
 * Solde 				  : 3000 $
 * Nombre de transactions : 18
 * Taux d'interet minimum : 0.1
 * Interet				  : 9 $
 * @return une string qui represente les informations du compte sous le format requis
 */

std::string Cheque::reqCompteFormate() const
{
	std::ostringstream os;
	os << "Compte Cheque\n" << Compte::reqCompteFormate() << "\n" << "Nombre de transactions : "
		<< reqNombreTransactions() << "\n" << "Taux d'interet minimum : " << reqTauxInteretMinimum()
		<< "\n" << "Interet                : " << calculerInteret() << " $";

	return os.str();
}

/**
 * @brief Assignateur du nombre de transactions du compte
 * @param[in] p_nombreTransactions est un entier qui represente le nouveau nombre de transactions
 * @pre p_nombreTransactions est inférieur ou égal à 40
 * @post verification de l'assignation correcte du parametre d'entree
 */

void Cheque::asgNombreTransactions(int p_nombreTransactions)
{
	PRECONDITION(p_nombreTransactions <= 40);
	m_nombreTransactions = p_nombreTransactions;
	POSTCONDITION(m_nombreTransactions == p_nombreTransactions);
	INVARIANTS();
}

/**
 * @brief Permet de calculer le taux d'interet de la maniere suivante:
 * L’intérêt se calcule sur un solde négatif (si le solde est positif ou nul, il n’y a pas d’intérêt à payer) de la manière suivante :
 * - entre 0 et jusqu’à 10 transactions, l’intérêt est payé au taux d’intérêt minimum.
 * - de 11 jusqu’à 25 transactions, l’intérêt est payé au taux d’intérêt du compte fois 40%.
 * - de 26 jusqu’à 35 transactions, l’intérêt est payé au taux d’intérêt du compte fois 80%.
 * - au-delà de 35 transactions, l’intérêt est payé au taux d’intérêt du compte;
 * @return un double representant l'interet a payer sur le compte
 */

double Cheque::calculerInteret() const
{
	double interet = 0.0;
	if (reqSolde() < 0)
	{
		if (reqNombreTransactions() < 11)
		{
			interet = reqTauxInteretMinimum();
		}
		else if (reqNombreTransactions() < 26)
		{
			interet = reqTauxInteret() * 0.4;
		}
		else if (reqNombreTransactions() < 36)
		{
			interet = reqTauxInteret() * 0.8;
		}
		else
		{
			interet = reqTauxInteret();
		}
	}
	return std::abs(interet * reqSolde() / 100);
}

/**
 * @brief permet de faire une copie allouee sur le monceau de l'objet courant
 * @return un pointeur de l'objet copie
 */
Cheque* Cheque::clone() const
{
	return new Cheque(*this);
}

/**
 * @brief verifie les invariants de classe
 */
void Cheque::verifieInvariant() const
{
	INVARIANT(reqTauxInteret() >= reqTauxInteretMinimum());
	INVARIANT(reqNombreTransactions() <= 40);
}
}
