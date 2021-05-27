#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include "Interface.h"
#include "Answer.h"
#include "States.h"
#include "Trade.h"

using namespace std;
void betryal(Trade &trade , States &war , int index)
{
	static int count = 0;
	vector<vector <int>> list_info = {{1,2,3},{3,3,3}};
	war.country.push_back(trade.country_list[index].name);
	war.InformationOfEachCountry.push_back(list_info[count % list_info.size()]);
	war.chosencountries.push_back(10+count);
	cout << trade.country_list[index].name <<" country betrayed you, at this time it is your anamy" << endl;
	war.currentStatementPrint();
	trade.country_list.erase(trade.country_list.begin() + index);
	count++;
}
int main()
{
	vector<int> indexs{0, 1, 2, 3};
	States kingdom;
	srand(time(NULL));
	bool warStarted = true;
	bool ejra = false;
	int param = 0;
	Trade trading;
	trading.fill();
	while (true)
	{
		int index = rand() % indexs.size();
		Interface q(indexs[index]);
		Answer ans(indexs[index]);
		int selected_option;
		cin >> selected_option;
		kingdom.readStatesOfAnswer(indexs[index], selected_option);
		kingdom.currentStatementPrint();
		if (kingdom.war_validation())
		{
			if (warStarted == false)
			{
				cout << "the spy brought you the information do you wanna see that ?" << endl;
				string answer;
				cin >> answer;
				if (answer == "yes")
				{
					kingdom.spy();
				label3:
					cout << "if you wanna attack write the number of country and quit if you wanna leave the current state" << endl;
					string _answer;
					cin >> _answer;
					if (_answer == "quit")
					{
					}
					else if (_answer.length() == 1 && int(_answer[0]) < 58 && int(_answer[0]) > 46)
					{
						int ans = stoi(_answer);
						kingdom.ApplyWar(ans);
					}
					else
					{
						cerr << "Read the question carfully" << endl;
						goto label3;
					}
				}
			}
			else
			{
				if (ejra)
				{
				label4:
					cout << "you reached the enough power for attacking again \ntype 'ok' for more information or type 'skip' for skipping this state " << endl;
					string answer;
					cin >> answer;
					if (answer == "ok")
					{
						kingdom.ShowCountries();
						kingdom.Show_MnifestedCountries();
						cout << "Now you got 3 choices:\n1.hiring a spy again\n2.attack randomly\n3.quit" << endl;
						string _answer;
						cin >> _answer;
						if (_answer == "1")
						{
							cout << "Good choice,as the time goes by spies will bring you the full information of each country" << endl;
							warStarted = false;
						}
						else if (_answer == "2")
						{
							cout << "enter the number of country" << endl;
						label5:
							string ans;
							cin >> ans;
							if (ans.length() == 1 && int(ans[0]) < 58 && int(ans[0]) > 46)
							{
								int _ans = stoi(ans);
								kingdom.ApplyWar(_ans);
							}
							else
							{
								cerr << "Enter the correct number" << endl;
								goto label5;
							}
						}
						else if (_answer == "3")
						{
						}
						else
						{
							cerr << "Read the question carefully" << endl;
						}
					}
					else if (answer == "skip")
					{
					}
					else
					{
						cerr << "Read the question carefully NAMOSAN!" << endl;
						goto label4;
					}
				}
				else
				{
					cout << "You got enough power to start the war do you wanna risk it ?!" << endl;
					ejra = true;
				label:
					string answer_war;
					cin >> answer_war;
					if (answer_war == "Yes" || answer_war == "yes")
					{
						kingdom.ShowCountries();
						cout << "here are the list of countries that can be attacked but there is no information about them you got 3 choices: \n1.you can hire a spy to bring you the inforamtion of these countries\n2.take the risk and choose randomly.\n3.quit" << endl;
					label2:
						string answer;
						cin >> answer;
						if (answer == "1")
						{
							cout << "Good choice,as the time goes by spies will bring you the full information of each country" << endl;
							warStarted = false;
						}
						else if (answer == "2")
						{
							cout << "enter the number of country" << endl;
						label6:
							string ans;
							cin >> ans;
							if (ans.length() == 1 && int(ans[0]) < 58 && int(ans[0]) > 46)
							{
								int _ans = stoi(ans);
								kingdom.ApplyWar(_ans);
							}
							else
							{
								cerr << "Enter the correct number" << endl;
								goto label6;
							}
						}
						else if (answer == "3")
						{
						}
						else
						{
							cerr << "just enter the number of the option" << endl;
							goto label2;
						}
					}
					else if (answer_war == "No" || answer_war == "no")
					{
					}
					else
					{
						cerr << "Enter yes if you agree and no for disagreement" << endl;
						goto label;
					}
				}
			}
		}
		else
		{
			warStarted = true;
		}
		//index1:money index2:religion index3:army if one state being risky then it chang it to true
		vector<bool> issue = trading.check_states(kingdom);
		string choosed;
		int index_betryal = 0;
		bool flag = false;
		for (int i = 0; i < issue.size(); i++)
		{
			if (issue[i] == true)
			{
				cout << "your states are in risk, do you want to trad with other countries:" << endl;
			label7:
				cin >> choosed;
				if (choosed == "yes")
				{
					trading.print(issue);
					cout << "print which country do you want:" << endl;
				label8:
					cin >> choosed;
					if (trading.checking_contry_name(choosed))
					{
						if(trading.choosed(choosed, kingdom , index_betryal))
						{
							cout << "index: " << index_betryal <<endl; //TODO DELETE
							betryal(trading , kingdom , index_betryal);
						}
					}
					else if (choosed == "quit")
					{
						cout << "ok" << endl;
					}
					else
					{
						cout << "Wrong name!" << endl;
						goto label8;
					}
				}
				else if (choosed == "no")
				{
					break;
				}
				else
				{
					cout << "Pleas print yes or no" << endl;
					goto label7;
				}
				break;
			}
		}
		indexs.erase(indexs.begin() + index);
	}
}
