#include "Question.h"
#include "Interface.h"
#include <fstream>
#include <iostream>
using namespace std;

Interface::Interface(int index):ques(new Question(index))
{
	ifstream input("../Questions.txt", ios::in);
	if (!input)
	{
		cerr << "file hasnt opened yet" << endl;
	}
	input.seekg(index * 113 + index);
    string test = ques->get();
	input >> test;
	input.close();
	Interface::dash_remover(test);
	Interface::dot_remover(test);
	cout << test << endl;
}
string Interface::get()
{
	return ques->get();
}

string Interface::set(string question)
{
	ques->set(question);
}