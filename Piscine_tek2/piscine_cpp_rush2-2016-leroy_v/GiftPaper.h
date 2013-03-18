/*
** GiftPaper.h for  in /home/vaga/Projects/tek2/piscine/rush2
** 
** Made by fabien casters
** Login   <fabien.casters@epitech.eu>
** 
** Started on  Sat Jan 19 20:10:14 2013 fabien casters
** Last update Sun Jan 20 02:18:21 2013 fabien casters
*/

#ifndef GIFTPAPER_H_
# define GIFTPAPER_H_

#include <iostream>
#include <string>
#include "Wrap.h"
#include "Message.h"

class GiftPaper : public Wrap
{
 public:
    GiftPaper();
    bool isOpen() const;
    void wrapMeThat(Object *);
};

#endif

