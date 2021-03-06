/*
** AEnemy.cpp for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d10-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Fri Jan 18 13:52:03 2013 maxime ginters
** Last update Fri Jan 18 13:52:03 2013 maxime ginters
*/

#include "AEnemy.hh"

AEnemy::AEnemy(int hp, std::string const& type) :
    _hp(hp), _type(type)
{
}

std::string const& AEnemy::getType() const
{
    return _type;
}

int AEnemy::getHP() const
{
    return _hp;
}

void AEnemy::takeDamage(int damage)
{
    if (damage < 0)
        return;
    _hp -= damage;
}

