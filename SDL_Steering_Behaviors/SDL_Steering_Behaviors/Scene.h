#pragma once
#include <iostream>
#include <SDL.h>

#define SEPARATION_WEIGHT 57 
#define COHESION_WEIGHT 10
#define ALIGNMENT_WEIGHT 47
#define OBSTACLE_AVOIDANCE_WEIGHT 500

class Scene
{
	
public:
	Scene() {};
	virtual ~Scene() {};
	virtual void update(float dtime, SDL_Event *event) = 0;
	virtual void draw() = 0;
	virtual const char* getTitle() { return ""; };	
};