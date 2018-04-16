/**
 * @file validationFormat.h
 * @brief Interface des methodes de validation de format pour le tp de GIF-1003
 * @author Mathieu Leger-Dalcourt
 * @date 14 fevrier 2018
 * @version 1.2
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <iosfwd>

namespace util
{
    bool validerFormatNom(const std::string &p_nom);

    bool validerTelephone(const std::string &p_telephone);

    bool validerFormatFichier(std::istream &p_is);
}

#endif /* VALIDATIONFORMAT_H_ */
