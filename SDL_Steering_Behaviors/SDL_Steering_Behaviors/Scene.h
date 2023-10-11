#pragma once
#include <iostream>
#include <SDL.h>

#define SEPARATION_WEIGHT 57 
#define COHESION_WEIGHT 10
#define ALIGNMENT_WEIGHT 30
#define OBSTACLE_AVOIDANCE_WEIGHT 1000

class Scene
{
	
public:
	Scene() {};
	virtual ~Scene() {};
	virtual void update(float dtime, SDL_Event *event) = 0;
	virtual void draw() = 0;
	virtual const char* getTitle() { return ""; };	
};