#include "FleeBehavior.h"

FleeBehavior::FleeBehavior(){}

FleeBehavior::~FleeBehavior(){}

Vector2D FleeBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    Vector2D steering = agent->_position - target;
    steering.Normalize();
    return steering * agent->max_velocity;
}

Vector2D FleeBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->_position, dtime);
}

void FleeBehavior::Accept(Agent* agent)
{
    agent->VisitSteeringBehavior(this);
}
