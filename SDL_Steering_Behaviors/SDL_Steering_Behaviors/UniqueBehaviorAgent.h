#pragma once
#include "Agent.h"

class UniqueBehaviorAgent : public Agent
{

private:

    std::vector<SteeringBehavior*> _steeringBehaviors;
	
	bool _seekBehavior;
	
	int _modeSelected;
    
public:

	UniqueBehaviorAgent(std::vector<SteeringBehavior*> steeringBehaviors, Vector2D initialPosition, Vector2D* target);
	~UniqueBehaviorAgent();
	
    void update(float dtime, SDL_Event* event) override;
};