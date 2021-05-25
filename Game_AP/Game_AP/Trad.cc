//#ifdef TRAD_CC
#define TRAD_CC

#include <iostream>
#include <vector>
#include "Trad.h"

using namespace std;

Trad::Trad (int money , int staisfaction , int religion , int army , string name)
{
    this->money = money;
    this->army = army;
    this->satisfaction = staisfaction;
    this->religion = religion;
    this-> name = name;
}

//this function fill the country list
void Trad::fill()
{
    Trad korax( -3 , 0 , +3 , 0 , "Korax");
    country_list.push_back(korax);
    Trad Lev(-3 , 0 , 0 , +3 , "Lev");
    country_list.push_back(Lev);
    Trad Zirex(+3 , 0 , -3 , 0 , "Zirex");
    country_list.push_back(Zirex);
    Trad Dora(+3 , 0 , 0 , -3 , "Dorax");
}
//print the list of countries
void Trad::print( string state_low) const
{
    for (int i = 0; i < country_list.size(); i++)
    {
        cout << country_list[i].name << endl;
        if (country_list[i].money > 0 && state_low == "money")
        {
            cout << "This county will give " << country_list[i].money << "$ money";
            for (int j = 0; j < country_list.size(); j++)
            {
                if (country_list[j].army < 0)
                {
                    cout << "but it wants " << country_list[i].army << endl ;
                }
                else if (country_list[j].religion < 0)
                {
                    cout << "but it will adevrtise its religion" << endl;
                }
            }
        }
        if (country_list[i].army > 0 && state_low == "army")
        {
            cout << "This county will give " << country_list[i].army << " army";
            for (int j = 0; j < country_list.size(); j++)
            {
                if (country_list[j].money < 0)
                {
                    cout << "but it wants " << country_list[i].money << "$" <<endl ;
                }
            }
        }
        if (country_list[i].religion > 0 && state_low == "religion")
        {
            cout << "This county build  " << country_list[i].religion << " mosque";
            for (int j = 0; j < country_list.size(); j++)
            {
                if (country_list[j].army < 0)
                {
                    cout << "but it wants " << country_list[i].army << endl ;
                }
                else if (country_list[j].religion < 0)
                {
                    cout << "but it will adevrtise its religion" << endl;
                }
            }
        }
        
        
    }
}

//if one states get lower than 3 this function will find out and start the operation
string Trad::check_states(bool &checking , States state , Trad countries) const
{
    if (state.money <= 3 )
    {
        //TODO check the input
        string choose;
        //when the state ower than was found state low will initialise
        string state_low;
        cout << "Visier: castel don't have any money you have to trad with some countries do you want to?" << endl;
        cout << "yes" << endl << "no" << endl;
        cin >> choose;
        if (choose == "1")
        {
            state_low = "money";
            countries.print(state_low);
        }
        else if(choose == "2")
        {
            cout << "what ever you wnat your majesty." << endl;
        }
    }
    else if ( state.army <= 3 )
    {
        //TODO check the input
        string choose;
        //when the state ower than was found state low will initialise
        string state_low;
        cout << "Visier: castel don't have any army you have to give army from other countries do you want to?" << endl;
        cout << "yes" << endl << "no" << endl;
        cin >> choose;
        if (choose == "1")
        {
            state_low = "army";
            countries.print(state_low);
        }
        else if(choose == "2")
        {
            cout << "what ever you wnat your majesty." << endl;
        }
    }
    else if ( state.religion <= 3 )
    {
        //TODO check the input
        string choose;
        //when the state ower than was found state low will initialise
        string state_low;
        cout << "Visier: peaple are leaving the religion you don't want to do any thing?" << endl;
        cout << "yes" << endl << "no" << endl;
        cin >> choose;
        if (choose == "1")
        {
            state_low = "religion";
            countries.print(state_low);
        }
        else if(choose == "2")
        {
            cout << "what ever you wnat your majesty." << endl;
        }
    }
}





//#endif