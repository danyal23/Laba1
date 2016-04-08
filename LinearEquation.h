#pragma once
#include <iostream>
#include "EquationBase.h"
#include <cmath>
#include "IEquation.h"
#include <vector>
class LinearEquation : public EquationBase {
public:
	LinearEquation() = default;
	LinearEquation(int a, int b);
	virtual ~LinearEquation() = default;
	virtual void  CalculateRoot()override;
};