// #ifdef TRAD_H
#define TRAD_H

#include <vector>
#include "States.h"
#include <iostream>

using namespace std;

/**
 * @brief this class is for trad part of game
 * 
 */
class Trad
{
public:
    Trad (int , int , int , int , string);
    void fill();
    void print(string) const;
    string Trad::check_states(bool &checking , States state , Trad countries) const;
private:
    int money = 0 , satisfaction = 0, religion = 0, army = 0;
    string name;
    vector <Trad> country_list;
};

// #endif