#include "Question.h"
#include"Answer.h"
#include "States.h"
#include "attack.h"
#include <iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
	vector<int> indexs{ 0,1,2,3 };
	srand(time(NULL));
	int index = rand() % indexs.size();
	Question q(indexs[index]);
	Answer ans(indexs[index]);
	int selected_option;
	cin >> selected_option;
	States kingdom;
	kingdom.readStatesOfAnswer(indexs[index], selected_option);
	kingdom.currentStatementPrint();
	indexs.erase(indexs.begin() + index);	
	attack fight;
	fight.print();
	int choose;
	cin >> choose;
	fight.after_attack(choose , kingdom);
	kingdom.currentStatementPrint();
}
