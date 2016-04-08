#include "BiquadraticEquation.h"

BiquadraticEquation::BiquadraticEquation() : _t(0.0), _t1(0.0), QuadraticEquation() {}

BiquadraticEquation::BiquadraticEquation(int a, int b, int c) : BiquadraticEquation() {
	_a = a;
	_b = b;
	_c = c;
};

void BiquadraticEquation::CalculateRoot() {

	if (CheckDiscriminant() == 2)
	{
		_t = ((-1) * _b + sqrt(GetDiscriminant())) / (2 * _a);
		_t1 = ((-1) * _b - sqrt(GetDiscriminant())) / (2 * _a);
	}
	else if (CheckDiscriminant() == 1)
		_t = ((-1) * _b) / 2 * _a;
	else if (CheckDiscriminant() == 0)
	{
		Roots.push_back(std::make_pair(((-1) * _b) / (2 * _a), false));
	}

	if (_t > 0)
	{
		Roots.push_back(std::make_pair(sqrt(_t), true));
		Roots.push_back(std::make_pair(sqrt(_t) * (-1), true));
	}
	else if (_t == 0)

		Roots.push_back(std::make_pair(0, true));

	else if (_t < 0)
	{
		Roots.push_back(std::make_pair(0, false));
		Roots.push_back(std::make_pair(0, false));
	}

	if (_t1 > 0)
	{
		Roots.push_back(std::make_pair(sqrt(_t1), true));
		Roots.push_back(std::make_pair(sqrt(_t1) * (-1), true));
	}
	else if ((_t1 == 0) && (_t != 0))

		Roots.push_back(std::make_pair(0, true));

	else if (_t < 0)
	{
		Roots.push_back(std::make_pair(0, false));
		Roots.push_back(std::make_pair(0, false));
	}
}