

#ifndef ATTACK_H
#define ATTACK_H
#include "States.h"
#include <vector>

#include "country.h"
/**
 * @file attack.h
 * @brief it is for attack part in the game
 * 
 */


using namespace std;
// class country;
class attack
{
private:
    // vector <country> countries;
    country countries[2];
public:
    attack();
    void print();
    void after_attack(int index , States &state);
 
};

#endif



