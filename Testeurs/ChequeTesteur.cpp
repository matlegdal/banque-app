/**
 * \file ChequeTesteur.cpp
 * \brief Testeur de la classe Cheque
 * \author Mathieu Leger-Dalcourt
 * \version 1.0
 * \date 2018-04-12
 */

#include <gtest/gtest.h>
#include <iostream>
#include "Compte.h"
#include "Cheque.h"

using namespace std;

/**
 * \brief Tests du constructeur avec paramètres valides
 *     Cas valides:  nombre de transactions inférieur ou égal à 40 et taux d'interet superieur
 *     ou egal au taux d'interet minimum
 */
TEST(Cheque, ConstructeurParametresValides)
{
	banque::Cheque cheque(12345, 1.3, 100.0, 20);
	ASSERT_EQ(12345, cheque.reqNoCompte());
	ASSERT_EQ(1.3, cheque.reqTauxInteret());
	ASSERT_EQ(100.0, cheque.reqSolde());
	ASSERT_EQ(20, cheque.reqNombreTransactions());
	ASSERT_EQ(0.1, cheque.reqTauxInteretMinimum());
	ASSERT_EQ("Cheque", cheque.reqDescription());
	ASSERT_EQ(util::Date(), cheque.reqDateOuverture());
}

/**
 * \brief Tests du constructeur avec paramètres invalides
 *     Cas invalide: nombre de transactions superieur à 40 et taux d'interet inferieur
 *     au taux d'interet minimum
 */
TEST(Cheque, ConstructeurParametresInvalides)
{
	ASSERT_THROW(banque::Cheque cheque(12345, 1.3, 100.0, 41), PreconditionException);
	ASSERT_THROW(banque::Cheque cheque(12345, 0.05, 100.0, 20), PreconditionException);
}

/**
 * \brief Test fixture pour les méthodes de la classe Cheque.
 */
class ChequeValide: public ::testing::Test
{
public:
	ChequeValide()
		: cheque(1, 1.5, 50.1, 13, 0.3)
	{
	}
	banque::Cheque cheque;
};

/**
 * \brief Test de la methode int reqNombreTransactions() const
 * 		Cas valide: verifier le retour
 */
TEST_F(ChequeValide, reqNombreTransactions)
{
	ASSERT_EQ(13, cheque.reqNombreTransactions());
}

/**
 * \brief Test de la methode double reqTauxInteretMinimum() const
 * 		Cas valide: verifier le retour
 */
TEST_F(ChequeValide, reqTauxInteretMinimum)
{
	ASSERT_EQ(0.3, cheque.reqTauxInteretMinimum());
}

/**
 * \brief Test de la methode virtual std::string reqCompteFormate() const
 * 		Cas valide: retourne une string formattee sous le format suivant:
 * Compte Cheque
 * Numero 				  : 1
 * Description 			  : Cheque
 * Date d'ouverture 	  : Mercredi le 07 mars 2018
 * Taux d'interet 		  : 1.5
 * Solde 				  : 50.1 $
 * Nombre de transactions : 13
 * Taux d'interet minimum : 0.3
 * Interet				  : 0 $
 */
TEST_F(ChequeValide, reqCompteFormate)
{
	ostringstream os;
	os << "Compte Cheque\n" << "numero                 : 1\n" << "Description            : Cheque\n"
		<< "Date d'ouverture       : " << cheque.reqDateOuverture().reqDateFormatee() << "\n"
		<< "Taux d'interet         : 1.5\n" << "Solde                  : 50.1 $\n"
		<< "Nombre de transactions : 13\n" << "Taux d'interet minimum : 0.3\n"
		<< "Interet                : 0 $";
	string resultatAttendu = os.str();

	ASSERT_EQ(resultatAttendu, cheque.reqCompteFormate());
}

/**
 * \brief Test de la methode void asgNombreTransactions(int p_nombreTransactions) avec param valide
 * 		Cas valide: nombre de transaction <= 40
 */
