#include "SeparationBehavior.h"

SeparationBehavior::SeparationBehavior()
{
}

SeparationBehavior::~SeparationBehavior()
{
}

Vector2D SeparationBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    return Vector2D();
}

Vector2D SeparationBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return Vector2D();
}

void SeparationBehavior::Accept(Agent* agent)
{
    agent->VisitSteeringBehavior(this);
}
