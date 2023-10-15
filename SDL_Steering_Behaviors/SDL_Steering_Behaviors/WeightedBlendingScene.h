#pragma once
#include "MultiAgentScene.h"

class WeightedBlendingScene :	public MultiAgentScene
{

private:	
	FlockingAgent* CreateAgent(SDL_Event* event) override;
	
public:
	WeightedBlendingScene();
	~WeightedBlendingScene();
	const char* getTitle();

};

