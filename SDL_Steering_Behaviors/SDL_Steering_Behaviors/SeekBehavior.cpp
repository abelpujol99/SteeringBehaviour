#include "SeekBehavior.h"

SeekBehavior::SeekBehavior(){}

SeekBehavior::~SeekBehavior(){}

Vector2D SeekBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    Vector2D steering = target - agent->position;
    steering.Normalize();
    return steering * agent->max_velocity;
}

Vector2D SeekBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->position, dtime);
}