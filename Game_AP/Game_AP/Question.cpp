#include "Question.h"
#include<iostream>
#include<fstream>
using namespace std;
Question::Question(int index)
{
	ifstream input("../Questions.txt", ios::in);
	if (!input)
	{
		cerr << "file hasnt opened yet" << endl;
	}
	input.seekg(index * 113 + index);
	input >> question;
	input.close();
	Question::dash_remover(question);
	Question::dot_remover(question);
	cout << question << endl;
}