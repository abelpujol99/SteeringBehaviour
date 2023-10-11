#pragma once
#include "SteeringBehavior.h"
#include "FlockingAgent.h"
#include "Obstacle.h"

class ObstacleAvoidanceBehavior : public SteeringBehavior
{
	
public:
	
	float avoidanceLookahead = 30.f;
	std::vector<Obstacle*> _obstacles;

	ObstacleAvoidanceBehavior(std::vector<Obstacle*> obstacles);
	~ObstacleAvoidanceBehavior();
	
	Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
	Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
};
