/*
** Box.cpp for SantaClaus in /home/vaga/Projects/tek2/piscine/rush2
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Sat Jan 19 17:38:51 2013 fabien casters
** Last update Sat Jan 19 22:00:14 2013 vincent leroy
*/

#include "Box.h"

Box::Box()
    : Wrap(TYPE_BOX, "Box de la mort qui tue")
{
}

void Box::wrapMeThat(Object *obj)
{
    if (obj == NULL)
    {
        std::cout << BOX_OBJ_EMPTY << std::endl;
        return ;
    }
    if (_obj != NULL)
    {
        std::cout << BOX_FULL << std::endl;
        return ;
    }
    if (!isOpen())
    {
        std::cout << BOX_CLOSE << std::endl;
        return ;
    }
    _obj = obj;
}
