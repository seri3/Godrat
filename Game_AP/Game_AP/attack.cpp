#include "attack.h"
#include "country.h"
attack::attack()
:countries{country("china", 1, 3, 6, 7),country("india", 7, 2, 0, 9)}
{
 
}
//print list of enemy
void attack::print()
{
    cout << "list of countries:" << endl;
    for (int i = 0; i < 2 ; i++)
    {
        cout << countries[i].name << endl;
    }
}

//chenging states after attack
void attack::after_attack(int index , States &state)
{
    state.applyChanges(countries[index].money_ch , countries[index].stisfaction_ch ,countries[index].religion_ch , countries[index].army_ch );
}