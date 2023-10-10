#include "CohesionBehavior.h"

CohesionBehavior::CohesionBehavior(){}

CohesionBehavior::~CohesionBehavior(){}

Vector2D CohesionBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    FlockingAgent* currentFlockingAgent = static_cast<FlockingAgent*>(agent);

    int neighborCounter = 0;
    
    Vector2D positionsSum = Vector2D(0, 0);
    
    for (Agent* agent : currentFlockingAgent->GetFlockingAgents())
    {
        float distance = Vector2D::Distance(agent->getPosition(), currentFlockingAgent->getPosition());
        
        if (distance < currentFlockingAgent->GetNeighborRadius())
        {
            positionsSum += agent->getPosition();
            neighborCounter++;
        }
    }

    if (neighborCounter == 0)
    {
        return target;
    }

    currentFlockingAgent->SetAveragePosition(positionsSum - currentFlockingAgent->getPosition());

    return currentFlockingAgent->CalculateAveragePosition(neighborCounter).Normalize();
}

Vector2D CohesionBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->getPosition(), dtime);
}