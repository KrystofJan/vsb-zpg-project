#include "Subject.h"

void Subject::addObserver(Observer* o)
{
	this->observers.push_back(o);
}
