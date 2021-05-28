#include <iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<string>
#include<iomanip>
#include <fstream>

using namespace std;
#define ROW 3
#define CULUMN 3

using namespace std;

//Tools.h
class Tools
{
public:
	void dot_remover(string&);
	void dash_remover(string&);
};
//Tools.cpp
void Tools::dot_remover(string &input)
{
	string answer;
	for (int i = 0;i < input.length();i++)
	{
		if (input[i] == '.')
		{
			break;
		}
		answer += input[i];
	}
	input = answer;
}
void Tools::dash_remover(string &input)
{
	for (int i = 0;i < input.length();i++)
	{
		if (input[i] == '-')
		{
			input[i] = ' ';
		}
	}
}
//Answer.h
using namespace std;
class Answer:public Tools
{
private:
	string first_answer_option;
	string second_answer_option;
public:
	Answer(int);
};
//Answer.cpp
Answer::Answer(int index)
{
	ifstream input("../Answers.txt", ios::in);
	if (!input)
	{
		cerr << "file hasnt opened yet" << endl;
	}
	input.seekg(index * 36 + index);
	input >> first_answer_option >> second_answer_option;
	input.close();
	Answer::dot_remover(first_answer_option);
	Answer::dash_remover(first_answer_option);
	Answer::dot_remover(second_answer_option);
	Answer::dash_remover(second_answer_option);
	cout << first_answer_option << '\t' << second_answer_option << endl;
}
//Question.h
class Question:public Tools
{
private :
	string question;
public:
	Question(int);
	string get();
	string set(string);
};
//Question.cpp
Question::Question(int index){}

string Question::get()
{
	return question;
}

string Question::set(string question)
{
	this->question = question;
}
//Interfac.h
class Question;

class Interface : public Tools
{
private:
    Question * ques;
public:
    Interface( int );
    string get();
    string set(string);
};
//Interfac.cpp
Interface::Interface(int index):ques(new Question(index))
{
	ifstream input("../Questions.txt", ios::in);
	if (!input)
	{
		cerr << "file hasnt opened yet" << endl;
	}
	input.seekg(index * 113 + index);
    string test = ques->get();
	input >> test;
	input.close();
	Interface::dash_remover(test);
	Interface::dot_remover(test);
	cout << test << endl;
}
string Interface::get()
{
	return ques->get();
}

