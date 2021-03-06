/**
 * @file CompteException.h
 * @brief Interface de la classe CompteException et de ses heritiers pour le tp de GIF-1003
 * @author Mathieu Leger-Dalcourt
 * @date 16 avril 2018
 * @version 1.0
 */

#ifndef COMPTEEXCEPTION_H_
#define COMPTEEXCEPTION_H_

#include <string>
#include <stdexcept>

namespace banque
{
/**
 * @class CompteException
 * @brief Classe de base pour les exceptions de comptes
 */
class CompteException: public std::runtime_error
{
public:
	CompteException(const std::string& p_raison);
};

/**
 * @class CompteDejaPresentException
 * @brief Classe pour les erreurs d'ajout de comptes qui sont deja presents dans la liste des comptes du client
 */
class CompteDejaPresentException: public CompteException
{
public:
	CompteDejaPresentException(const std::string& p_raison);
};

/**
 * @class CompteAbsentException
 * @brief Classe pour les erreurs de suppressions de comptes qui sont absents de la liste des comptes du client
 */
class CompteAbsentException: public CompteException
{
public:
	CompteAbsentException(const std::string& p_raison);
};

} /* namespace banque */

#endif /* COMPTEEXCEPTION_H_ */
