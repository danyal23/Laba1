#include "UserIteraction.h"
#include <string>
#include "CreateEquation.h"
#include <vector>


void UserInteraction::Interaction() {

	int choice = 0;
	do
	{
		PrintMenu();

		if (!Read(choice))
		{
			ShowInputError();
			continue;
		}

		switch (choice)
		{

		case Add_Equation:
		{
			AddEquation();
			break;
		}

		case Find_Roots:
		{
			FindRoots();
			break;
		}

		case Show_Equations:
		{

			ShowEquations();
			break;
		}

		case Exit:
		{
			return;
		}

		default:
			ShowInputError();
		}
	} while (true);
}


void UserInteraction::AddEquation() {
	static int win = 0;
	CreatorOfEquation _creatorOfEquation;
	std::cout << "\nInput:"; std::cin >> equat;
	equations.push_back(_creatorOfEquation.Create(equat));
	saveSTr.push_back(equat);
	equations[win]->CalculateRoot();
	win++;
}

void UserInteraction::FindRoots() {
	if (!saveSTr.empty())
	{
		std::cout << "Input number of equation" << std::endl;
		int a;
		std::cin >> a;

		for (int i = 0; i < equations[a]->GetRoots().size(); i++)
			if (equations[a]->GetRoots()[i].second == true)
			{
				std::cout << "X" << i << " = " << equations[a]->GetRoots()[i].first << std::endl;
			}
			else std::cout << "\nDiskrimenant < 0" << std::endl;
	}
	else std::cout << "ֽאזלטעו 1" << std::endl;
}

void UserInteraction::ShowEquations() {
	for (int i = 0; i < saveSTr.size(); i++)
		std::cout << i << "." << saveSTr[i] << std::endl;
}
void UserInteraction::PrintMenu()
{
	std::cout << std::endl;
	std::cout << Add_Equation << ":Add equation. Example: 2*x^4+5*x^2-10 = 0 | 2*x^2+6*x-6 = 0 | 7*x-10 = 0" << std::endl;
	std::cout << Find_Roots << ":Find the Roots for the equation. Input number equation." << std::endl;
	std::cout << Show_Equations << ":Show equations." << std::endl;
	std::cout << Exit << ":Exit" << std::endl;
}

void UserInteraction::ShowInputError()
{
	std::cout << "\nError: incorrect input\n" << std::endl;
}
