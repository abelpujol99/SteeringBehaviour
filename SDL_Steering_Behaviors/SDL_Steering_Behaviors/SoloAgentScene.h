#pragma once
#include <vector>
#include "Scene.h"
#include "Agent.h"

class SoloAgentScene : public Scene
{
public:
	SoloAgentScene();
	~SoloAgentScene();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();

private:
	std::vector<Agent*> _agents;
	Vector2D* _target;
};

