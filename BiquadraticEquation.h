#pragma once
#include "QuadraticEquation.h"


class BiquadraticEquation : public QuadraticEquation {
public:

	BiquadraticEquation();
	BiquadraticEquation(int a, int b, int c);

	virtual ~BiquadraticEquation() = default;
	virtual void CalculateRoot()override;

private:
	double _t, _t1;
};