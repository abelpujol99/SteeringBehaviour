#pragma once
#include <iostream>
#include <SDL.h>

#define SEPARATION_WEIGHT 0.33f 
#define COHESION_WEIGHT 0.33f
#define ALIGNMENT_WEIGHT 0.33f

class Scene
{
	
public:
	Scene() {};
	virtual ~Scene() {};
	virtual void update(float dtime, SDL_Event *event) = 0;
	virtual void draw() = 0;
	virtual const char* getTitle() { return ""; };
	
};

