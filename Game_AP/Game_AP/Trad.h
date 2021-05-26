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
    Trad();
    Trad (int , int , int , int , string);
    void fill();
    // void print(string) const;
    //void check_states( States state , Trad countries) const;
    vector<bool> check_states( States state );
    void print(vector<bool> &) ;
    void choosed(string , States&);
    bool checking_contry_name(string);
private:
    int money = 0 , satisfaction = 0, religion = 0, army = 0;
    string name;
    vector <Trad> country_list;
};

// #endif