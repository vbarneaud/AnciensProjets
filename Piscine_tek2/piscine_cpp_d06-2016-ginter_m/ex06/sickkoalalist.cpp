/*
** sickkoalalist.cpp for ex05 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex05
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 15:49:41 2013 maxime ginters
** Last update Mon Jan 14 15:49:41 2013 maxime ginters
*/

#include "sickkoalalist.h"

SickKoalaList::SickKoalaList(SickKoala* koala) : _koala(koala), _next(NULL) {}

bool SickKoalaList::isEnd()
{
    return _next == NULL;
}

void SickKoalaList::append(SickKoalaList* elem)
{
    if (_next)
        _next->append(elem);
    else
        _next = elem;
}

SickKoala* SickKoalaList::getFromName(std::string name)
{
    if (_koala && _koala->getName() == name)
        return _koala;
    if (_next)
        return _next->getFromName(name);
    return NULL;
}

SickKoalaList * SickKoalaList::remove(SickKoalaList* node)
{
    if (!node)
        return this;
    if (node == this)
        return _next;
    else if (_next)
    {
        if (_next == node)
            _next = _next->getNext();
        else
            _next->remove(node);
    }
    return this;
}

SickKoalaList * SickKoalaList::removeFromName(std::string name)
{
    if (_koala && _koala->getName() == name)
        return _next;
    else if (_next)
    {
        if (_next->getContent() && _next->getContent()->getName() == name)
            _next = _next->getNext();
        else
            _next->removeFromName(name);
    }
    return this;
}

void SickKoalaList::dump()
{
    std::cout << "Liste des patients : ";
    for (SickKoalaList* itr = this; itr != NULL; itr = itr->getNext())
        std::cout << (itr == this ? "" : ", ") << (itr->getContent() ? itr->getContent()->getName() : "[NULL]");
    std::cout << "." << std::endl;
}

SickKoala* SickKoalaList::getContent()
{
    return _koala;
}

SickKoalaList* SickKoalaList::getNext()
{
    return _next;
}
