#include "MultiAgentScene.h"

#include "WeightedBlending.h"

using namespace std;

MultiAgentScene::MultiAgentScene()
{
	srand(time(NULL));
    
	for (int i = 0; i < TOTAL_AGENTS; i++)
	{
		std::vector<SteeringBehavior*> steeringBehaviors {new CohesionBehavior, new AlignmentBehavior, new SeparationBehavior};
		std::vector<float> weigths {COHESION_WEIGHT, ALIGNMENT_WEIGHT, SEPARATION_WEIGHT};
		_agents.push_back(new Agent(new WeightedBlending(steeringBehaviors, weigths), _target));
		_agents[i]->setPosition(Vector2D(rand() % 1280, rand() % 768));
		*_target += _agents[i]->getPosition();
	}

	*_target /= TOTAL_AGENTS;
}

MultiAgentScene::~MultiAgentScene()
{
	for (int i = 0; i < _agents.size(); ++i)
	{
		delete _agents[i];
	}

	delete _target;
	delete _averagePosition;
}

void MultiAgentScene::update(float dtime, SDL_Event *event)
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

	for (Agent* agent : _agents)
	{
		agent->update(dtime, event);
	}
}

void MultiAgentScene::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)_target->x, (int)_target->y, NEIGHBORHOOD_RADIUS, 255, 0, 0, 255);
	
	for (Agent* agent : _agents)
	{
		agent->draw();
	}
}

const char* MultiAgentScene::getTitle()
{
	return "SDL Steering Behaviors :: Multi Agent Demo";
}