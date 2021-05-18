#include "Country.h"

Country::Country(string name, int money_ch, int satisfaction_ch, int religion_ch, int army_ch)
{
    this->name = name;
    this->money_ch = money_ch;
    this->satisfaction_ch = satisfaction_ch;
    this->religion_ch = religion_ch;
    this->army_ch = army_ch;
}