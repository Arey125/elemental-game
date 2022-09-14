#include "Updatable.h"

Updatable::Updatable()
	:dt(DeltaTimeManager::instance().dt),
	dTime(DeltaTimeManager::instance().dTime)
{

}