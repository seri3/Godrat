#include "States.h"
#include <vector>
// #include "country.h"

#ifndef ATTACK_H
#define ATTACK_H

/**
 * @file attack.h
 * @brief it is for attack part in the game
 * 
 */


using namespace std;
class country;
class attack
{
private:
    vector <country> countries;

public:
    attack();
    void print();
    void after_attack(int index , States &state);
 
};

#endif



