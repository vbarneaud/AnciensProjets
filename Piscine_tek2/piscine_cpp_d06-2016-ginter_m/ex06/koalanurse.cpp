/*
** koalanurse.cpp for ex03 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d06-2016-ginter_m/ex03
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Mon Jan 14 13:33:42 2013 maxime ginters
** Last update Mon Jan 14 13:33:42 2013 maxime ginters
*/

#include <fstream>
#include "koalanurse.h"

KoalaNurse::KoalaNurse(int id) : _id(id), _working(false) {}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << _id << ": Enfin un peu de repos !" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala* koala)
{
    if (!koala)
        return;
    koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string file_name)
{
    std::string ext = ".report";
    if (file_name.length() < ext.length() || file_name.substr(file_name.length() - ext.length()) != ext)
        return std::string("");

    std::fstream file;
    file.open(file_name.c_str());
    if (!file.is_open())
        return std::string("");

    std::string drug;
    std::getline(file, drug);
    file.close();

    std::cout << "Nurse " << _id << ": Kreog ! Il faut donner un " << drug << " a Mr." << file_name.substr(0, file_name.find(".report")) << " !" << std::endl;
    return drug;
}

void KoalaNurse::timeCheck()
{
    if (_working)
        std::cout << "Nurse " << _id << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
    else
        std::cout << "Nurse " << _id << ": Je commence le travail !" << std::endl;
    _working = !_working;
}

int KoalaNurse::getID()
{
    return _id;
}
