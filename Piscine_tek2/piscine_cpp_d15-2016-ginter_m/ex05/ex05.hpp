/*
** ex05.hpp for ex05 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d15-2016-ginter_m/ex05
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 23 13:19:02 2013 maxime ginters
** Last update Thu Jan 24 08:11:32 2013 maxime ginters
*/

#ifndef EX05_H_
# define EX05_H_

#include <iostream>

template<class T>
class array
{
public:
    array() : _tab(NULL), _size(0) {}
    array(unsigned int n) : _tab(NULL), _size(n)
    {
        _tab = new T[_size];
    }
    array(array const& ar) : _tab(NULL), _size(ar._size)
    {
        _tab = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
            _tab[i] = ar._tab[i];
    }

    array& operator=(array const& ar)
    {
        _size = ar._size;
        delete[] _tab;
        _tab = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
            _tab[i] = ar._tab[i];
        return *this;
    }

    T& operator[](unsigned int index)
    {
        if (index >= _size)
        {
            T* _new = new T[index + 1];
            for (unsigned int i = 0; i < _size; ++i)
                _new[i] = _tab[i];
            delete[] _tab;
            _tab = _new;
            _size=  index + 1;
        }
        return _tab[index];
    }
    T const& operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::exception();
        return _tab[index];
    }

    unsigned int size() const
    {
        return _size;
    }

    void dump() const
    {
        std::cout << "[";
        for (unsigned int i = 0; i < _size; ++i)
            std::cout << _tab[i] << (i < _size - 1 ? ", " : "");
        std::cout << "]" << std::endl;
    }

    template<class U>
    array<U> convertTo(U (*convert)(T const& v)) const
    {
        array<U> ar(_size);
        for (unsigned int i = 0; i < _size; ++i)
            ar[i] = (*convert)(_tab[i]);
        return ar;
    }

private:
    T* _tab;
    unsigned int _size;
};

#endif /* !EX05_H_ */
