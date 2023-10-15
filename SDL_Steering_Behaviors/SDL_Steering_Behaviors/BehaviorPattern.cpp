#include "BehaviorPattern.h"


BehaviorPattern::BehaviorPattern()
{
    currentId = instanceId++;
}

BehaviorPattern::BehaviorPattern(std::vector<SteeringBehavior*> steeringBehaviors) : _steeringBehaviors(steeringBehaviors)
{
}

BehaviorPattern::~BehaviorPattern()
{
    for (SteeringBehavior* steeringBehavior : _steeringBehaviors)
    {
        delete steeringBehavior;
    }
}