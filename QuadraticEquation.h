#pragma once
#include <cmath>
#include <iostream>
#include "EquationBase.h"

class QuadraticEquation : public  EquationBase {
public:

	QuadraticEquation();
	QuadraticEquation(int a, int b, int c);

	virtual ~QuadraticEquation() = default;

	int CheckDiscriminant();

	int  GetDiscriminant();

	virtual void CalculateRoot()override;

private:
	int _temp;
};
