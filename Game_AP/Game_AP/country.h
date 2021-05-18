#ifndef COUNTRY_H
#define COUNTRY_H
#include <iostream>
// #include "Attack.h"
using namespace std;
/**
 * @file Country.h
 * 
 * @brief it is related to Attack class and this class specifies the changes of states
 * 
 */
class Country
{
friend class Attack;
private:
    string name;
    int money_ch;
    int satisfaction_ch;
    int religion_ch;
    int army_ch;
public:
    Country(string , int , int , int , int );
};

#endif