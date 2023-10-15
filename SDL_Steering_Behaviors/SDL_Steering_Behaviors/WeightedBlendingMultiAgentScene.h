#pragma once
#include <vector>
#include "Scene.h"
#include "AlignmentBehavior.h"
#include "CohesionBehavior.h"
#include "FlockingAgent.h"
#include "SeparationBehavior.h"
#include "ObstacleAvoidanceBehavior.h"
#include "Obstacle.h"

class WeightedBlendingMultiAgentScene :	public Scene
{

private:	
	std::vector<FlockingAgent*> _agents;
	std::vector<Obstacle*> _obstacles;

	Vector2D* _target = new Vector2D(0,0);
	Vector2D* _averagePosition = new Vector2D(0, 0);
	
	void SetupObstacles();
	FlockingAgent* CreateAgent(SDL_Event* event);
	
public:
	WeightedBlendingMultiAgentScene();
	~WeightedBlendingMultiAgentScene();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();

};

