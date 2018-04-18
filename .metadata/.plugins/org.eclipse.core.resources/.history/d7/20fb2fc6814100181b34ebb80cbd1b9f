/**
 * @file Epargne.cpp
 * @brief Implementation de la classe Epargne pour le tp de GIF-1003
 * @author Mathieu Leger-Dalcourt
 * @date 12 avril 2018
 * @version 1.0
 */

#include "Epargne.h"

namespace banque
{
/**
 * @brief Constructeur avec parametres
 * @param[in] p_noCompte est un entier positif qui represente le numero du compte
 * @param[in] p_tauxInteret d'interet est un double representant le taux d'interet du compte en pourcentage
 * @param[in] p_solde est un double representant le solde du compte
 * @param[in] p_description est une string donnant une description du compte. "Epargne" par defaut.
 * @pre p_tauxInteret est entre 0.1 et 3.5.
 */
Epargne::Epargne(int p_noCompte, double p_tauxInteret, double p_solde,
	const std::string& p_description)
	: Compte(p_noCompte, p_tauxInteret, p_solde, p_description)
{
	PRECONDITION(p_tauxInteret >= 0.1 && p_tauxInteret <= 3.5);
	INVARIANTS();
}

/**
 * @brief Presente les differentes informations du compte sous la forme suivante:
 * Compte Epargne
 * numero 			: 12345
 * Description 		: compte courant
 * Date d'ouverture : Mercredi le 07 mars 2018
 * Taux d'interet 	: 0.2
 * Solde 			: 3000 $
 * Interet			: 9 $
 * @return une string qui represente les informations du compte sous le format requis
 */
std::string Epargne::reqCompteFormate() const
{
	std::ostringstream os;
	os << "Compte Epargne\n" << Compte::reqCompteFormate() << "\n" << "Interet                : "
		<< calculerInteret() << " $";

	return os.str();
}

/**
 * @brief Permet de calculer le taux d'interet de maniere simpliste. Calcule de la maniere suivante:
 * Taux d'interet * Solde / 100
 * @return un double representant l'interet accumule sur le compte
 */
double Epargne::calculerInteret() const
{
	return reqTauxInteret() * reqSolde() / 100;
}

/**
 * @brief permet de faire une copie allouee sur le monceau de l'objet courant
 * @return un pointeur de l'objet copie
 */
Epargne* Epargne::clone() const
{
	return new Epargne(*this);
}

/**
 * @brief verifie les invariants de classe
 */
void Epargne::verifieInvariant() const
{
	INVARIANT(reqTauxInteret() >= 0.1);
	INVARIANT(reqTauxInteret() <= 3.5);
}
}
