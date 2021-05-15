#include "Question.h"
#include"Answer.h"
#include <iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> indexs{ 0,1,2,3 };
	srand(time(0));
	int index = rand() % indexs.size();
	Question q(indexs[index]);
	Answer ans(indexs[index]);
	indexs.erase(indexs.begin() + index);
}

