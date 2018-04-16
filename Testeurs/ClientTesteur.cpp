/**
 * \file ClientTesteur.cpp
 * \brief Testeur de la classe Client
 * \author Mathieu Leger-Dalcourt
 * \version 1.0
 * \date 2018-04-12
 */

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Client.h"
#include "Cheque.h"
#include "Epargne.h"

using namespace std;

/**
 * \brief Tests du constructeur avec paramètres valides
 *     Cas valides: no de folio entre [1000, 10000[, prenom, nom et telephone valides, date de
 *     naissance entre [1970, 2037]
 */
TEST(Client, ConstructeurParametresValides)
{
	banque::Client client(1000, "Dalcourt", "Mathieu", "819 640-1681", util::Date(8, 10, 1990));
	ASSERT_EQ(1000, client.reqNoFolio());
	ASSERT_EQ("Dalcourt", client.reqNom());
	ASSERT_EQ("Mathieu", client.reqPrenom());
	ASSERT_EQ("819 640-1681", client.reqTelephone());
	ASSERT_EQ(util::Date(8, 10, 1990), client.reqDateNaissance());
}

/**
 * \brief Tests du constructeur avec paramètres invalides
 *     Cas invalide: no de folio en dehors de [1000, 10000[, prenom, nom et telephone invalides, date
 *     de naissance en dehors de [1970, 2037] ou date invalide
 */
TEST(Client, ConstructeurParametresInvalides)
{
	// no folio invalide
	ASSERT_THROW(
		banque::Client client(10000, "Dalcourt", "Mathieu", "819 640-1681", util::Date(8, 10, 1990)),
		PreconditionException);
	ASSERT_THROW(
		banque::Client client(999, "Dalcourt", "Mathieu", "819 640-1681", util::Date(8, 10, 1990)),
		PreconditionException);
	ASSERT_THROW(
		banque::Client client(0, "Dalcourt", "Mathieu", "819 640-1681", util::Date(8, 10, 1990)),
		PreconditionException);
	ASSERT_THROW(
		banque::Client client(-1000, "Dalcourt", "Mathieu", "819 640-1681", util::Date(8, 10, 1990)),
		PreconditionException);

	// Nom, prenom ou telephone invalides
	ASSERT_THROW(
		banque::Client client(1000, "Leger-Dalcourt", "Mathieu", "819 640-1681", util::Date(8, 10, 1990)),
		PreconditionException);
	ASSERT_THROW(
		banque::Client client(1000, "Leger Dalcourt", "Marc-Antoine", "819 640-1681", util::Date(8, 10, 1990)),
		PreconditionException);
	ASSERT_THROW(
		banque::Client client(1000, "Leger Dalcourt", "Mathieu", "000 640-1681", util::Date(8, 10, 1990)),
		PreconditionException);
	ASSERT_THROW(
		banque::Client client(1000, "Leger Dalcourt", "Mathieu", "0006401681", util::Date(8, 10, 1990)),
		PreconditionException);

	// Dates invalides
	ASSERT_THROW(
		banque::Client client(1000, "Leger Dalcourt", "Mathieu", "819 640-1681", util::Date(31, 9, 1990)),
		PreconditionException);
	ASSERT_THROW(
		banque::Client client(1000, "Leger Dalcourt", "Mathieu", "819 640-1681", util::Date(30, 9, 1969)),
		PreconditionException);
	ASSERT_THROW(
		banque::Client client(1000, "Leger Dalcourt", "Mathieu", "819 640-1681", util::Date(30, 9, 2038)),
		PreconditionException);
}

/**
 * \brief Test fixture pour les méthodes de la classe Client.
 */
class ClientValide: public ::testing::Test
{
public:
	ClientValide()
		: client(1000, "Dalcourt", "Mathieu", "819 640-1681", util::Date(8, 10, 1990))
	{
	}
	banque::Client client;
};

/**
 * \brief Test de la methode int reqNoFolio() const
 * 		Cas valide: verifier le retour
 */
TEST_F(ClientValide, reqNoFolio)
{
	ASSERT_EQ(1000, client.reqNoFolio());
}

/**
 * \brief Test de la methode const std::string& reqNom() const
 * 		Cas valide: verifier le retour
 */
TEST_F(ClientValide, reqNom)
{
	ASSERT_EQ("Dalcourt", client.reqNom());
}

/**
 * \brief Test de la methode const std::string& reqPrenom() const
 * 		Cas valide: verifier le retour
 */
TEST_F(ClientValide, reqPrenom)
{
	ASSERT_EQ("Mathieu", client.reqPrenom());
}

