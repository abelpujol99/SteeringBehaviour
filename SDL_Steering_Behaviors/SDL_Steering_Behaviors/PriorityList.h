#pragma once
#include <vector>

#include "BehaviorPattern.h"
#include "WeightedBlending.h"

#define PRIORITY_THRESHOLD 1

class PriorityList : public BehaviorPattern
{    
private:

    std::vector<WeightedBlending> _weightedBlendingGroups;
    
public:
    
    PriorityList(std::vector<WeightedBlending> weightedBlendingGroups);
    ~PriorityList();
    
    Vector2D CalculateForce(Agent* agent, Vector2D target, float dtime) override;
};
