#include "EquationBase.h"

EquationBase::EquationBase() :_b(0), _a(0), _c(0) {}

std::vector<std::pair<double, bool >> EquationBase::GetRoots() {
	return Roots;
}
