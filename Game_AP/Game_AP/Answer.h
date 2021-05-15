#pragma once
#include"Tools.h"
#include<iostream>
using namespace std;
class Answer:public Tools
{
private:
	string first_answer_option;
	string second_answer_option;
public:
	Answer(int);
};

