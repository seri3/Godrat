#include "Question.h"
#include<iostream>
#include<fstream>
using namespace std;
Question::Question(int index)
{
	ifstream input("../Questions.txt", ios::in);
	if (!input)
	{
		cerr << "file hasent opened yet" << endl;
	}
	input.seekg(index*113+index);
	input >> question;
	input.close();
	dash_remover();
	dot_remover();
	cout << question << endl;
}
void Question::dash_remover()
{
	for (int i = 0;i < question.length();i++)
	{
		if (question[i] == '-')
		{
			question[i] = ' ';
		}
	}
}
void Question::dot_remover()
{
	string answer;
	for (int i = 0;i < question.length();i++)
	{
		if (question[i] == '.')
		{
			break;
		}
		answer += question[i];
	}
	question = answer;
}