#include "ObstacleAvoidanceBehavior.h"

ObstacleAvoidanceBehavior::ObstacleAvoidanceBehavior(std::vector<Obstacle*> obstacles)
{
    _obstacles = obstacles;
}

ObstacleAvoidanceBehavior::~ObstacleAvoidanceBehavior(){}

Vector2D ObstacleAvoidanceBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    FlockingAgent* currentFlockingAgent = static_cast<FlockingAgent*>(agent);

    Vector2D dir = currentFlockingAgent->getVelocity();
    dir = dir.Normalize();
    Vector2D raycastVector = dir * avoidanceLookahead;
    //std::cout << currentFlockingAgent->getPosition().x << ", " <<currentFlockingAgent->getPosition().y << " - " << currentFlockingAgent->getVelocity().Normalize().x << ", " << currentFlockingAgent->getVelocity().Normalize().y << " - " << raycastVector.x << ", " << raycastVector.y << std::endl;
    Vector2D intersectionPoint, normalVector;
    bool obstacleCollision = false;
    
    for (int i = 0; i < _obstacles.size(); i++) {
        obstacleCollision = _obstacles[i]->IntersectSegment(currentFlockingAgent->getPosition(), raycastVector, intersectionPoint, normalVector);
        if (obstacleCollision) break;
    }

    Vector2D ret = Vector2D(0.f, 0.f);
    if (obstacleCollision) {
        ret = normalVector;
        //std::cout << ret.x << ", " << ret.y << std::endl;
    }
    
    return ret;
}

Vector2D ObstacleAvoidanceBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->getPosition(), dtime);
}