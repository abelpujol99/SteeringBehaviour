#pragma once
#include "SteeringBehavior.h"

class FleeBehavior : public SteeringBehavior
{
    
public:

    FleeBehavior();
    ~FleeBehavior();
    
    Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
    Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
};