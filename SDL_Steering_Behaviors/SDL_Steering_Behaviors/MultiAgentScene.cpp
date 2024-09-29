#include "MultiAgentScene.h"

#include "FlockingAgent.h"
#include "WeightedBlending.h"

using namespace std;

MultiAgentScene::MultiAgentScene()
{
	srand(time(NULL));
    
	*_target = Vector2D(640,360);
	SetupObstacles();
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
						FlockingAgent* flockingAgent = CreateAgent(event);

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

void MultiAgentScene::SetupObstacles() {
	std::vector<Vector2D> vertices;
	vertices.push_back(Vector2D(-100, -150));
	vertices.push_back(Vector2D(-120, 30));
	vertices.push_back(Vector2D(0, 100));
	vertices.push_back(Vector2D(120, 30));
	vertices.push_back(Vector2D(100, -150));
	_obstacles.push_back(new Obstacle(vertices, Vector2D(200, 500), new Vector2D(200, 500)));

	vertices.clear();
	vertices.push_back(Vector2D(65, -35));
	vertices.push_back(Vector2D(-35, -65));
	vertices.push_back(Vector2D(-65, 35));
	vertices.push_back(Vector2D(35, 65));
	_obstacles.push_back(new Obstacle(vertices, Vector2D(1100, 100), new Vector2D(1100, 100)));

	vertices.clear();
	vertices.push_back(Vector2D(150, 195));
	vertices.push_back(Vector2D(75, 60));
	vertices.push_back(Vector2D(180, -45));
	vertices.push_back(Vector2D(60, -37));
	vertices.push_back(Vector2D(0, -150));
	vertices.push_back(Vector2D(-60, -37));
	vertices.push_back(Vector2D(-180, -45));
	vertices.push_back(Vector2D(-75, 60));
	vertices.push_back(Vector2D(-150, 195));
	vertices.push_back(Vector2D(0, 105));
	_obstacles.push_back(new Obstacle(vertices, Vector2D(800, 500), new Vector2D(800, 500)));
}