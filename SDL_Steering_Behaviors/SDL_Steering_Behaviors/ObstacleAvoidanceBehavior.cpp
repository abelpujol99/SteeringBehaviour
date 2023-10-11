#include "ObstacleAvoidanceBehavior.h"

ObstacleAvoidanceBehavior::ObstacleAvoidanceBehavior(){}

ObstacleAvoidanceBehavior::~ObstacleAvoidanceBehavior(){}

Vector2D ObstacleAvoidanceBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    FlockingAgent* currentFlockingAgent = static_cast<FlockingAgent*>(agent);

    int neighborCounter = 0;
    
    Vector2D xdd = Vector2D(-1, 0);

    return xdd;
}

Vector2D ObstacleAvoidanceBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->getPosition(), dtime);
}