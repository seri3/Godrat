#include "Answer.h"
#include<fstream>
#include<iostream>
using namespace std;
Answer::Answer(int index)
{
	ifstream input("../Answers.txt", ios::in);
	if (!input)
	{
		cerr << "file hasnt opened yet" << endl;
	}
	input.seekg(index * 36 + index);
	input >> first_answer_option >> second_answer_option;
	input.close();
	Answer::dash_remover(first_answer_option);
	Answer::dot_remover(first_answer_option);
	Answer::dash_remover(second_answer_option);
	Answer::dot_remover(second_answer_option);
	cout << first_answer_option << '\t' << second_answer_option << endl;
}
