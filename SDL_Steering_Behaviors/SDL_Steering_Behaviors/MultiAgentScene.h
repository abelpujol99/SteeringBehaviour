#pragma once
#include <vector>
#include "AlignmentBehavior.h"
#include "CohesionBehavior.h"
#include "FlockingAgent.h"
#include "SeparationBehavior.h"
#include "ObstacleAvoidanceBehavior.h"
#include "Obstacle.h"

class MultiAgentScene :	public Scene
{

protected:	
	std::vector<FlockingAgent*> _agents;
	std::vector<Obstacle*> _obstacles;

	Vector2D* _target = new Vector2D(0,0);
	Vector2D* _averagePosition = new Vector2D(0, 0);

	virtual FlockingAgent* CreateAgent(SDL_Event* event) = 0;
	void SetupObstacles();
	
public:
	MultiAgentScene();
	~MultiAgentScene();
	void update(float dtime, SDL_Event *event);
	void draw();
	virtual const char* getTitle() = 0;
};

