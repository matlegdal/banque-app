/**
 * @file CompteException.cpp
 * @brief Implementation de la classe CompteException et de ses heritiers pour le tp de GIF-1003
 * @author Mathieu Leger-Dalcourt
 * @date 16 avril 2018
 * @version 1.0
 */

#include "CompteException.h"

namespace banque
{
/**
 * @brief Constructeur de la classe de base CompteException
 * @param p_raison chaine de caracteres representant la raison de l'erreur
 */
CompteException::CompteException(const std::string& p_raison)
	: runtime_error(p_raison)
{
}

/**
 * @brief Constructeur de la classe CompteDejaPresentException
 * @param p_raison chaine de caracteres representant la raison de l'erreur
 */
CompteDejaPresentException::CompteDejaPresentException(const std::string& p_raison)
	: CompteException(p_raison)
{
}

/**
 * @brief Constructeur de la classe CompteAbsentException
 * @param p_raison chaine de caracteres representant la raison de l'erreur
 */
CompteAbsentException::CompteAbsentException(const std::string& p_raison)
	: CompteException(p_raison)
{
}

} /* namespace banque */

