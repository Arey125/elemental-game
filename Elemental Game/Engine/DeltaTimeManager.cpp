#include "DeltaTimeManager.h"

DeltaTimeManager& DeltaTimeManager::instance()
{
	static DeltaTimeManager *_instance = nullptr;
	if (!_instance)
		_instance = new DeltaTimeManager();
	return *_instance;
}

void DeltaTimeManager::updateDeltaTime()
{
	dTime = clock.restart();
	dt = dTime.asSeconds();
}

DeltaTimeManager::DeltaTimeManager()
	:dTime(sf::milliseconds(10)), dt(dTime.asSeconds())
{
	clock.restart();
}