string Interface::set(string question)
{
	ques->set(question);
}
//War.h
class War
{
protected:
	vector<string> country = { "Antarika","Romoa","Caspior","Xendal","Ormino","Wastel","Berlaf","uldiryo","tequnile","Janatabad"};
	vector<vector<int>> InformationOfEachCountry = { {4,1,5},{3,4,5},{7,6,7},{8,4,3},{6,5,5},{2,5,7},{9,4,8},{4,5,4},{7,3,8},{11,10,10} };//army,people,treasury
	vector<int> chosencountries = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> manifestedcountries;
	void Print_NameOfCountries();
	bool Checking_The_States_For_Starting_The_War(int, int, int);//money,satisfaction,army
	void Spyinformation();
	void Changingstates(int, int&, int&, int&, int&);//country,religion,satisfaction,army,money
	void Manifested_countires();
	int GetNumberOfCountries();
};
//War.cpp
bool War::Checking_The_States_For_Starting_The_War(int money, int satisfaction, int army)
{
	if (money >= 2 && satisfaction >= 2 && army >= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
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
//States.h
class Trade;
class States :protected War
{
	friend ostream& operator<<(ostream& out, States& state);
	friend class Trade;
	friend void betryal(Trade& trade, States& war, int index);
private:
	int money, satisfaction, religion, army;
	void Printer(int, int = 15);
	int _year = 0;
public:
	States();
	void readStatesOfAnswer(int, int);
	inline int converter(int);
	void applyChanges(int, int, int, int);
	bool reachedZero();
	void currentStatementPrint();
	bool war_validation();
	void spy();
	void ApplyWar(int);
	void ShowCountries();
	void Show_MnifestedCountries();
	void ApplySpyChanges();
	int getSatisfaction();
	int NumberOfCountries();
	bool IsAliveYet();
	int Year();
};
//States.cpp
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
bool States::reachedZero() {
	if (religion && money && satisfaction && army)
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
bool States::IsAliveYet()
{
	if (religion < 1 || money < 1 || satisfaction < 1 || army < 1 || religion>14 || money>14 || army>14 || satisfaction>14)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void States::currentStatementPrint()
{
	if (IsAliveYet())
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
	else
	{
		if (_year > 0)
		{
			cout << "you lost the game!" << endl;
			cout << "you were " << _year << " year in power" << endl;
			exit(0);
		}
		else
		{
			cout << "you lost the game!" << endl << "you were in power less than a year" << endl;
			exit(0);
		}
	}
}
bool States::war_validation()
{
	return States::Checking_The_States_For_Starting_The_War(money, satisfaction, army);
}
void States::spy()
{
	States::Print_NameOfCountries();
	States::Spyinformation();
	States::Manifested_countires();
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
void States::ApplySpyChanges()
{
	States::Spyinformation();
}
int States::getSatisfaction()
{
	return satisfaction;
}
int States::NumberOfCountries()
{
	return States::GetNumberOfCountries();
}
int States::Year()
{
	return _year += 1;
}
//Trade.h
/**
 * @brief this class is for trade part in game
 *
 */
 // class War;
class States;
class Trade
{
    friend void betryal(Trade& trade, States& war, int index);
public:
    Trade();
    Trade(int, int, int, int, string);
    Trade(int, int, int, int, string, int);
    void fill();
    //void print(string) const;
    //void check_states( States state , Trad countries) const;
    vector<bool> check_states(States state);
    void print(vector<bool>&);
    bool choosed(string, States&, int&);
    bool checking_contry_name(string, vector<bool>);
private:
    int money = 0, satisfaction = 0, religion = 0, army = 0, count_for_betray = 0;
    int betrayal_capasity;
    string name;
    vector <Trade> country_list;
};
//Trad.cpp
// #ifdef TRAD_CC

using namespace std;

Trade::Trade(int money, int staisfaction, int religion, int army, string name)
{
    this->money = money;
    this->army = army;
    this->satisfaction = staisfaction;
    this->religion = religion;
    this->name = name;
}

Trade::Trade(int money, int staisfaction, int religion, int army, string name, int betrayal_capasity)
{
    this->money = money;
    this->army = army;
    this->satisfaction = staisfaction;
    this->religion = religion;
    this->name = name;
    this->betrayal_capasity = betrayal_capasity;
}

Trade::Trade() {}

/**
 * @brief this function fill the country list
 *
 */
void Trade::fill()
{
    //TODO be betrayal Korax va Son ezafe kon
    Trade korax(-3, 0, +3, 0, "Korax", 1);
    country_list.push_back(korax);
    Trade Lev(-3, 0, 0, +3, "Lev");
    country_list.push_back(Lev);
    Trade Zirex(+3, 0, -3, 0, "Zirex");
    country_list.push_back(Zirex);
    Trade Dora(+3, 0, 0, -3, "Dorax");
    country_list.push_back(Dora);
    Trade Son(0, 0, 3, -3, "Son", 2);
    country_list.push_back(Son);
    Trade Dunck(0, 0, -3, +3, "Dunck");
    country_list.push_back(Dunck);
}

/**
 * @brief this func creat a vector list then find low states and change the value of the list and pass it to
 *
 * @param state index 0 is for money index 1 is for religion index 2 is for army
 * @return vector<bool>
 */
vector<bool> Trade::check_states(States state)
{
    vector<bool> issue = { false, false, false };
    if (state.money <= 5)
    {
        issue[0] = true;
    }
    if (state.religion <= 5)
    {
        issue[1] = true;
    }
    if (state.army <= 5)
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
void Trade::print(vector<bool>& issue)
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
                cout << country_list[i].name << " county will give you " << country_list[i].money << "$";

                if (country_list[i].army < 0)
                {
                    if (country_list[i].army == -1)
                        cout << " but it wants " << -1 * country_list[i].army << " army" << endl;
                    else
                        cout << " but it wants " << -1 * country_list[i].army << " armies" << endl;
                    //break;
                }
                else if (country_list[i].religion < 0)
                {
                    if (country_list[i].religion == 1)
                        cout << " but it will adevrtise its religion " << -1 * country_list[i].religion << " time in your country" << endl;
                    else
                        cout << " but it will adevrtise its religion " << -1 * country_list[i].religion << " times in your country" << endl;
                    //break;
                }
            }
        }
    }
    if (issue[1] == true)
    {
        for (int i = 0; i < country_list.size(); i++)
        {
            if (country_list[i].religion > 0)
            {
                if (country_list[i].religion == 1)
                    cout << country_list[i].name << " county will build " << country_list[i].religion << " mosque";
                else
                    cout << country_list[i].name << " county will build " << country_list[i].religion << " mosques";

                if (country_list[i].money < 0)
                {
                    cout << " but it wants " << -1 * country_list[i].money << "$" << endl;
                    //break;
                }
                else if (country_list[i].army < 0)
                {
                    if (country_list[i].army == -1)
                        cout << " but it will give you " << -1 * country_list[i].army << " army" << endl;
                    else
                        cout << " but it will give you " << -1 * country_list[i].army << " armies" << endl;
                    //break;
                }
            }
        }
    }
    if (issue[2] == true)
    {
        for (int i = 0; i < country_list.size(); i++)
        {
            if (country_list[i].army > 0)
            {
                cout << country_list[i].name << " give you " << country_list[i].army << " army ";
                if (country_list[i].money < 0)
                {
                    cout << " but it wants " << -1 * country_list[i].money << "$" << endl;
                    //break;
                }
                else if (country_list[i].religion < 0)
                {
                    if (country_list[i].religion == -1)
                        cout << " but it will adevrtise its religion" << -1 * country_list[i].religion << "time in your country" << endl;
                    else
                        cout << " but it will adevrtise its religion" << -1 * country_list[i].religion << "times in your country" << endl;
                    //break;
                }
            }
        }
    }
    // issue[0] = false;
    // issue[1] = false;
    // issue[2] = false;
}
/**
 * @brief customer choose the country and this func apply chenges
 *
 * @param name the name of country which cunstomer choosed
 * @param state name of the state object
 * @return true when one country betryed
 */
bool Trade::choosed(string name, States& state, int& index)
{
    for (int i = 0; i < country_list.size(); i++)
    {
        if (country_list[i].name == name)
        {
            //these countries aren't royal
            if (name == "Korax")
            {
                country_list[i].count_for_betray++;
                if (country_list[i].count_for_betray == country_list[i].betrayal_capasity)
                {
                    country_list[i].money = (country_list[i].money >= 0) ? 0 : country_list[i].money;
                    country_list[i].religion = (country_list[i].religion >= 0) ? 0 : country_list[i].religion;
                    country_list[i].army = (country_list[i].army >= 0) ? 0 : country_list[i].army;
                    state.applyChanges(country_list[i].money, country_list[i].satisfaction, country_list[i].religion, country_list[i].army);
                    state.currentStatementPrint();
                    index = i;
                    return true;
                }
            }
            if (name == "Son")
            {
                country_list[i].count_for_betray++;
                if (country_list[i].count_for_betray == country_list[i].betrayal_capasity)
                {
                    country_list[i].money = (country_list[i].money >= 0) ? 0 : country_list[i].money;
                    country_list[i].religion = (country_list[i].religion >= 0) ? 0 : country_list[i].religion;
                    country_list[i].army = (country_list[i].army >= 0) ? 0 : country_list[i].army;
                    state.applyChanges(country_list[i].money, country_list[i].satisfaction, country_list[i].religion, country_list[i].army);
                    state.currentStatementPrint();
                    index = i;
                    return true;
                }
            }
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
                country_list[i].religion = country_list[i].religion - 1;
            }
            else if (country_list[i].religion < 0 && country_list[i].religion > -15)
            {
                country_list[i].religion = country_list[i].religion - 2;
            }
            if (country_list[i].army > 1)
            {
                country_list[i].army = country_list[i].army - 1;
            }
            else if (country_list[i].army < 0 && country_list[i].army > -15)
            {
                country_list[i].army = country_list[i].army - 2;
            }
            // cout << "size: " << country_list.size() << endl;
        }
    }
    return false;
}
/**
 * @brief checking the name of country
 *
 * @param name it is name of country the customer input
 * @return true if the name of country exits in country_list
 * @return false if it doesn't exist this name in country_list
 */
bool Trade::checking_contry_name(string name, vector<bool> bool_list)
{
    for (int i = 0; i < country_list.size(); i++)
    {

        if (name == country_list[i].name)
        {
            if (country_list[i].money > 0 && bool_list[0] == true)
                return true;
            if (country_list[i].religion > 0 && bool_list[1] == true)
                return true;
            if (country_list[i].army > 0 && bool_list[2] == true)
                return true;
            return false;
        }
        else if (i == country_list.size() - 1)
        {
            return false;
        }
    }
}
//Game_AP.cpp
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
void betryal(Trade& trade, States& war, int index)
{
	static int count = 0;
	vector<vector <int>> list_info = { {1,2,3},{3,3,3} };
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
ostream& operator<<(ostream& out, States& state)
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
template<typename T>
void vazir(T a)
{
	cout << a << endl;
}
int main()
{
	vector<int> indexs{ 0,1,2,3,4,5,6,7,8,9 };
	States kingdom;
	srand(time(NULL));
	bool warStarted = true;
	bool ejra = false;
	bool first_time = true;
	Trade trading;
	trading.fill();
	while (true)
	{
		//if (!kingdom.reachedZero())
		//{
		//	cout << "you lost the game" << endl;
		//	exit(0);
		//}
		//int index = rand() % indexs.size();
		int index = 0;

		Interface q(indexs[index]);
		Answer ans(indexs[index]);
	label0:string selected_option;
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
			label9:cout << "the spy brought you the information do you wanna see that ?" << endl;
				string answer;
				cin >> answer;
				if (answer == "yes")
				{
					kingdom.spy();
				label3:cout << "if you wanna attack write the number of country and quit if you wanna leave the current state" << endl;
					string _answer;
					cin >> _answer;
					bool check = true;
					if (_answer == "quit")
					{

					}
					else
					{
						for (int k = 0;k < _answer.size();k++)
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
				label4:cout << "you reached the enough power for attacking again \ntype 'ok' for more information or type 'skip' for skipping this state " << endl;
					string answer;
					cin >> answer;
					if (answer == "ok")
					{
						kingdom.ShowCountries();
						kingdom.Show_MnifestedCountries();
						cout << "Now you got 3 choices:\n1.hiring a spy again\n2.attack randomly\n3.quit" << endl;
					label21:string _answer;
						cin >> _answer;
						if (_answer == "1")
						{
							cout << "Good choice,as the time goes by spies will bring you the full information of each country" << endl;
							warStarted = false;
						}
						else if (_answer == "2")
						{
							cout << "enter the number of country" << endl;
						label5:string ans;
							cin >> ans;
							bool check = true;
							for (int k = 0;k < ans.size();k++)
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
				label:string answer_war;
					cin >> answer_war;
					if (answer_war == "Yes" || answer_war == "yes")
					{
						kingdom.ShowCountries();
						cout << "here are the list of countries that can be attacked but there is no information about them you got 3 choices: \n1.you can hire a spy to bring you the inforamtion of these countries\n2.take the risk and choose randomly.\n3.quit" << endl;
					label2:string answer;
						cin >> answer;
						if (answer == "1")
						{
							cout << "Good choice,as the time goes by spies will bring you the full information of each country" << endl;
							warStarted = false;
						}
						else if (answer == "2")
						{
							cout << "enter the number of country" << endl;
						label6:string ans;
							cin >> ans;
							bool check = true;
							for (int k = 0;k < ans.size();k++)
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
		if (kingdom.getSatisfaction() <= 5)
		{

			int map[3][3] = {
		{1, 9, 3},
		{6, 3, 8},
		{8, 7, 2} };
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
		if (index < indexs.size() - 1)
		{
			index++;
		}
		else
		{
			cout << "you won" << endl;
			exit(0);
		}
	}

}


