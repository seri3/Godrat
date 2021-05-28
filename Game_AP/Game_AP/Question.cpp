#include "Question.h"
#include<iostream>
#include<fstream>
using namespace std;
Question::Question(int index){}

string Question::get()
{
	return question;
}

string Question::set(string question)
{
	this->question = question;
}