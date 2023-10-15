#include "FlockingAgent.h"

FlockingAgent::FlockingAgent(BehaviorPattern* behaviorPattern, Vector2D* target, Vector2D initialPosition) :
                _averageNeighborPosition(new Vector2D(0)),
                _separationDirection(new Vector2D(0)),
                _averageNeighborVelocity(new Vector2D(0)),
                _behaviorPattern(std::move(behaviorPattern)),
                Agent(initialPosition, target)
{}

FlockingAgent::~FlockingAgent()
{
    delete _behaviorPattern;
}

float FlockingAgent::GetNeighborRadius()
{
    return NEIGHBOR_RADIUS;
}

std::vector<FlockingAgent*> FlockingAgent::GetFlockingAgents()
{
    return _flockingAgents;
}

void FlockingAgent::MeetNewAgent(FlockingAgent* flockingAgent)
{
    _flockingAgents.push_back(flockingAgent);
}

void FlockingAgent::update(float dtime, SDL_Event* event)
{
    //cout << "agent update:" << endl;

    switch (event->type) {
        /* Keyboard & Mouse events */
        case SDL_KEYDOWN:
            if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
            {
                draw_sprite = !draw_sprite;	
            }				
        break;
    default:
        break;
    }

    Vector2D steeringForce = _behaviorPattern->CalculateForce(this, *_target, dtime);

    Vector2D acceleration = steeringForce / mass;
    
    _velocity = _velocity + acceleration * 10 * dtime;
    _velocity = _velocity.Truncate(max_velocity);

    _position = _position + _velocity * dtime;


    // Update orientation
    orientation = (float)(atan2(_velocity.y, _velocity.x) * RAD2DEG);


    // Trim position values to window size
    if (_position.x < 0) _position.x = TheApp::Instance()->getWinSize().x;
    if (_position.y < 0) _position.y = TheApp::Instance()->getWinSize().y;
    if (_position.x > TheApp::Instance()->getWinSize().x) _position.x = 0;
    if (_position.y > TheApp::Instance()->getWinSize().y) _position.y = 0;
}

Vector2D FlockingAgent::CalculateAveragePosition(int neighborCount)
{
    return *_averageNeighborPosition = *_averageNeighborPosition / neighborCount;
}

Vector2D FlockingAgent::CalculateSeparationVector(int neighborCount)
{
    return *_separationDirection = *_separationDirection / neighborCount;
}

Vector2D FlockingAgent::CalculateAverageVelocity(int neighborCount)
{
    return *_averageNeighborVelocity = *_averageNeighborVelocity / neighborCount;
}

void FlockingAgent::SetAveragePosition(Vector2D averagePosition)
{
    *_averageNeighborPosition = averagePosition;
}

Vector2D FlockingAgent::GetAveragePosition()
{
    return *_averageNeighborPosition;
}

void FlockingAgent::SetSeparationVector(Vector2D separationVector)
{
    *_separationDirection = separationVector;
}

Vector2D FlockingAgent::GetSeparationVector()
{
    return *_separationDirection;
}

void FlockingAgent::SetAverageVelocity(Vector2D averageVelocity)
{
    *_averageNeighborVelocity = averageVelocity;
}

Vector2D FlockingAgent::GetAverageVelocity()
{
    return *_averageNeighborVelocity;
}