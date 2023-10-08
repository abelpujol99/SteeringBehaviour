#include "PriorityList.h"

PriorityList::PriorityList(std::vector<SteeringBehavior*> steeringBehaviors) : BehaviorPattern(steeringBehaviors)
{
}

PriorityList::~PriorityList()
{
}

Vector2D PriorityList::CalculateForce(Agent* agent, Vector2D target, float dtime)
{
    return Vector2D();
}