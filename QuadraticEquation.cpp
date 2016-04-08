#include "QuadraticEquation.h"

QuadraticEquation::QuadraticEquation() : EquationBase() {}

QuadraticEquation::QuadraticEquation(int a, int b, int c) : EquationBase() {
	_a = a;
	_b = b;
	_c = c;
}

int QuadraticEquation::GetDiscriminant() {
	return (pow(_b, 2) - 4 * _a * _c);
}

int QuadraticEquation::CheckDiscriminant() {
	if (GetDiscriminant() > 0)
		return 2;
	else if (GetDiscriminant() < 0)
		return 0;
	else return 1;
}

void QuadraticEquation::CalculateRoot() {
	if (CheckDiscriminant() == 2)
	{
		Roots.push_back(std::make_pair(((-1) * _b + sqrt(GetDiscriminant())) / (2 * _a), true));
		Roots.push_back(std::make_pair(((-1) * _b - sqrt(GetDiscriminant())) / (2 * _a), true));
	}
	else if (CheckDiscriminant() == 1)

		Roots.push_back(std::make_pair(((-1) * _b) / (2 * _a), true));

	else if (CheckDiscriminant() == 0)
	{
		Roots.push_back(std::make_pair(((-1) * _b) / (2 * _a), false));
	}
}