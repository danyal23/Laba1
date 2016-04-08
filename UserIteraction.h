#pragma once
#include <iostream>
#include <string>
#include "EquationBase.h"
#include "CreateEquation.h"
#include <sstream>
#include <vector>
#include "IEquation.h"


class UserInteraction {
public:

	void Interaction();

	void AddEquation();

	void FindRoots();

	void ShowEquations();

private:
	static const int Add_Equation = 1;
	static const int Find_Roots = 2;
	static const int Show_Equations = 3;
	static const int Exit = 4;

	std::string equat;
	std::vector<IEquation*> equations;
	std::vector<std::string> saveSTr;

	void PrintMenu();

	void ShowInputError();

	template< class T >
	bool Read(T& res)
	{
		std::string s;
		std::cin >> s;

		std::istringstream sin(s);
		if (!(sin >> res))
		{
			return false;
		}

		if (!sin.eof()) return false;
		return true;
	}
};
