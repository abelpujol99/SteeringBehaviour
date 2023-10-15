#include "PriorityListMultiAgentScene.h"

#include "FlockingAgent.h"
#include "PriorityList.h"
#include "WeightedBlending.h"

using namespace std;

PriorityListMultiAgentScene::PriorityListMultiAgentScene()
{
	srand(time(NULL));
    
	*_target = Vector2D(640,360);
	SetupObstacles();
}

PriorityListMultiAgentScene::~PriorityListMultiAgentScene()
{
	for (int i = 0; i < _agents.size(); ++i)
	{
		delete _agents[i];
	}

	delete _target;
	delete _averagePosition;
}

void PriorityListMultiAgentScene::update(float dtime, SDL_Event *event)
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

void PriorityListMultiAgentScene::draw()
{	
	for (Agent* agent : _agents)
	{
		agent->draw();
	}
	for (Obstacle* obstacle : _obstacles) {
		obstacle->draw();
	}
}

void PriorityListMultiAgentScene::SetupObstacles() {
	std::vector<Vector2D> vertices;
	
	vertices.reserve(5);
	vertices.push_back(Vector2D(-100, -150));
	vertices.push_back(Vector2D(-120, 30));
	vertices.push_back(Vector2D(0, 100));
	vertices.push_back(Vector2D(120, 30));
	vertices.push_back(Vector2D(100, -150));
	_obstacles.push_back(new Obstacle(vertices, Vector2D(200, 500), new Vector2D(200, 500)));
	vertices.clear();
	
	vertices.reserve(4);
	vertices.push_back(Vector2D(65, -35));
	vertices.push_back(Vector2D(-35, -65));
	vertices.push_back(Vector2D(-65, 35));
	vertices.push_back(Vector2D(35, 65));
	_obstacles.push_back(new Obstacle(vertices, Vector2D(1100, 100), new Vector2D(1100, 100)));
	vertices.clear();
	
	vertices.reserve(10);
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

const char* PriorityListMultiAgentScene::getTitle()
{
	return "SDL Steering Behaviors :: Priority List Multi Agent Demo";
}

int PriorityList::currentId = 0;
int BehaviorPattern::currentId = 0;

FlockingAgent* PriorityListMultiAgentScene::CreateAgent(SDL_Event* event)
{
	std::vector<SteeringBehavior*> flockingSteeringBehaviorsGroup {new CohesionBehavior, new AlignmentBehavior, new SeparationBehavior};
	std::vector<float> flockingWeights {COHESION_WEIGHT, ALIGNMENT_WEIGHT, SEPARATION_WEIGHT};
						
	std::vector<SteeringBehavior*> avoidanceSteeringBehaviorsGroup {new ObstacleAvoidanceBehavior(_obstacles)};
	std::vector<float> avoidanceWeights {OBSTACLE_AVOIDANCE_WEIGHT};

	WeightedBlending flockingGroup(flockingSteeringBehaviorsGroup, flockingWeights);
	WeightedBlending avoidanceGroup (avoidanceSteeringBehaviorsGroup, avoidanceWeights);

	std::vector<WeightedBlending> weightedBlendingGroups;

	weightedBlendingGroups.push_back(avoidanceGroup);
	weightedBlendingGroups.push_back(flockingGroup);

	//PriorityList* priority_list = new PriorityList(weightedBlendingGroups);
						
	float randomAngle = rand () % 360;
	Vector2D* directionVector = new Vector2D(cosf(randomAngle), sinf(randomAngle));
						
	FlockingAgent* flockingAgent = new FlockingAgent(new PriorityList(weightedBlendingGroups),
		directionVector,
		Vector2D((float)(event->button.x), (float)(event->button.y)));

	weightedBlendingGroups.clear();
	
	return flockingAgent;	
}