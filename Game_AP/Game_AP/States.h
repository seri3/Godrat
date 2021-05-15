#pragma once
class States
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
};

