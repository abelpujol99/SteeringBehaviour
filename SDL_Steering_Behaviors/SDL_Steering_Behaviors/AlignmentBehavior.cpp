#include "AlignmentBehavior.h"

AlignmentBehavior::AlignmentBehavior(){}

AlignmentBehavior::~AlignmentBehavior(){}

Vector2D AlignmentBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    FlockingAgent* currentFlockingAgent = static_cast<FlockingAgent*>(agent);

    Vector2D averageVelocity = Vector2D(0, 0);

    int neighborCounter = 0;
    
    for (Agent* agent : currentFlockingAgent->GetFlockingAgents())
    {
        float distance = Vector2D::Distance(agent->getPosition(), currentFlockingAgent->getPosition());
        
        if (distance < currentFlockingAgent->GetNeighborRadius())
        {
            averageVelocity += agent->getVelocity();
            neighborCounter++;
        }
    }

    if (neighborCounter == 0)
    {
        return target;
    }

    currentFlockingAgent->SetAverageVelocity(averageVelocity);

    currentFlockingAgent->setTarget(currentFlockingAgent->CalculateAverageVelocity(neighborCounter).Normalize());
    
    return *currentFlockingAgent->getTarget();
}

Vector2D AlignmentBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return Vector2D();
}