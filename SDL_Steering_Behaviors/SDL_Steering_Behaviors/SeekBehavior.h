#pragma once
#include "SteeringBehavior.h"

class SeekBehavior : public SteeringBehavior
{
    
public:
    
    SeekBehavior();
    ~SeekBehavior();
    
    Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
    Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
    void Accept(Agent* agent) override;
};