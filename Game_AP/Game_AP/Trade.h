#pragma once
#define TRADE_H

#include <vector>
#include "States.h"
#include <iostream>
// #include "War.h"

using namespace std;

/**
 * @brief this class is for trade part in game
 * 
 */
// class War;
class States;
class Trade
{
friend void betryal(Trade &trade , States &war , int index);
public:
    Trade();
    Trade (int , int , int , int , string);
    Trade (int , int , int , int , string , int);
    void fill();
    //void print(string) const;
    //void check_states( States state , Trad countries) const;
    vector<bool> check_states( States state );
    void print(vector<bool> &) ;
    bool choosed(string , States& , int &);
    bool checking_contry_name(string , vector<bool>);
private:
    int money = 0 , satisfaction = 0, religion = 0, army = 0 , count_for_betray = 0;
    int betrayal_capasity;
    string name;
    vector <Trade> country_list;
};

// #endif