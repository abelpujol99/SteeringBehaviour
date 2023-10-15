#pragma once
#include "Agent.h"

class Obstacle : public Agent
{
private:
	std::vector<Vector2D> _vertices;


public:
	Obstacle(std::vector<Vector2D>& vertices, Vector2D initialPosition, Vector2D* target);
	~Obstacle();
	bool IntersectSegment(Vector2D pos, Vector2D raycastVector, Vector2D& intersectionPoint, Vector2D& normalVector);
	virtual void update(float dtime, SDL_Event* event) override;
	void draw() override;
};

