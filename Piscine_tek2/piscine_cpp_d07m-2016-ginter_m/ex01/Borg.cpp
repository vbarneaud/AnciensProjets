/*
** Borg.cpp for ex01 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07m-2016-ginter_m/ex01
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 11:11:04 2013 maxime ginters
** Last update Tue Jan 15 11:11:04 2013 maxime ginters
*/

#include <iostream>
#include "Borg.hh"

namespace Borg
{

Ship::Ship() : _side(300), _maxWarp(9), _core(NULL)
{
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." <<std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

void Ship::setupCore(WarpSystem::Core* core)
{
    _core = core;
}

void Ship::checkCore()
{
    if (!_core || !_core->getReactor())
        return;
    std::cout << (_core->getReactor()->isStable() ? "Everything is in order." : "Critical failure imminent.") << std::endl;
}

} // !namespace Borg
