#pragma once
#include "MultiAgentScene.h"

class PriorityListScene :	public MultiAgentScene
{

private:	
	
public:
    PriorityListScene();
    ~PriorityListScene();
    const char* getTitle();

protected:
    FlockingAgent* CreateAgent(SDL_Event* event) override;
};
