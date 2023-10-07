#include "AlignmentBehavior.h"

AlignmentBehavior::AlignmentBehavior()
{
}

AlignmentBehavior::~AlignmentBehavior()
{
}

Vector2D AlignmentBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    return Vector2D();
}

Vector2D AlignmentBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return Vector2D();
}

void AlignmentBehavior::Accept(Agent* agent)
{
    agent->VisitSteeringBehavior(this);
}
