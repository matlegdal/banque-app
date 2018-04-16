/**
 * @file validationFormat.cpp
 * @brief Implantation des methodes de validation de format pour le tp de GIF-1003
 * @author Mathieu Leger-Dalcourt
 * @date 14 fevrier 2018
 * @version 1.2
 */

#include <vector>
#include <sstream>
#include "validationFormat.h"
#include "Date.h"

using namespace std;

namespace util
{
/**
 * @brief 1ere implémentation basique. Ne tient pas compte de la locale, donc les accents causent problème.
 * Vérifie que le nom contient uniquement des lettres ou des espaces.
 * @param [in] p_nom - Le nom a valider
 * @return bool - Vrai si le nom est valide, faux sinon
 */
    bool validerFormatNom(const std::string &p_nom)
    {
        bool estValide = false;

        if (!p_nom.empty())
        {
            bool charValides = true;
            for (string::size_type i = 0; i < p_nom.length(); ++i)
            {
                if (!isalpha(p_nom[i]) && !isspace(p_nom[i]))
                    charValides = false;
            }

            if (charValides)
            {
                estValide = true;
            }
        }

        return estValide;
    }

/**
 * @brief Valide le numero de telephone sous le format standard canadien XXX 000-0000 ou XXX est
 * un indicatif valide de la liste des indicatifs canadiens
 * @param [in] p_telephone - Le numero de telephone a valider
 * @return bool - Vrai si le numero est valide, faux sinon
 */
    bool validerTelephone(const std::string &p_telephone)
    {
        // Indicatifs régionaux canadiens valides
        const string INDICATIFS[] =
                { "403", "780", "604", "236", "250", "778", "902", "204", "506", "902",
                  "905", "519", "289", "705", "613", "807", "416", "647", "438",
                  "514", "450", "579", "418", "581", "819", "306", "709", "867",
                  "867", "800", "866", "877", "888", "855", "900", "976" };

        bool estValide = false;

        if (p_telephone.length() == 12)
        {
            if (p_telephone[3] == ' ' && p_telephone[7] == '-')
            {

                string indicatif = p_telephone.substr(0, 3);

//            Valide que le numéro est composé uniquement de chiffres 0-9
                stringstream chiffresStream;
                chiffresStream << indicatif << p_telephone.substr(4, 3)
                               << p_telephone.substr(8);
                string chiffres = chiffresStream.str();

                bool chiffresValides = true;
                for (int i = 0; i < 10; ++i)
                {
                    if (chiffres[i] < '0' || chiffres[i] > '9')
                    {
                        chiffresValides = false;
                    }
                }

//            Valide que l'indicatif fait partie de la liste des indicatifs possibles
                if (chiffresValides)
                {
                    const int NOMBRE_INDICATIFS = sizeof(INDICATIFS)
                                                  / sizeof(*INDICATIFS);
                    bool match = false;
                    for (int i = 0; i < NOMBRE_INDICATIFS; ++i)
                    {
                        if (indicatif == INDICATIFS[i])
                        {
                            match = true;
                        }
                    }

                    if (match)
                    {
                        estValide = true;
                    }
                }
            }
        }

        return estValide;
    }

/**
 * @brief Valide un fichier texte qui contient des informations bancaires sous la forme desiree:
 * nom
 * prenom
 * date de naissance sous la forme (jj mm aaaa)
 * telephone
 * numero de folio
 * type de compte (cheque ou epargne)
 * selon le type de compte (5 lignes pour epargne et 6 lignes pour cheque)
 * @param [in] p_is - Un flux d'entree de type istringstream
 * @return bool - Vrai si le fichier est au bon format et que les entrees sont valides, faux sinon
 */
    bool validerFormatFichier(std::istream &p_is)
    {
        bool estValide = false;
        vector<string> lignes;

        for (char buffer[256]; p_is.getline(buffer, 255);)
        {
            lignes.push_back(buffer);
        }

        if (lignes.size() >= 6)
        {
            if (validerFormatNom(lignes[0]))
            {
                if (validerFormatNom(lignes[1]))
                {
                    istringstream iss(lignes[2]);
                    int jour = -1;
                    int mois = -1;
                    int annee = -1;
                    iss >> jour >> mois >> annee;

                    if (util::Date::validerDate(jour, mois, annee))
                    {
                        if (validerTelephone(lignes[3]))
                        {
                            const int LIGNE_DEPART_COMPTES = 5;
                            const int NOMBRE_LIGNES_CHEQUE = 6;
                            const int NOMBRE_LIGNES_EPARGNE = 5;

                            unsigned int numeroLigne = LIGNE_DEPART_COMPTES;
                            bool comptesValides = true;

                            while (numeroLigne < lignes.size() && comptesValides)
                            {
                                if (lignes[numeroLigne] == "cheque")
                                {
                                    numeroLigne += NOMBRE_LIGNES_CHEQUE + 1;
                                }
                                else if (lignes[numeroLigne] == "epargne")
                                {
                                    numeroLigne += NOMBRE_LIGNES_EPARGNE + 1;
                                }
                                else
                                {
                                    comptesValides = false;
                                }
                            }

                            if (comptesValides && numeroLigne == lignes.size())
                            {
                                estValide = true;
                            }
                        }
                    }
                }
            }
        }

        return estValide;
    }
}
