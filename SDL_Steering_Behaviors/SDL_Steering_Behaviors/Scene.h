#pragma once
#include <iostream>
#include <SDL.h>

#define SEPARATION_WEIGHT 4000 
#define COHESION_WEIGHT 4000
#define ALIGNMENT_WEIGHT 800

class Scene
{
	
public:
	Scene() {};
	virtual ~Scene() {};
	virtual void update(float dtime, SDL_Event *event) = 0;
	virtual void draw() = 0;
	virtual const char* getTitle() { return ""; };	
};