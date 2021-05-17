#include "attack.h"
#include "country.h"
attack::attack()
:countries{country("china", 1, -3, 6, -2),country("india", -2, 2, 0, -4)}{}
//output: print list of enemy
void attack::print() const
{
    cout << "list of countries:" << endl;
    for (int i = 0; i < 2 ; i++)
    {
        cout << countries[i].name << endl;
    }
}

//chenging states after attack
void attack::after_attack(int index , States &state) const
{
    state.applyChanges(countries[index].money_ch , countries[index].satisfaction_ch ,countries[index].religion_ch , countries[index].army_ch );
}