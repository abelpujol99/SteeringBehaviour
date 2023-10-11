#include "MultiAgentScene.h"

#include "FlockingAgent.h"
#include "WeightedBlending.h"

using namespace std;

MultiAgentScene::MultiAgentScene()
{
	srand(time(NULL));
    
	*_target = Vector2D(640,360);
	std::vector<Vector2D> vertices;
	vertices.push_back(Vector2D(-100, -100));
	vertices.push_back(Vector2D(-100, 100));
	vertices.push_back(Vector2D(100, 100));
	vertices.push_back(Vector2D(100, -100));
	_obstacles.push_back(new Obstacle(vertices, Vector2D(500,500), new Vector2D(500, 500)));
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
						std::vector<SteeringBehavior*> steeringBehaviors {new CohesionBehavior, new AlignmentBehavior, new SeparationBehavior, new ObstacleAvoidanceBehavior(_obstacles)};
						std::vector<float> weigths {COHESION_WEIGHT, ALIGNMENT_WEIGHT, SEPARATION_WEIGHT, OBSTACLE_AVOIDANCE_WEIGHT};
						
						int randomAngle = rand () % 360;
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
	for (Obstacle* obstacle : _obstacles) {
		obstacle->draw();
	}
}

const char* MultiAgentScene::getTitle()
{
	return "SDL Steering Behaviors :: Multi Agent Demo";
}