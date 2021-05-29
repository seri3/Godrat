#include "Interface.h"
#include "Answer.h"
#include "States.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>
#include "Trade.h"
#include <unistd.h>
using namespace std;
#define ROW 3
#define CULUMN 3
int collect(const int(map)[3][3], int r, int c)
{
	// Base condition.
	if ((r < 0) || (r == ROW) || (c == CULUMN))
		return 0;

	//MOVEMENTS:
	int upperDiagonal = collect(map, r - 1, c + 1);
	int straight = collect(map, r, c + 1);
	int lowerDiagonal = collect(map, r + 1, c + 1);
	int maxPath = max(max(upperDiagonal, straight), lowerDiagonal);
	// Recurtion to return the maximum gold collected.
	return map[r][c] + maxPath;
}
void betryal(Trade &trade, States &war, int index)
{
	static int count = 0;
	vector<vector<int>> list_info = {{1, 2, 3}, {3, 3, 3}};
	war.country.push_back(trade.country_list[index].name);
	war.InformationOfEachCountry.push_back(list_info[count % list_info.size()]);
	war.chosencountries.push_back(10 + count);
	cout << trade.country_list[index].name << " country betrayed you, at this time it is your enemy" << endl;
	trade.country_list.erase(trade.country_list.begin() + index);
	count++;
}
int maxGoldCollected(const int(map)[][3])
{
	int maxGold = 0;

	//function call for  every row.
	for (int i = 0; i < ROW; i++)
	{
		int goldCollected = collect(map, i, 0);
		maxGold = max(maxGold, goldCollected);
	}

	return maxGold;
}
ostream &operator<<(ostream &out, States &state)
{

	out << setw(15) << "Money" << setw(1) << " : ";
	state.Printer(state.money);
	out << setw(15) << "Army" << setw(1) << " : ";
	state.Printer(state.army);
	out << setw(15) << "Satisfaction" << setw(1) << " : ";
	state.Printer(state.satisfaction);
	out << setw(15) << "Religion" << setw(1) << " : ";
	state.Printer(state.religion);
	return out;
}
template <typename T>
void vazir(T a)
{
	cout << a;
}
int main()
{
	cout
		<< endl
		<< "            __________     ____                                       ____                                         " << endl
		<< endl
		<< "          /           |   |    |                                     |    |                                        " << endl
		<< endl
		<< "         /     _______|   |    |                                     |    |                                ___     " << endl
		<< endl
		<< "         |    /           |    |             ___________             |    |                             __|   |__  " << endl
		<< endl
		<< "         |    |      __   |    |_______    /   _______  \\    ________|    |   ___  __    ___________   |__     __| " << endl
		<< endl
		<< "         |    |    |   |  |            |  |   |       |  |  |    _____    |  |     __|  |   ____    |     |   |    " << endl
		<< endl
		<< "         |    \\____|   |  |     ___    |  |   |       |  |  |   |     |   |  |    |     |  |    |   |     |   |    " << endl
		<< endl
		<< "         \\             |  |    |   |   |  |   |_______|  |  |   |_____|   |  |    |     |  |____|   |     |   |    " << endl
		<< endl
		<< "          \\____________|  |____|   |___|   \\____________/   |_____________|  |____|     |________| __|    |___|    " << endl;
	cout << "loading";
	unsigned int microsecond = 1000000;
	for (int i = 0; i < 1; i++)
	{
		// cout << '\b' << '\b' << '\b' ;
		usleep(1 * microsecond);
		cout << ".";
		usleep(1 * microsecond);
		cout << ".";
		usleep(1 * microsecond);
		cout << ".";
		usleep(1 * microsecond);
		cout << " " << '\b' << '\b';
		cout << " " << '\b' << '\b';
		cout << " " << '\b' << '\b' << " " << '\b';
	}
	vector<int> indexs{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	States kingdom;
	srand(time(NULL));
	bool warStarted = true;
	bool ejra = false;
	bool first_time = true;
	Trade trading;
	trading.fill();
	while (true)
	{

		if (indexs.size() == 0)
		{
			cout << "congrats you are imortal" << endl;
			exit(0);
		}
		int index = rand() % indexs.size();
		Interface q(indexs[index]);
		Answer ans(indexs[index]);
	label0:
		string selected_option;
		cin >> selected_option;
		if (selected_option == "1" || selected_option == "2")
		{
		}
		else
		{
			cerr << "please enter the number of option" << endl;
			goto label0;
		}
		int temp = stoi(selected_option);
		kingdom.readStatesOfAnswer(indexs[index], temp);
		if (kingdom.IsAliveYet())
		{
			vazir<States>(kingdom);
			if (!first_time)
			{
				cout << kingdom.Year() << " year in power" << endl;
			}
			first_time = false;
		}
		else
		{
			cout << "you lost the game" << endl;
			cout << "you were " << kingdom.Year() << " year in power" << endl;
			exit(0);
		}
		if (kingdom.war_validation())
		{
			if (warStarted == false)
			{
			label9:
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
					bool check = true;
					if (_answer == "quit")
					{
					}
					else
					{
						for (int k = 0; k < _answer.size(); k++)
						{
							if (int(_answer[k]) >= 58 || int(_answer[k]) <= 46)
							{
								check = false;
							}
						}
						if (check)
						{
							int _ans = stoi(_answer);
							if (_ans > kingdom.NumberOfCountries() || _ans <= 0)
							{
								cerr << "Enter the correct number" << endl;
								goto label3;
							}
							else
							{
								kingdom.ApplyWar(_ans);
								warStarted = true;
							}
						}
						else
						{
							cerr << "Enter the correct number" << endl;
							goto label3;
						}
					}
				}
				else if (answer == "no")
				{
					kingdom.ApplySpyChanges();
				}
				else
				{
					cerr << "enter yes for agreement and no for disagreement" << endl;
					goto label9;
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
					label21:
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
							bool check = true;
							for (int k = 0; k < ans.size(); k++)
							{
								if (int(ans[k]) >= 58 || int(ans[k]) <= 46)
								{
									check = false;
								}
							}
							if (check)
							{
								int _ans = stoi(ans);
								if (_ans > kingdom.NumberOfCountries() || _ans <= 0)
								{
									cerr << "Enter the correct number" << endl;
									goto label5;
								}
								else
								{
									kingdom.ApplyWar(_ans);
								}
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
							goto label21;
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
							bool check = true;
							for (int k = 0; k < ans.size(); k++)
							{
								if (int(ans[k]) >= 58 || int(ans[k]) <= 46)
								{
									check = false;
								}
							}
							if (check)
							{
								int _ans = stoi(ans);
								if (_ans > kingdom.NumberOfCountries() || _ans <= 0)
								{
									cerr << "Enter the correct number" << endl;
									goto label6;
								}
								else
								{
									kingdom.ApplyWar(_ans);
								}
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
		vector<bool> issue = trading.check_states(kingdom);
		string choosed;
		int index_betryal = 0;
		bool flag = false;
		for (int i = 0; i < issue.size(); i++)
		{
			if (issue[i] == true)
			{
				cout << "your states are in risk, do you want to trade with other countries:" << endl;
			label7:
				cin >> choosed;
				if (choosed == "yes")
				{
					trading.print(issue);
					cout << "print which country do you want or print 'quit' to leave this state" << endl;
				label8:
					cin >> choosed;
					if (trading.checking_contry_name(choosed, issue))
					{
						if (trading.choosed(choosed, kingdom, index_betryal))
						{
							betryal(trading, kingdom, index_betryal);
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
		if (kingdom.getSatisfaction() <= 2)
		{

			int map[3][3] = {
				{1, 9, 3},
				{6, 3, 8},
				{8, 7, 2}};
			cout << "here you can see the population of each city of your country. try to increase the satisfaction of your people" << endl;
			cout << "Capital" << endl
				 << "|" << endl
				 << "+--- " << map[0][0] << " --- " << map[0][1] << " --- " << map[0][2] << endl
				 << "+--- " << map[1][0] << " --- " << map[1][1] << " --- " << map[1][2] << endl
				 << "+--- " << map[2][0] << " --- " << map[2][1] << " --- " << map[2][2] << endl
				 << "now choose the best way to catch best result & satisfaction from people." << endl;
			int sum_total = 0, max_sum = maxGoldCollected(map);
			int m_input[3];
			do
			{
				cin >> m_input[0] >> m_input[1] >> m_input[2];
				int i = 0, j = 0, k = 0;
				for (i = 0; i < 3; i++)
					if (m_input[0] == map[i][0])
						break;
				for (j = 0; j < 3; j++)
					if (m_input[1] == map[j][1])
						break;
				for (k = 0; k < 3; k++)
					if (m_input[2] == map[k][2])
						break;
				sum_total = map[i][0] + map[j][1] + map[k][2];
				if (sum_total == max_sum)
				{
					cout << "this made satisfaction of people " << (int)(max_sum / 3) << "more. good job! back to the home." << endl;
					kingdom.applyChanges(0, (int)(max_sum / 3), 0, 0);
					kingdom.currentStatementPrint();
					break;
				}
				else if (sum_total != max_sum)
					cout << "Try Again! maybe not a good choice." << endl;

			} while (1);
		}
		indexs.erase(indexs.begin() + index);
		if (indexs.size() == 0)
		{
			cout << "you won" << endl;
			exit(0);
		}
	}
	return 0;
}
