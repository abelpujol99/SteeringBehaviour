#pragma once
#include "SteeringBehavior.h"
class SeparationBehavior : public SteeringBehavior
{

	SeparationBehavior();
	~SeparationBehavior();

	Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
	Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
};