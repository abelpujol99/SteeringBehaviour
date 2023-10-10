#include "SeparationBehavior.h"

SeparationBehavior::SeparationBehavior(){}

SeparationBehavior::~SeparationBehavior(){}

Vector2D SeparationBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{    
    FlockingAgent* currentFlockingAgent = static_cast<FlockingAgent*>(agent);

    Vector2D separationVector = Vector2D(0, 0);

    int neighborCounter = 0;
    
    for (Agent* otherAgent : currentFlockingAgent->GetFlockingAgents())
    {
        float distance = Vector2D::Distance(otherAgent->getPosition(), currentFlockingAgent->getPosition());
        
        if (distance < currentFlockingAgent->GetNeighborRadius())
        {
            separationVector += currentFlockingAgent->getPosition() - otherAgent->getPosition();
            neighborCounter++;
        }
    }

    if (neighborCounter == 0)
    {
        return target;
    }

    currentFlockingAgent->SetSeparationVector(separationVector);

    return currentFlockingAgent->CalculateSeparationVector(neighborCounter).Normalize();
}

Vector2D SeparationBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->getPosition(), dtime);
}