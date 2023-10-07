#include "CohesionBehavior.h"

CohesionBehavior::CohesionBehavior(){}

CohesionBehavior::~CohesionBehavior(){}

Vector2D CohesionBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    Vector2D steering = target - agent->_position;
    steering.Normalize();
    return steering * agent->max_velocity;
}

Vector2D CohesionBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->_position, dtime);
}

void CohesionBehavior::Accept(Agent* agent)
{
    agent->VisitSteeringBehavior(this);
}
