#pragma once
#include<iostream>
#include<vector>
using namespace std;
class War
{
private:
	vector<string> country = { "Antarika","Romoa","Caspior","Xendal","Ormino","Wastel","Berlaf","uldiryo","tequnile","Janatabad" };
	vector<vector<int>> InformationOfEachCountry = { {4,1,5},{3,4,5},{7,6,7},{8,4,3},{6,5,5},{2,5,7},{9,4,8},{4,5,4},{7,3,8},{11,10,10} };//army,people,treasury
	vector<int> chosencountries = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> manifestedcountries;
protected:
	void Print_NameOfCountries();
	bool Checking_The_States_For_Starting_The_War(int, int, int);//money,satisfaction,army
	void Spyinformation();
	void Changingstates(int, int&, int&, int&, int&);//country,religion,satisfaction,army,money
	void Manifested_countires();
};

