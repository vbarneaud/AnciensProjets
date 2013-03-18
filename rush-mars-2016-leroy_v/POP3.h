/*
** POP3.h for rush-mars-2016-leroy_v in /home/leroy_v/Epitech/projet_tek2/bmail/rush-mars-2016-leroy_v
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Sat Mar 09 17:19:20 2013 vincent leroy
** Last update Sun Mar 10 13:46:33 2013 fabien casters
*/

#ifndef POP3_H_
# define POP3_H_

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "AReceveur.h"

namespace Protocol
{

class POP3 : public AReceveur
{
    public:
        explicit POP3();
        virtual ~POP3();

        bool login(const std::string &, const std::string &) const;
        std::list<std::string> getFolders() const;
        std::list<std::vector<std::string> > getMails(const std::string &) const;
        std::string getMail(const std::string &) const;
        std::string getHeader(const std::string &key, const std::string &content) const;
        void removeMail(const std::string&) const;
};

}

#endif /* !POP3_H_ */
