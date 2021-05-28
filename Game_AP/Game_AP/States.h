#pragma once
#include"War.h"
#include"Trade.h"
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

