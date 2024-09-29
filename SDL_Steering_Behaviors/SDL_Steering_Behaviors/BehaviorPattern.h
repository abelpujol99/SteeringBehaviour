#pragma once
#include "SteeringBehavior.h"
#include "Agent.h"

class BehaviorPattern
{

protected:

    std::vector<SteeringBehavior*> _steeringBehaviors;
    
public:

    BehaviorPattern();
    BehaviorPattern(std::vector<SteeringBehavior*> steeringBehaviors);
    virtual ~BehaviorPattern();
    
    virtual Vector2D CalculateForce(Agent* agent, Vector2D target, float dtime) = 0;
};
