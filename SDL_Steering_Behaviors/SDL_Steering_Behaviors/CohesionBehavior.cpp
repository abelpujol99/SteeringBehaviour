#include "CohesionBehavior.h"

CohesionBehavior::CohesionBehavior()
{
}

CohesionBehavior::~CohesionBehavior()
{
}

Vector2D CohesionBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    return Vector2D();
}

Vector2D CohesionBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return Vector2D();
}
