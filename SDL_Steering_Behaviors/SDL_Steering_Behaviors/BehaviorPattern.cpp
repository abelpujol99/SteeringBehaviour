#include "BehaviorPattern.h"

BehaviorPattern::BehaviorPattern(std::vector<SteeringBehavior*> steeringBehaviors)
{
    _steeringBehaviors = steeringBehaviors;
}

BehaviorPattern::~BehaviorPattern()
{
    for (SteeringBehavior* steeringBehavior : _steeringBehaviors)
    {
        delete steeringBehavior;
    }
}
