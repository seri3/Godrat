#include "Question.h"
#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
	srand(time(0));
	int index = rand() % 4;
	Question q(index);

}

