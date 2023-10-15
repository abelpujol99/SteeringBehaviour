#pragma once
#include "SteeringBehavior.h"

class BehaviorPattern
{

protected:

    int instanceId;
    std::vector<SteeringBehavior*> _steeringBehaviors;
    
public:

    static int currentId;

    BehaviorPattern();
    BehaviorPattern(std::vector<SteeringBehavior*> steeringBehaviors);
    virtual ~BehaviorPattern();
    
    virtual Vector2D CalculateForce(Agent* agent, Vector2D target, float dtime) = 0;
};
