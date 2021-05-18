

#ifndef ATTACK_H
#define ATTACK_H
#include "States.h"
#include <vector>
#include "Country.h"

using namespace std;
// class Country;
/**
 * @file Attack.h
 * @brief it is for Attack part in the game and it contains list of countries
 * 
 */
class Attack
{
private:
    Country countries[2];
public:
    Attack();
    void print() const ;
    void after_attack(int index , States &state) const;
 
};

#endif



