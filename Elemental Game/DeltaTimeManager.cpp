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
	dt = clock.getElapsedTime().asSeconds();
	clock.restart();
}

DeltaTimeManager::DeltaTimeManager()
	:dt(0.01)
{
	clock.restart();
}
