#pragma once

class Entity;

class Component
{
public:
	Component(Entity& entity) : entity(entity) {}

protected:
	Entity& entity;
};