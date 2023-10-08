#include "MultiAgentScene.h"

#include "FlockingAgent.h"
#include "WeightedBlending.h"

using namespace std;

MultiAgentScene::MultiAgentScene()
{
	srand(time(NULL));
    
	*_target = Vector2D(640,360);
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
		case SDL_MOUSEBUTTONDOWN:
			switch (event->button.button)
			{
				case SDL_BUTTON_LEFT:
					{
						std::vector<SteeringBehavior*> steeringBehaviors {new CohesionBehavior, new AlignmentBehavior, new SeparationBehavior};
						std::vector<float> weigths {COHESION_WEIGHT, ALIGNMENT_WEIGHT, SEPARATION_WEIGHT};
						
						int randomAngle = rand () % 361;
						Vector2D* directionVector = new Vector2D(cosf(randomAngle), sinf(randomAngle));
						
						FlockingAgent* flockingAgent = new FlockingAgent(new WeightedBlending(steeringBehaviors, weigths),
							directionVector,
							Vector2D((float)(event->button.x), (float)(event->button.y)));

						for (FlockingAgent* agent : _agents)
						{
							agent->MeetNewAgent(flockingAgent);
						}
						
						_agents.push_back(flockingAgent);						
					}
					break;
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
	for (Agent* agent : _agents)
	{
		agent->draw();
	}
}

const char* MultiAgentScene::getTitle()
{
	return "SDL Steering Behaviors :: Multi Agent Demo";
}