/**
 * \brief Test de la methode const std::string& reqTelephone() const
 * 		Cas valide: verifier le retour
 */
TEST_F(ClientValide, reqTelephone)
{
	ASSERT_EQ("819 640-1681", client.reqTelephone());
}

/**
 * \brief Test de la methode const util::Date& reqDateNaissance() const
 * 		Cas valide: verifier le retour
 */
TEST_F(ClientValide, reqDateNaissance)
{
	ASSERT_EQ(util::Date(8, 10, 1990), client.reqDateNaissance());
}

/**
 * \brief Test de la methode std::string reqClientFormate() const
 * 		Cas valide: verifier le retour sous le format:
 * Client no de folio : 1000
 * Mathieu Dalcourt
 * Date de naissance : Samedi le 12 mai 1979
 * 819 640-1681
 */
TEST_F(ClientValide, reqClientFormate)
{
	ostringstream os;
	os << "Client no de folio : 1000\n" << "Mathieu Dalcourt\n" << "Date de naissance : "
		<< client.reqDateNaissance().reqDateFormatee() << "\n" << "819 640-1681";
	string resultatAttendu = os.str();
	ASSERT_EQ(resultatAttendu, client.reqClientFormate());
}

/**
 * \brief Test de la methode std::string reqReleves() const
 * 		Cas valide: verifier le retour sous le format requis
 */
TEST_F(ClientValide, reqReleves)
{
	banque::Epargne epargne(1, 3, 100);
	client.ajouterCompte(epargne);
	ostringstream os;
	os << "Client no de folio : 1000\n" << "Mathieu Dalcourt\n" << "Date de naissance : "
		<< client.reqDateNaissance().reqDateFormatee() << "\n" << "819 640-1681\n"
		<< "Compte Epargne\n" << "numero                 : 1\n"
		<< "Description            : Epargne\n" << "Date d'ouverture       : "
		<< epargne.reqDateOuverture().reqDateFormatee() << "\n" << "Taux d'interet         : 3\n"
		<< "Solde                  : 100 $\n" << "Interet                : 3 $\n";

	string resultatAttendu = os.str();
	ASSERT_EQ(resultatAttendu, client.reqReleves());
}

/**
 * \brief Test de la methode void asgTelephone(const std::string &p_telephone) avec param valide
 * 		Cas valide: telephone valide sous le format xxx 000-0000
 */
TEST_F(ClientValide, asgTelephoneParametreValide)
{
	client.asgTelephone("418 123-1234");
	ASSERT_EQ("418 123-1234", client.reqTelephone());
}
/**
 * \brief Test de la methode void asgTelephone(const std::string &p_telephone) avec param invalide
 * 		Cas invalide: telephone invalide selon la fonction verifierTelephone()
 */
TEST_F(ClientValide, asgTelephoneParametreInvalide)
{
	ASSERT_THROW(client.asgTelephone("4181231234"), PreconditionException);
}

/**
 * \brief Test de la surcharge de l'operateur ==
 * 		cas valides: true si 2 clients ont tous leurs attributs egaux et false si les attributs sont differents
 */
TEST_F(ClientValide, surchargeOperateurEgalite)
{
	banque::Client client2(1000, "Dalcourt", "Mathieu", "819 640-1681", util::Date(8, 10, 1990));
	ASSERT_TRUE(client == client2);
	banque::Client client3(1001, "x", "Mr", "418 123-1234", util::Date(1, 3, 1990));
	ASSERT_FALSE(client == client3);
}

/**
 * \brief Test de la surcharge de l'operateur <
 * 		cas valides: true : un client est inferieur si son no de folio est plus petit
 * 					 false: le no de folio est plus grand
 */
TEST_F(ClientValide, surchargeOperateurEgaliteInferieur)
{
	banque::Client client2(1001, "Dalcourt", "Mathieu", "819 640-1681", util::Date(8, 10, 1990));
	ASSERT_TRUE(client < client2);
	banque::Client client3(1000, "x", "Mr", "418 123-1234", util::Date(1, 3, 1990));
	ASSERT_FALSE(client < client3);
}

/**
 * \brief Test fixture pour les méthodes de gestion des comptes de la classe Client.
 */
class ClientGestionDesComptes: public ::testing::Test
{
public:
	ClientGestionDesComptes()
		: client(1000, "Dalcourt", "Mathieu", "819 640-1681", util::Date(8, 10, 1990))
	{
	}
	banque::Client client;
};

