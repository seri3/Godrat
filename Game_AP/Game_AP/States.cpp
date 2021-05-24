#include "States.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

States::States()
	: money(5), satisfaction(5), religion(5), army(5)
{
}

inline int States::converter(int a)
{
	if (a > 5)
		return ((a - 5) * (-1));
	return a;
}
void States::applyChanges(int money_changes, int satisfaction_changes, int religion_changes, int army_changes)
{
	int temp = money_changes + money;
	if (temp > 15)
		temp = 15;
	else if (temp < 0)
		temp = 0;
	money = temp;
	
	temp = satisfaction_changes + satisfaction;
	if (temp > 15)
		temp = 15;
	else if (temp < 0)
		temp = 0;
	satisfaction = temp;
	
	temp = religion_changes + religion;
	if (temp > 15)
		temp = 15;
	else if (temp < 0)
		temp = 0;
	religion = temp;
	
	temp = army_changes + army;
	if (temp > 15)
		temp = 15;
	else if (temp < 0)
		temp = 0;
	army = temp;
	
}
void States::readStatesOfAnswer(int index, int answer_option)
{
	ifstream input;
	int religion_changes, satisfaction_changes, army_changes, money_changes;
	switch (answer_option)
	{
	case 1:
	{
		input.open("../States_1.txt", ios::in);
		break;
	}
	case 2:
	{
		input.open("../States_2.txt", ios::in);
		break;
	}
	}
	if (!input)
	{
		cerr << "file hasnt opened yet" << endl;
	}
	input.seekg(index * 8 + index);
	input >> religion_changes >> satisfaction_changes >> army_changes >> money_changes;
	//cout << religion << '\t' << satisfaction << '\t' << army << '\t' << money << endl;
	applyChanges(converter(money_changes), converter(satisfaction_changes), converter(religion_changes), converter(army_changes));
}
bool States::reachedZero(){
	if(religion && money && satisfaction && army)
		return true;
	return false;
}
void States::Printer(int progress, int barWidth)
{
    cout << "[";
    for (int i = 0; i < barWidth; ++i)
    {
        if (i < progress)
            cout << "=";
        // else if (i == progress)
        //     cout << ">";
        else
            cout << " ";
    }
    cout << "] " << (int)(((double)(progress) / (double)(barWidth)) * 100) << "%"
         << "   ( " << setw(2) << progress << setw(1) << " / " << barWidth << " )" << endl;
}
void States::currentStatementPrint()
{
    cout << setw(15) << "Money" << setw(1) << " : ";
    Printer(money);
    cout << setw(15) << "Army" << setw(1) << " : ";
    Printer(army);
    cout << setw(15) << "Satisfaction" << setw(1) << " : ";
    Printer(satisfaction);
    cout << setw(15) << "Religion" << setw(1) << " : ";
    Printer(religion);
}
bool States::war_validation()
{
	return States::Checking_The_States_For_Starting_The_War(money, satisfaction, army);
}
void States::spy()
{
	States::Print_NameOfCountries();
	States::Spyinformation();
}
void States::ApplyWar(int country)
{
	States::Changingstates(country, religion, satisfaction, army, money);
	currentStatementPrint();
}
void States::Show_MnifestedCountries()
{
	States::Manifested_countires();
}
void States::ShowCountries()
{
	Print_NameOfCountries();
}