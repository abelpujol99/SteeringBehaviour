#include "PriorityListScene.h"

#include "FlockingAgent.h"
#include "PriorityList.h"
#include "WeightedBlending.h"

using namespace std;

PriorityListScene::PriorityListScene()
{
	srand(time(NULL));
    
	*_target = Vector2D(640,360);
	SetupObstacles();
}

PriorityListScene::~PriorityListScene()
{
	for (int i = 0; i < _agents.size(); ++i)
	{
		delete _agents[i];
	}

	delete _target;
	delete _averagePosition;
}

FlockingAgent* PriorityListScene::CreateAgent(SDL_Event* event)
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

const char* PriorityListScene::getTitle()
{
	return "SDL Steering Behaviors :: Priority List Multi Agent Demo";
}