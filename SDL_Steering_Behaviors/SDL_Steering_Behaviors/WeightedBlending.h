#pragma once
#include <vector>

#include "BehaviorPattern.h"
#include "Agent.h"

class WeightedBlending : public BehaviorPattern
{
    
private:

    std::vector<float> _weights;

public:

    WeightedBlending(std::vector<SteeringBehavior*> steeringBehaviors, std::vector<float> weights);
    ~WeightedBlending();
    
    Vector2D CalculateForce(Agent* agent, Vector2D target, float dtime) override;

    std::vector<SteeringBehavior*> GetSteeringBehaviors();
    std::vector<float> GetWeights();
};
