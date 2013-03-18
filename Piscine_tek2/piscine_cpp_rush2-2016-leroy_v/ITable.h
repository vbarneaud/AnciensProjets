/*
** ITable.h for piscine_cpp_rush2-2016-leroy_v in /home/fest/Epitech/Piscine_tek2/piscine_cpp_rush2-2016-leroy_v
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Sat Jan 19 18:51:15 2013 maxime ginters
** Last update Sun Jan 20 02:37:22 2013 maxime ginters
*/

#ifndef ITABLE_H_
# define ITABLE_H_

#include <string>
#include "Object.h"

class ITable
{
public:
    virtual ~ITable() {}
    virtual Object* take(unsigned int mask) = 0;
    virtual void put(Object* obj) = 0;
    virtual std::string* Look() = 0;
};

#endif /* !ITABLE_H_ */
