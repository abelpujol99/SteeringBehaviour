#pragma once
#include "SteeringBehavior.h"
class AlignmentBehavior : public SteeringBehavior
{
	AlignmentBehavior();
	~AlignmentBehavior();

	Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
	Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
};