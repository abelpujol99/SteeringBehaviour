#pragma once
#include "Agent.h"
#include <iostream>

class Obstacle : public Agent
{
protected:
	std::vector<Vector2D> _vertices;


public:
	Obstacle(std::vector<Vector2D>& vertices, Vector2D initialPosition, Vector2D* target);
	bool IntersectSegment(Vector2D pos, Vector2D raycastVector, Vector2D& intersectionPoint, Vector2D& normalVector);
	virtual void update(float dtime, SDL_Event* event) override;
	void draw() override;
};

