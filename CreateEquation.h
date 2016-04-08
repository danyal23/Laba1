#pragma once
#include <iostream>
#include "IEquation.h"
#include <vector>
#include <string>

class CreatorOfEquation
{
public:
	IEquation* Create(const std::string& _equation);

protected:
	std::vector<int> Storage;
	std::vector<int> Powers;
private:
	int ExtractPower(const std::string& s, int& pos);
	int ExtractCoefficient(const std::string& s, int& pos);
};