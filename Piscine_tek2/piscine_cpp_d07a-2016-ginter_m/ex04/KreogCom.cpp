/*
** KreogCom.cpp for ex02 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d07a-2016-ginter_m/ex02
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Jan 15 23:12:16 2013 maxime ginters
** Last update Tue Jan 15 23:12:16 2013 maxime ginters
*/

#include "KreogCom.h"

KreogCom::KreogCom(int x, int y, int serial) :
    _next(NULL), _x(x), _y(y), m_serial(serial)
{
    std::cout << "KreogCom " << m_serial << " initialised" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom* elem = new KreogCom(x, y, serial);
    if (!_next)
        _next = elem;
    else
    {
        elem->_next = _next;
        _next = elem;
    }
}

void Skat::addCom(KreogCom* elem)
{
    if (!elem)
        return;
    if (!_next)
        _next = elem;
    else
    {
        elem->_next = _next;
        _next = elem;
    }
}

KreogCom* KreogCom::getCom()
{
    return _next;
}

void KreogCom::removeCom()
{
    if (!_next)
        return;
    if (_next->_next)
    {
        KreogCom* tmp = _next;
        _next = _next->_next;
        delete tmp;
    }
    else
    {
        delete _next;
        _next = NULL;
    }
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << m_serial << " currently at " << _x << " " << _y << std::endl;
}

void KreogCom::locateSquad() const
{
    for (KreogCom* itr = _next; itr != NULL; itr = itr->getCom())
        itr->ping();
    ping();
}
