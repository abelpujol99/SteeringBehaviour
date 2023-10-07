#pragma once
#include <vector>
#include "Scene.h"
#include "AlignmentBehavior.h"
#include "CohesionBehavior.h"
#include "SeparationBehavior.h"


#define TOTAL_AGENTS 5
#define NEIGHBORHOOD_RADIUS 50


class MultiAgentScene :	public Scene
{

private:	
	std::vector<Agent*> _agents;

	Vector2D* _target = new Vector2D(0,0);
	Vector2D* _averagePosition = new Vector2D(0, 0);

	int _neighborCount = 0;
	
	
public:
	MultiAgentScene();
	~MultiAgentScene();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();
};

