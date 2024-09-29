#include "SeekBehavior.h"

SeekBehavior::SeekBehavior(){}

SeekBehavior::~SeekBehavior(){}

Vector2D SeekBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    Vector2D steering = target - agent->getPosition();
    steering.Normalize();
    return steering * agent->getMaxVelocity();
}

Vector2D SeekBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->getPosition(), dtime);
}