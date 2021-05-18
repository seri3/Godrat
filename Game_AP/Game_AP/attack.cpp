#include "Attack.h"
#include "Country.h"
Attack::Attack()
:countries{Country("china", 1, -3, 6, -2),Country("india", -2, 2, 0, -4)}{}
//output: print list of enemy
void Attack::print() const
{
    cout << "list of countries:" << endl;
    for (int i = 0; i < 2 ; i++)
    {
        cout << countries[i].name << endl;
    }
}

//chenging states after Attack
void Attack::after_attack(int index , States &state) const
{
    state.applyChanges(countries[index].money_ch , countries[index].satisfaction_ch ,countries[index].religion_ch , countries[index].army_ch );
}