/**
 * \brief Test de la methode void ajouterCompte (const Compte& p_nouveauCompte) pour un compte cheque
 * 		Cas valide: le compte a un no de compte unique
 */
TEST_F(ClientGestionDesComptes, ajouterCompteChequeValide)
{
	banque::Cheque compteCheque(1, 1.3, 100.0, 20);
	ostringstream os;
	os << client.reqClientFormate() << "\n" << compteCheque.reqCompteFormate() << "\n";
	string resultatAttendu = os.str();

	client.ajouterCompte(compteCheque);
	ASSERT_EQ(resultatAttendu, client.reqReleves());
}

/**
 * \brief Test de la methode void ajouterCompte (const Compte& p_nouveauCompte) pour un compte epargne
 * 		Cas valide: le compte a un no de compte unique
 */
TEST_F(ClientGestionDesComptes, ajouterCompteEpargneValide)
{
	banque::Epargne compteEpargne(1, 2, 100);
	ostringstream os;
	os << client.reqClientFormate() << "\n" << compteEpargne.reqCompteFormate() << "\n";
	string resultatAttendu = os.str();

	client.ajouterCompte(compteEpargne);
	ASSERT_EQ(resultatAttendu, client.reqReleves());
}

/**
 * \brief Test de la methode void ajouterCompte (const Compte& p_nouveauCompte) avec un compte invalide
 * 		Cas Invalide: le no de compte a ajouter est deja present dans la liste des comptes du client
 */
TEST_F(ClientGestionDesComptes, ajouterCompteDejaPresent)
{
	banque::Cheque compteCheque(1, 1.3, 100.0, 20);
	client.ajouterCompte(compteCheque);
	ASSERT_THROW(client.ajouterCompte(banque::Epargne(1, 2, 100)),
		banque::CompteDejaPresentException);
}

/**
 * \brief Test de la methode void ajouterCompte (const Compte& p_nouveauCompte) pour l'ajout de plusieurs comptes valides
 * 		Cas valide: le compte a un no de compte unique
 */
TEST_F(ClientGestionDesComptes, ajouterPlusieursComptesValides)
{
	banque::Cheque compteCheque(1, 1.3, 100.0, 20);
	banque::Cheque compteSupplementaire(2, 1.3, 100.0, 20);
	ostringstream os;
	os << client.reqClientFormate() << "\n" << compteCheque.reqCompteFormate() << "\n"
		<< compteSupplementaire.reqCompteFormate() << "\n";
	string resultatAttendu = os.str();

	client.ajouterCompte(compteCheque);
	client.ajouterCompte(compteSupplementaire);
	ASSERT_EQ(resultatAttendu, client.reqReleves());
}

/**
 * \brief Test de la methode void supprimerCompte(int p_noCompte) pour un no de compte valide
 * 		Cas valide: le compte est present dans la liste
 */
TEST_F(ClientGestionDesComptes, supprimerCompteValide)
{
	banque::Cheque compteCheque(1, 1.3, 100.0, 20);
	client.ajouterCompte(compteCheque);

	ostringstream os;
	os << client.reqClientFormate() << "\n";
	string resultatAttendu = os.str();

	client.supprimerCompte(1);
	ASSERT_EQ(resultatAttendu, client.reqReleves());
}

/**
 * \brief Test de la methode void supprimerCompte(int p_noCompte) pour un no de compte invalide
 * 		Cas invalide: le compte est absent de la liste des comptes
 */
TEST_F(ClientGestionDesComptes, supprimerCompteAbsent)
{
	banque::Cheque compteCheque(1, 1.3, 100.0, 20);
	client.ajouterCompte(compteCheque);

	ASSERT_THROW(client.supprimerCompte(2), banque::CompteAbsentException);
}

/**
 * \brief Test de la methode void supprimerCompte(int p_noCompte) pour plusieurs suppressions
 */
TEST_F(ClientGestionDesComptes, supprimerPlusieursComptes)
{
	banque::Cheque compte1(1, 1.3, 100.0, 20);
	banque::Cheque compte2(2, 1.5, 500.0, 10);
	banque::Epargne compte3(3, 2, 200);

	client.ajouterCompte(compte1);
	client.ajouterCompte(compte2);
	client.ajouterCompte(compte3);

	client.supprimerCompte(1);
	client.supprimerCompte(3);

	ostringstream os;
	os << client.reqClientFormate() << "\n" << compte2.reqCompteFormate() << "\n";
	string resultatAttendu = os.str();

	ASSERT_EQ(resultatAttendu, client.reqReleves());
}

