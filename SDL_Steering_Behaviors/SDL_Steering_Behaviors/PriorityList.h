#pragma once
#include <vector>

#include "BehaviorPattern.h"
#include "SteeringBehavior.h"

class PriorityList : public BehaviorPattern
{

private:
    
public:

    PriorityList(std::vector<SteeringBehavior*> steeringBehaviors);
    ~PriorityList();
    
    Vector2D CalculateForce(Agent* agent, Vector2D target, float dtime) override;
};
