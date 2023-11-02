#pragma once

#include <vector>
#include "Observer.h"
class Subject
{
protected:
	std::vector<Observer*> observers;
	virtual void notify() = 0;
public:
	void addObserver(Observer* o);
};
