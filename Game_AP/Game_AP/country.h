#ifndef COUNTRY_H
#define COUNTRY_H
#include <iostream>
// #include "attack.h"
using namespace std;
/**
 * @file country.h
 * 
 * @brief it is related to attack class and this class specifies the changes of states
 * 
 */
// class attack;
class country
{
friend class attack;
private:
    string name;
    int money_ch;
    int stisfaction_ch;
    int religion_ch;
    int army_ch;
public:
    country(string , int , int , int , int );
};

#endif