#pragma once
#include "SteeringBehavior.h"

class BehaviorPattern
{

protected:
    
    std::vector<SteeringBehavior*> _steeringBehaviors;
    
public:

    BehaviorPattern(std::vector<SteeringBehavior*> steeringBehaviors);
    ~BehaviorPattern();
    
    virtual Vector2D CalculateForce(Agent* agent, Vector2D target, float dtime) = 0;
    
    virtual void Accept(Agent* agent) = 0;
};
