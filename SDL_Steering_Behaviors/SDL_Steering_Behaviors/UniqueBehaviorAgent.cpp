#include "UniqueBehaviorAgent.h"

UniqueBehaviorAgent::UniqueBehaviorAgent(std::vector<SteeringBehavior*> steeringBehaviors, Vector2D initialPosition, Vector2D* target) :
                _steeringBehaviors(steeringBehaviors),
                _modeSelected(0),
                Agent(initialPosition, target){}

UniqueBehaviorAgent::~UniqueBehaviorAgent(){}

void UniqueBehaviorAgent::update(float dtime, SDL_Event* event)
{
    //cout << "agent update:" << endl;

    switch (event->type) {
        /* Keyboard & Mouse events */
        case SDL_MOUSEBUTTONDOWN:
            if (event->button.button == SDL_BUTTON_RIGHT)
            {
                _modeSelected = (_modeSelected + 1) % 2;
            }            
        case SDL_KEYDOWN:
            if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
            {
                draw_sprite = !draw_sprite;	
            }				
        break;
    default:
        break;
    }

    Vector2D steering_force = _steeringBehaviors[_modeSelected]->CalculateForces(this, *_target, dtime);    

    Vector2D acceleration = steering_force / mass;
    _velocity = _velocity + acceleration * dtime;
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
