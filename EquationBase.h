#pragma once
#include "IEquation.h"
#include <string>
#include <vector>

class EquationBase :public IEquation {

public:

	EquationBase();
	virtual std::vector<std::pair<double, bool >> GetRoots()override;

protected:
	std::vector<std::pair<double, bool >> Roots;
	int _a;
	int _b;
	int _c;
};