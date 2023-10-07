#pragma once
#include "SteeringBehavior.h"

class AlignmentBehavior : public SteeringBehavior
{
	
public:
	
	AlignmentBehavior();
	~AlignmentBehavior();

	Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
	Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
	void Accept(Agent* agent) override;
};