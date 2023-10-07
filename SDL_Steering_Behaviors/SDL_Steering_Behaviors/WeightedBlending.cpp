#include "WeightedBlending.h"

WeightedBlending::WeightedBlending(std::vector<SteeringBehavior*> steeringBehaviors, std::vector<float> weights) :
                    BehaviorPattern(steeringBehaviors),
                    _weights(weights){}

Vector2D WeightedBlending::CalculateForce(Agent* agent, Vector2D target, float dtime)
{
    Vector2D force = Vector2D(0,0);

    for (int i = 0; i < _steeringBehaviors.size(); ++i)
    {
        force += _steeringBehaviors[i]->CalculateForces(agent, target, dtime) * _weights[i];
    }    
    return force;
}

void WeightedBlending::Accept(Agent* agent)
{
    agent->VisitBehaviorPattern(this);
}
