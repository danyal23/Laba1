#include "CreateEquation.h"
#include "BiquadraticEquation.h"
#include "LinearEquation.h"
#include "QuadraticEquation.h"
#include "EquationBase.h"
#include <iostream>

IEquation* CreatorOfEquation::Create(const std::string& _equation) {

	int i = 0;
	int j = 0;

	while (i < _equation.size())
	{
		char sign = ' ';
		if ((_equation[i] == '+') || (_equation[i] == '-'))
		{
			sign = _equation[i];
			++i;
		}

		int coefficient = ExtractCoefficient(_equation, i);

		int power = 0;

		if (_equation[i] == '*')
			++i;

		if ((_equation[i] == '-') || (_equation[i] == '+'))
			power = 1;

		if (_equation[i] == '^')
		{
			++i;
			power = ExtractPower(_equation, i);
		}

		if (_equation[i] == 'x')
		{
			++i;
			if (_equation[i] != '^') { power = 1; }
			else {
				++i;
				power = ExtractPower(_equation, i);

			}
		}

		if (sign == '-')
			coefficient *= -1;

		Storage.push_back(coefficient);
		Powers.push_back(power);

		if (_equation[i] == '=') break;
	}


	if (Powers[0] == 4)
	{
		if (Storage.size() == 3)
			return new BiquadraticEquation(Storage[0], Storage[1], Storage[2]);

		else if ((Storage.size() == 2) && (Powers[0] == 4) && (Powers[1] == 2))
			new BiquadraticEquation(Storage[0], Storage[1], 0);

		else if ((Powers[0] == 4) && (Storage.size() == 1))
			new BiquadraticEquation(Storage[0], 0, 0);

		else if ((Powers[0] == 4) && (Storage.size() == 2))
			new BiquadraticEquation(Storage[0], 0, Storage[1]);
	}

	else if (Powers[0] == 2)
	{
		if (Storage.size() == 3)
			return new QuadraticEquation(Storage[0], Storage[1], Storage[2]);

		else if ((Powers[0] == 2) && (Storage.size() == 1))
			new QuadraticEquation(Storage[0], 0, 0);

		else if ((Powers[0] == 2) && (Powers[1] == 1))
			new QuadraticEquation(Storage[0], Storage[1], 0);

		else if ((Powers[0] == 2) && (Storage.size() == 2))
			new QuadraticEquation(Storage[0], 0, Storage[1]);
	}

	else if ((Powers[0] == 1) && (Storage.size() == 2))
		return new LinearEquation(Storage[0], Storage[1]);
	else if (Powers[0] == 1)
		return new LinearEquation(Storage[0], 0);
	else return nullptr;


}

int CreatorOfEquation::ExtractPower(const std::string& s, int& pos)
{
	int result = 0;

	while (pos < s.size() && isdigit(s[pos]))
	{
		if (isdigit(s[pos + 1]))
		{
			result = 1;
			result = s[pos] - '0';
			result *= 10;
			++pos;
		}

		result += s[pos] - '0';
		++pos;
	}
	return result;

}

int CreatorOfEquation::ExtractCoefficient(const std::string& s, int& pos)
{
	int result = 1;

	if (isdigit(s[pos]))
	{
		result = s[pos] - '0';
		while (isdigit(s[pos + 1])) {
			result *= 10;
			result += s[pos + 1] - '0';
			pos++;
		}
	}
	++pos;
	return result;

}