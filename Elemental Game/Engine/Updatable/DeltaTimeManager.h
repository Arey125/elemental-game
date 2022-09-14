#pragma once

#include <SFML/System.hpp>

class DeltaTimeManager
{
public:
	static DeltaTimeManager& instance();

	void updateDeltaTime();

	friend class Updatable;
private:
	DeltaTimeManager();

	sf::Clock clock;
	sf::Time dTime;
	float dt;
};

