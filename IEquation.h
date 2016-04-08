#pragma once
#include <vector>
#include <iostream>
class IEquation {
public:
	IEquation() = default;
	virtual ~IEquation() = default;
	virtual void CalculateRoot() = 0;
	virtual std::vector<std::pair<double, bool >> GetRoots() = 0;
};