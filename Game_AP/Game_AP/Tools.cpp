#include "Tools.h"
void Tools::dot_remover(string &input)
{
	string answer;
	for (int i = 0;i < input.length();i++)
	{
		if (input[i] == '.')
		{
			break;
		}
		answer += input[i];
	}
	input = answer;
}
void Tools::dash_remover(string &input)
{
	for (int i = 0;i < input.length();i++)
	{
		if (input[i] == '-')
		{
			input[i] = ' ';
		}
	}
}