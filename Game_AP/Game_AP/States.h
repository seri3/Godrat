#pragma once
#include"War.h"
class States:protected War
{
private:
	int money, satisfaction, religion, army;
    void Printer(int,int = 15);
public:
    States();
	void readStatesOfAnswer(int,int);
    inline int converter(int);
    void applyChanges(int,int,int,int);
    bool reachedZero();
    void currentStatementPrint();
    bool war_validation();
    void spy();
    void ApplyWar(int);
    void ShowCountries();
    void Show_MnifestedCountries();
};

