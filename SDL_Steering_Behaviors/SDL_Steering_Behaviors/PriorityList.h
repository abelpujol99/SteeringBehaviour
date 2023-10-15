#pragma once
#include <vector>

#include "BehaviorPattern.h"
#include "Agent.h"
#include "SteeringBehavior.h"
#include "WeightedBlending.h"

#define PRIORITY_THRESHOLD 1

class PriorityList : public BehaviorPattern
{    
private:

    int instanceId;
    std::vector<WeightedBlending> _weightedBlendingGroups;
    
public:

    static int currentId;
    PriorityList(std::vector<WeightedBlending> weightedBlendingGroups);
    ~PriorityList();
    
    Vector2D CalculateForce(Agent* agent, Vector2D target, float dtime) override;
};
