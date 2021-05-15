#include "States.h"
#include<iostream>
#include<fstream>
using namespace std;
States::States(int index, int answer_option)
{
	ifstream input;
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
	input >> religion >> satisfaction >> army >> money;
	cout << religion << '\t' << satisfaction << '\t' << army << '\t' << money << endl;
}