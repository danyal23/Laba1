#include "LinearEquation.h"

LinearEquation::LinearEquation(int a, int b) : EquationBase() {
	_a = a;
	_b = b;
}

void LinearEquation::CalculateRoot() {
	Roots.push_back(std::make_pair(((-1) * (double)_b) / (double)_a, true));
}