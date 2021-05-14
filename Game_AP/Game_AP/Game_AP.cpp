#include "Question.h"
#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
	const int count_q = 4;
	srand(time(0));
	bool q_list[count_q] = { true };
	int index;
	do
	{
		index = rand() % count_q;
	} while (q_list[index] == false);
	q_list[index] = true;
	Question q(index);

}

