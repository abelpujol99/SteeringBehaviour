#pragma once
#include "Agent.h"
#include "BehaviorPattern.h"

#define NEIGHBOR_RADIUS 100

class FlockingAgent : public Agent
{
private:

	std::vector<FlockingAgent*> _flockingAgents;
	
    BehaviorPattern* _behaviorPattern;	

	Vector2D* _direction;
	Vector2D* _averageNeighborPosition;
	Vector2D* _separationDirection;
	Vector2D* _averageNeighborVelocity;
    
public:

	FlockingAgent(BehaviorPattern* behaviorPattern, Vector2D* direction, Vector2D initialPosition);
	~FlockingAgent();

	float GetNeighborRadius();
	std::vector<FlockingAgent*> GetFlockingAgents();	

	void MeetNewAgent(FlockingAgent* flockingAgent);
	void update(float dtime, SDL_Event* event) override;

	Vector2D CalculateAveragePosition(int neighborCount);
	Vector2D CalculateSeparationVector(int neighborCount);
	Vector2D CalculateAverageVelocity(int neighborCount);
	void ModifyNeighborCount(int modifier);

	Vector2D GetDirection();
	
	void SetAveragePosition(Vector2D averagePosition);	
	Vector2D GetAveragePosition();

	void SetSeparationVector(Vector2D separationVector);
	Vector2D GetSeparationVector();

	void SetAverageVelocity(Vector2D averageVelocity);
	Vector2D GetAverageVelocity();
};
