#pragma once

#include "DeltaTimeManager.h"
#include <vector>

class Updatable
{
public:
	Updatable();

	virtual void update() = 0;

protected:
	float& dt;
};

