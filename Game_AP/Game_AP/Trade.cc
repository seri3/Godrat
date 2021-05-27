// #ifdef TRAD_CC
#define TRADE_CC

#include <iostream>
#include <vector>
#include "Trade.h"

using namespace std;

Trade::Trade(int money, int staisfaction, int religion, int army, string name)
{
    this->money = money;
    this->army = army;
    this->satisfaction = staisfaction;
    this->religion = religion;
    this->name = name;
}

Trade::Trade() {}

//this function fill the country list
void Trade::fill()
{
    Trade korax(-3, 0, +3, 0, "Korax");
    country_list.push_back(korax);
    Trade Lev(-3, 0, 0, +3, "Lev");
    country_list.push_back(Lev);
    Trade Zirex(+3, 0, -3, 0, "Zirex");
    country_list.push_back(Zirex);
    Trade Dora(+3, 0, 0, -3, "Dorax");
}

//this func creat a vector list then find low states and change the value of the list and pass it to //TODO
vector<bool> Trade::check_states(States state)
{
    //index 0 is for money
    //index 1 is for religion
    //index 2 is for army
    vector<bool> issue = {false, false, false};
    if (state.money <= 7)
    {
        issue[0] = true;
    }
    if (state.religion <= 7)
    {
        issue[1] = true;
    }
    if (state.army <= 7)
    {
        issue[2] = true;
    }
    return issue;
}
/**
 * @brief for printing problemes and solutions. inputs: input1: each index being true it prints the probleme and solution of that state
 * @param issue 
 * bool vector index0 is for money index1 is for army index3 is religion
 */
void Trade::print(vector<bool> &issue)
{
    cout << "These states are in risk:" << endl;
    if (issue[0] == true)
    {
        cout << "money" << endl;
    }
    if (issue[1] == true)
    {
        cout << "religion" << endl;
    }
    if (issue[2] == true)
    {
        cout << "army" << endl;
    }

    if (issue[0] == true)
    {
        for (int i = 0; i < country_list.size(); i++)
        {
            if (country_list[i].money > 0)
            {
                cout << country_list[i].name << " county will give " << country_list[i].money << "$ money";
                for (int j = 0; j < country_list.size(); j++)
                {
                    if (country_list[j].army < 0)
                    {
                        cout << " but it wants " << country_list[i].army << endl;
                        break;
                    }
                    else if (country_list[j].religion < 0)
                    {
                        cout << " but it will adevrtise its religion in your country" << endl;
                        break;
                    }
                }
            }
        }
        issue[0] = false;
    }
    if (issue[1] == true)
    {
        for (int i = 0; i < country_list.size(); i++)
        {
            if (country_list[i].religion > 0)
            {
                cout << country_list[i].name << " county will build " << country_list[i].religion << " mosque";
                for (int j = 0; j < country_list.size(); j++)
                {
                    if (country_list[j].money < 0)
                    {
                        cout << " but it wants " << -1 * country_list[i].money << "$" << endl;
                        break;
                    }
                    else if (country_list[j].army < 0)
                    {
                        cout << " but it will give" << -1 * country_list[i].army << "army" << endl;
                        break;
                    }
                }
            }
        }
        issue[1] = false;
    }
    if (issue[2] == true)
    {
        for (int i = 0; i < country_list.size(); i++)
        {
            if (country_list[i].army > 0)
            {
                cout << country_list[i].name << " give " << country_list[i].army << " army ";
                for (int j = 0; j < country_list.size(); j++)
                {
                    if (country_list[j].army < 0)
                    {
                        cout << " but it wants " << country_list[i].money << "$" << endl;
                        break;
                    }
                    else if (country_list[j].religion < 0)
                    {
                        cout << " but it will adevrtise its religion in your country" << endl;
                        break;
                    }
                }
            }
        }
        issue[2] = false;
    }
}
//customer choose the country and this func apply chenges
//input1: the name of country cunstomer choosed
//input2: name of the state object
void Trade::choosed(string name, States &state)
{
    for (int i = 0; i < country_list.size(); i++)
    {
        if (country_list[i].name == name)
        {
            state.applyChanges(country_list[i].money, country_list[i].satisfaction, country_list[i].religion, country_list[i].army);
            state.currentStatementPrint();
            if (country_list[i].money > 1)
            {
                country_list[i].money = country_list[i].money - 1;
            }
            else if (country_list[i].money < 0 && country_list[i].money > -15)
            {
                country_list[i].money = country_list[i].money - 2;
            }
            if (country_list[i].religion > 1)
            {
                country_list[i].religion = country_list[i].religion- 1;
            }
            else if (country_list[i].religion < 0 && country_list[i].religion > -15)
            {
                country_list[i].religion = country_list[i].religion- 2;
            }
            if (country_list[i].army > 1)
            {
                country_list[i].army = country_list[i].army - 1;
            }
            else if (country_list[i].army < 0 && country_list[i].army > -15)
            {
                country_list[i].army = country_list[i].army - 2;
            }
        }
    }
}
bool Trade::checking_contry_name(string name)
{
    for (int i = 0; i < country_list.size(); i++)
    {
        if (name == country_list[i].name)
        {
            return true;
        }
        else if (i == country_list.size() - 1)
        {
            return false;
        }
    }
}
// #endif
