#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"

class Renderable
{
public:
	Renderable();
	
	virtual void render() = 0;

protected:
	sf::RenderTarget& renderTarget;
};