TEST_F(ChequeValide, asgNombreTransactionsValide)
{
	cheque.asgNombreTransactions(10);
	ASSERT_EQ(10, cheque.reqNombreTransactions());
}

/**
 * \brief Test de la methode void asgNombreTransactions(int p_nombreTransactions) avec param invalide
 * 		Cas invalide: nombre de transactions >40
 */
TEST_F(ChequeValide, asgNombreTransactionsInvalide)
{
	ASSERT_THROW(cheque.asgNombreTransactions(41), PreconditionException);
}

/**
 * \brief Test fixture pour le calcul des interets de la classe Cheque.
 */
class ChequeInteret: public ::testing::Test
{
public:
	ChequeInteret()
		: cheque(1, 5, -100, 0, 1)
	{
	}
	banque::Cheque cheque;
};

/**
 * \brief Test de la methode virtual double calculerInteret() const
 * 		cas valides: L’intérêt se calcule sur un solde négatif (si le solde est positif ou nul,
 * 			il n’y a pas d’intérêt à payer) de la manière suivante :
 * 		- entre 0 et jusqu’à 10 transactions, l’intérêt est payé au taux d’intérêt minimum.
 * 		- de 11 jusqu’à 25 transactions, l’intérêt est payé au taux d’intérêt du compte fois 40%.
 * 		- de 26 jusqu’à 35 transactions, l’intérêt est payé au taux d’intérêt du compte fois 80%.
 * 		- au-delà de 35 transactions, l’intérêt est payé au taux d’intérêt du compte
 */
TEST_F(ChequeInteret, calculerInteretSoldePositif)
{
	cheque.asgSolde(100);
	ASSERT_EQ(0, cheque.calculerInteret());
}
// Bracket minimale 0-10
TEST_F(ChequeInteret, calculerInteretMinimum)
{
	ASSERT_EQ(1, cheque.calculerInteret());
}
// Bracket moyenne 11-25
TEST_F(ChequeInteret, calculerInteretMedium)
{
	cheque.asgNombreTransactions(11);
	ASSERT_EQ(5*0.4, cheque.calculerInteret());
}
// Bracket elevee
TEST_F(ChequeInteret, calculerInteretEleve)
{
	cheque.asgNombreTransactions(26);
	ASSERT_EQ(5*0.8, cheque.calculerInteret());
}
// Bracket maximum
TEST_F(ChequeInteret, calculerInteretMaximum)
{
	cheque.asgNombreTransactions(36);
	ASSERT_EQ(5, cheque.calculerInteret());
}

/**
 * \brief Test fixture pour la méthode clone() de la classe Cheque.
 */
class ChequeClone: public ::testing::Test
{
public:
	ChequeClone()
		: cheque(1, 5, 100, 10, 1, "Clone")
	{
	}
	banque::Cheque cheque;
};

/**
 * \brief Test de la methode virtual Compte* clone() const
 * 		Cas valide: tous les attributs de la copie sont identiques, mais les adresses sont differentes
 */
TEST_F(ChequeClone, clone)
{
	banque::Cheque* clone;
	clone = cheque.clone();
	ASSERT_EQ(clone->reqNoCompte(), cheque.reqNoCompte());
	ASSERT_EQ(clone->reqTauxInteret(), cheque.reqTauxInteret());
	ASSERT_EQ(clone->reqSolde(), cheque.reqSolde());
	ASSERT_EQ(clone->reqNombreTransactions(), cheque.reqNombreTransactions());
	ASSERT_EQ(clone->reqTauxInteretMinimum(), cheque.reqTauxInteretMinimum());
	ASSERT_EQ(clone->reqDescription(), cheque.reqDescription());
	ASSERT_EQ(clone->reqDateOuverture(), cheque.reqDateOuverture());
	ASSERT_NE(clone, &cheque);
}


