#include "WeightedBlendingScene.h"

#include "FlockingAgent.h"
#include "WeightedBlending.h"

using namespace std;

WeightedBlendingScene::WeightedBlendingScene()
{
	srand(time(NULL));
    
	*_target = Vector2D(640,360);
	SetupObstacles();
}

WeightedBlendingScene::~WeightedBlendingScene()
{
	for (int i = 0; i < _agents.size(); ++i)
	{
		delete _agents[i];
	}

	delete _target;
	delete _averagePosition;
}
const char* WeightedBlendingScene::getTitle()
{
	return "SDL Steering Behaviors :: Weighted Blending Multi Agent Demo";
}

FlockingAgent* WeightedBlendingScene::CreateAgent(SDL_Event* event)
{
	std::vector<SteeringBehavior*> steeringBehaviors {new CohesionBehavior, new AlignmentBehavior, new SeparationBehavior, new ObstacleAvoidanceBehavior(_obstacles)};						
	std::vector<float> weigths {COHESION_WEIGHT, ALIGNMENT_WEIGHT, SEPARATION_WEIGHT, OBSTACLE_AVOIDANCE_WEIGHT};
						
	float randomAngle = rand () % 360;
	Vector2D* directionVector = new Vector2D(cosf(randomAngle), sinf(randomAngle));
						
	return new FlockingAgent(new WeightedBlending(steeringBehaviors, weigths),
		directionVector,
		Vector2D((float)(event->button.x), (float)(event->button.y)));
}
