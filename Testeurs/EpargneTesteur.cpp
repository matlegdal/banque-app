/**
 * \file EpargneTesteur.cpp
 * \brief Testeur de la classe Epargne
 * \author Mathieu Leger-Dalcourt
 * \version 1.0
 * \date 2018-04-12
 */

#include <gtest/gtest.h>
#include <iostream>
#include "Epargne.h"

using namespace std;

/**
 * \brief Tests du constructeur avec paramètres valides
 *     Cas valides:  taux d'interet entre 0.1 et 3.5
 */
TEST(Epargne, ConstructeurParametresValides)
{
	banque::Epargne epargne(12345, 1.3, 100.0);
	ASSERT_EQ(12345, epargne.reqNoCompte());
	ASSERT_EQ(1.3, epargne.reqTauxInteret());
	ASSERT_EQ(100.0, epargne.reqSolde());
	ASSERT_EQ("Epargne", epargne.reqDescription());
	ASSERT_EQ(util::Date(), epargne.reqDateOuverture());
}

/**
 * \brief Test du constructeur avec paramètres invalides
 *     Cas invalide: taux d'interet < 0.1 ou >3.5
 */
TEST(Epargne, ConstructeurParametresInvalides)
{
	ASSERT_THROW(banque::Epargne epargne(12345, 0.09, 100.0),
			PreconditionException);
	ASSERT_THROW(banque::Epargne epargne(12345, 3.51, 100.0),
			PreconditionException);
}

/**
 * \brief Test fixture pour les méthodes de la classe Epargne.
 */
class EpargneValide: public ::testing::Test
{
public:
	EpargneValide()
		: epargne(1, 3, 100)
	{
	}
	banque::Epargne epargne;
};

/**
 * \brief Test de la methode virtual std::string reqCompteFormate() const
 * 		Cas valide: retourne une string formattee sous le format suivant:
 * Compte Epargne
 * numero 			: 1
 * Description 		: Epargne
 * Date d'ouverture : Mercredi le 07 mars 2018
 * Taux d'interet 	: 3
 * Solde 			: 100 $
 * Interet			: 3 $
 */
TEST_F(EpargneValide, reqCompteFormate)
{
	ostringstream os;
	os << "Compte Epargne\n" << "numero                 : 1\n" << "Description            : Epargne\n"
		<< "Date d'ouverture       : " << epargne.reqDateOuverture().reqDateFormatee() << "\n"
		<< "Taux d'interet         : 3\n" << "Solde                  : 100 $\n"
		<< "Interet                : 3 $";
	string resultatAttendu = os.str();

	ASSERT_EQ(resultatAttendu, epargne.reqCompteFormate());
}

/**
 * \brief Test de la methode virtual double calculerInteret() const
 */
TEST_F(EpargneValide, calculerInteret)
{
	ASSERT_EQ(3, epargne.calculerInteret());
}

/**
 * \brief Test de la methode virtual Compte* clone() const
 * 		Cas valide: tous les attributs de la copie sont identiques, mais les adresses sont differentes
 */
TEST_F(EpargneValide, clone)
{
	banque::Epargne* clone;
	clone = epargne.clone();
	ASSERT_EQ(clone->reqNoCompte(), epargne.reqNoCompte());
	ASSERT_EQ(clone->reqTauxInteret(), epargne.reqTauxInteret());
	ASSERT_EQ(clone->reqSolde(), epargne.reqSolde());
	ASSERT_EQ(clone->reqDescription(), epargne.reqDescription());
	ASSERT_EQ(clone->reqDateOuverture(), epargne.reqDateOuverture());
	ASSERT_NE(clone, &epargne);
}




