#include "PriorityList.h"


PriorityList::PriorityList(std::vector<WeightedBlending> weightedBlendingGroups) :
                            _weightedBlendingGroups(weightedBlendingGroups)
{
}

PriorityList::~PriorityList(){}


Vector2D PriorityList::CalculateForce(Agent* agent, Vector2D target, float dtime)
{
    Vector2D force = Vector2D(0,0);

    for (int i = 0; i < _weightedBlendingGroups.size(); ++i)
    {
        std::vector<SteeringBehavior*> steeringBehaviors = _weightedBlendingGroups[i].GetSteeringBehaviors();

        std::vector<float> weights = _weightedBlendingGroups[i].GetWeights();

        for (int j = 0; j < steeringBehaviors.size(); ++j)
        {
            force += steeringBehaviors[j]->CalculateForces(agent, target, dtime) * weights[j];
        }

        if (i == 1 && force.Length() > PRIORITY_THRESHOLD)
        {
            return force;
        }
        
    }    
    return force;
}