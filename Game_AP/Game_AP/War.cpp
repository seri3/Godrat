#include "War.h"
#include<iostream>
#include<string>
/**
 * @brief checking states to say you have enough power
 * 
 * @param money 
 * @param satisfaction 
 * @param army 
 * @return true if these states being more than boundry
 * @return false 
 */
bool War::Checking_The_States_For_Starting_The_War(int money, int satisfaction, int army)
{
	if (money >= 8 && satisfaction >= 8 && army >= 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**
 * @brief printing the list of countries
 * 
 */
void War::Print_NameOfCountries()
{
	for (int i = 0;i < country.size();i++)
	{
		cout << i + 1 << '.' << country[i] << "   ";
		if (i == country.size() - 1)
		{
			cout << endl;
		}
	}
}

void War::Spyinformation()
{
	int index = rand() % chosencountries.size();
	manifestedcountries.push_back(chosencountries[index]);
	chosencountries.erase(chosencountries.begin() + index);
}
void War::Changingstates(int _country, int& religion, int& satisfaction, int& army, int& money)
{
	for (int i = 0;i < country.size();i++)
	{
		if (i == (_country - 1))
		{
			army -= InformationOfEachCountry[i][0];
			money += InformationOfEachCountry[i][2];
			satisfaction += ((InformationOfEachCountry[i][2] / 2) - (InformationOfEachCountry[i][2] / 3));
			religion -= InformationOfEachCountry[i][1] / 3;
			InformationOfEachCountry.erase(InformationOfEachCountry.begin() + i);
			country.erase(country.begin() + i);
			for (int j = 0;j < manifestedcountries.size();j++)
			{
				if (manifestedcountries[j] == i)
				{
					manifestedcountries.erase(manifestedcountries.begin() + j);
					break;
				}
			}
			break;
		}
	}
}
void War::Manifested_countires()
{
	for (int j = 0;j < manifestedcountries.size();j++)
	{
		cout << country[manifestedcountries[j]] << endl;
		cout << "Army:    [";
		for (int i = 1;i <= InformationOfEachCountry[manifestedcountries[j]][0];i++)
		{
			cout << "=";
			if (i == InformationOfEachCountry[manifestedcountries[j]][0])
			{
				cout << "]" << endl;
			}
		}
		cout << "People:  [";
		for (int i = 1;i <= InformationOfEachCountry[manifestedcountries[j]][1];i++)
		{
			cout << "=";
			if (i == InformationOfEachCountry[manifestedcountries[j]][1])
			{
				cout << "]" << endl;
			}
		}
		cout << "Treasury:[";
		for (int i = 1;i <= InformationOfEachCountry[manifestedcountries[j]][2];i++)
		{
			cout << "=";
			if (i == InformationOfEachCountry[manifestedcountries[j]][2])
			{
				cout << "]" << endl;
			}
		}
	}
}
int War::GetNumberOfCountries()
{
	return country.size();
}

