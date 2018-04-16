/**
 * \file CompteTesteur.cpp
 * \brief Testeur de la classe Compte
 * \author Mathieu Leger-Dalcourt
 * \version 1.0
 * \date 2018-04-12
 */

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Compte.h"

using namespace std;

/**
 * \class CompteDeTest
 * \brief Classe de test pour tester la classe abstraite Compte
 */
class CompteDeTest: public banque::Compte
{
public:
	CompteDeTest(int p_noCompte, double p_tauxInteret, double p_solde,
		const std::string &p_description)
		: Compte(p_noCompte, p_tauxInteret, p_solde, p_description)
	{
	}
	;
	virtual double calculerInteret() const
	{
		return 0.0;
	}
	;
	virtual Compte* clone() const
	{
		return 0;
	}
	;
	virtual ~CompteDeTest()
	{
	}
	;
};

/**
 * \brief Tests du constructeur avec paramètres valides
 *     Cas valides:  noCompte > 0 et description non-vide
 */
TEST(CompteDeTest, ConstructeurParametresValides)
{
	CompteDeTest compte(1, 5.0, 100.0, "description");
	ASSERT_EQ(1, compte.reqNoCompte());
	ASSERT_EQ(5.0, compte.reqTauxInteret());
	ASSERT_EQ(100.0, compte.reqSolde());
	ASSERT_EQ("description", compte.reqDescription());
	ASSERT_EQ(util::Date(), compte.reqDateOuverture());
}

/**
 * \brief Tests du constructeur avec paramètres invalides
 *     Cas invalide: noCompte <= 0 ou description vide
 */
TEST(Compte, ConstructeurParametresInvalides)
{
	ASSERT_THROW(CompteDeTest compte(-1, 5.0, 100.0, "description"), PreconditionException);
	ASSERT_THROW(CompteDeTest compte(1, 5.0, 100.0, ""), PreconditionException);
}

/**
 * \brief Test fixture pour les méthodes de la classe Compte.
 */
class CompteValide: public ::testing::Test
{
public:
	CompteValide()
		: compte(2, 2.5, 30.5, "Compte abstrait")
	{
	}
	CompteDeTest compte;
};

/**
 * \brief Test de la methode int reqNoCompte() const
 * 		Cas valide: verifier le retour
 */
TEST_F(CompteValide, reqNoCompte)
{
	ASSERT_EQ(2, compte.reqNoCompte());
}

/**
 * \brief Test de la methode double reqTauxInteret() const
 * 		Cas valide: verifier le retour
 */
TEST_F(CompteValide, reqTauxInteret)
{
	ASSERT_EQ(2.5, compte.reqTauxInteret());
}

/**
 * \brief Test de la methode double reqSolde() const
 * 		Cas valide: verifier le retour
 */
TEST_F(CompteValide, reqSolde)
{
	ASSERT_EQ(30.5, compte.reqSolde());
}

/**
 * \brief Test de la methode const std::string& reqDescription() const
 * 		Cas valide: verifier le retour
 */
TEST_F(CompteValide, reqDescription)
{
	ASSERT_EQ("Compte abstrait", compte.reqDescription());
}

/**
 * \brief Test de la methode const util::Date& reqDateOuverture() const
 * 		Cas valide: verifier le retour
 */
TEST_F(CompteValide, reqDateOuverture)
{
	ASSERT_EQ(util::Date(), compte.reqDateOuverture());
}

/**
 * \brief Test de la méthode asgTauxInteret(double p_tauxInteret).
 */
TEST_F(CompteValide, asgTauxInteret)
{
	compte.asgTauxInteret(10.0);
	ASSERT_EQ(10.0, compte.reqTauxInteret());
}

/**
 * \brief Test de la méthode asgSolde(double p_solde).
 */
TEST_F(CompteValide, asgSolde)
{
	compte.asgSolde(500);
	ASSERT_EQ(500, compte.reqSolde());
}

/**
 * \brief Test de la méthode asgDescription(const std::string& p_description) avec param valide.
 * 		Valide: p_description est non-vide.
 */
TEST_F(CompteValide, asgDescriptionValide)
{
	compte.asgDescription("une autre description");
	ASSERT_EQ("une autre description", compte.reqDescription());
}

/**
 * \brief Test de la méthode asgDescription(const std::string& p_description) avec parametre invalide
 * 		Non-valide: p_description est vide.
 */
TEST_F(CompteValide, asgDescriptionInvalide)
{
	ASSERT_THROW(compte.asgDescription(""), PreconditionException);
}

/**
 * \brief Test de la méthode virtual std::string reqCompteFormate() const
 * 		Cas valide : retourne une srting formattee de la facon suivante:
 * numero 			: 2
 * Description 		: Compte abstrait
 * Date d'ouverture : Mercredi le 07 mars 2018
 * Taux d'interet 	: 2.5
 * Solde 			: 30.5 $
 */
TEST_F(CompteValide, reqCompteFormate)
{
	ostringstream os;
	os << "numero                 : 2\n" << "Description            : Compte abstrait\n"
		<< "Date d'ouverture       : " << compte.reqDateOuverture().reqDateFormatee() << "\n"
		<< "Taux d'interet         : 2.5\n" << "Solde                  : 30.5 $";
	string resultatAttendu = os.str();
	ASSERT_EQ(resultatAttendu, compte.reqCompteFormate());
}

