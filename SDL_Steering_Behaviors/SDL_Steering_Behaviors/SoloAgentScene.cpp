
#include "SoloAgentScene.h"

#include "FleeBehavior.h"
#include "SeekBehavior.h"
#include "UniqueBehaviorAgent.h"
#include "WeightedBlending.h"

using namespace std;

SoloAgentScene::SoloAgentScene()
{	
	_target = new Vector2D(640, 360);
	std::vector<SteeringBehavior*> steeringBehaviors {new SeekBehavior, new FleeBehavior};
	std::vector<float> weights {1, 0};
	Agent* agent = new UniqueBehaviorAgent(steeringBehaviors, Vector2D(640,360), _target);
	//agent->loadSpriteTexture("../res/soldier.png", 4);
	agents.push_back(agent);
}

SoloAgentScene::~SoloAgentScene()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SoloAgentScene::update(float dtime, SDL_Event *event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
		case SDL_MOUSEMOTION:
		case SDL_MOUSEBUTTONDOWN:
			if (event->button.button == SDL_BUTTON_LEFT)
			{
				*_target = Vector2D((float)(event->button.x), (float)(event->button.y));
			}
			break;
		default:
			break;
	}
	
	agents[0]->update(dtime, event);
}

void SoloAgentScene::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)_target->x, (int)_target->y, 15, 255, 0, 0, 255);
	agents[0]->draw();
}

const char* SoloAgentScene::getTitle()
{
	return "SDL Steering Behaviors :: Solo Agent Demo";
}