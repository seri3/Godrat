#include "Tools.h"
#include <iostream>

class Question;

class Interface : public Tools
{
private:
    Question * ques;
public:
    Interface( int );
    string get();
    string set(string);
};


