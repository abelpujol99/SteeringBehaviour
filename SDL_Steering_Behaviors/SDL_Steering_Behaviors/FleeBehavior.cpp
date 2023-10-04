#include "FleeBehavior.h"

FleeBehavior::FleeBehavior(){}

FleeBehavior::~FleeBehavior(){}

Vector2D FleeBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    Vector2D steering = agent->position - target;
    steering.Normalize();
    return steering * agent->max_velocity;
}

Vector2D FleeBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->position, dtime);
}