#include "Agent.h"

#include "BehaviorPattern.h"

using namespace std;

Agent::Agent(BehaviorPattern* behaviorPattern, Vector2D* target) :
				 sprite_texture(0),
                 _position(Vector2D(100, 100)),
				 _target(target),
	             _velocity(Vector2D(0,0)),
	             mass(0.5f),
	             max_force(50),
	             max_velocity(200),
	             orientation(0),
	             color({ 255,255,255,255 }),
				 sprite_num_frames(0),
	             sprite_w(0),
	             sprite_h(0),
	             draw_sprite(false),
				 _behaviorPattern(behaviorPattern),
				 _modeSelected(0)
{	
	/*for (SteeringBehavior* steeringBehavior : _steeringBehaviorsVector)
	{
		steeringBehavior->Accept(this);	
	}*/
}

Agent::~Agent()
{
	SDL_DestroyTexture(sprite_texture);

	delete _behaviorPattern;

	delete _target;
}

Vector2D Agent::getPosition()
{
	return _position;
}

Vector2D* Agent::getTarget()
{
	return _target;
}

Vector2D Agent::getVelocity()
{
	return _velocity;
}

float Agent::getMaxVelocity()
{
	return max_velocity;
}

void Agent::setPosition(Vector2D position)
{
	_position = position;
}

void Agent::setTarget(Vector2D target)
{
	*_target = target;
}

void Agent::setVelocity(Vector2D velocity)
{
	_velocity = velocity;
}

void Agent::setMass(float _mass)
{
	mass = _mass;
}

void Agent::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	color = { r, g, b, a };
}

void Agent::update(float dtime, SDL_Event *event)
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

	//Vector2D steering_force = this->Behavior()[_modeSelected]->CalculateForces(this, *_target, dtime);
	Vector2D steering_force = _behaviorPattern->CalculateForce(this, *_target, dtime);

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

void Agent::draw()
{
	if (draw_sprite)
	{
		Uint32 sprite;
		
		if (_velocity.Length() < 5.0)
			sprite = 1;
		else
			sprite = (int)(SDL_GetTicks() / (-0.1*_velocity.Length() + 250)) % sprite_num_frames;
		
		SDL_Rect srcrect = { (int)sprite * sprite_w, 0, sprite_w, sprite_h };
		SDL_Rect dstrect = { (int)_position.x - (sprite_w / 2), (int)_position.y - (sprite_h / 2), sprite_w, sprite_h };
		SDL_Point center = { sprite_w / 2, sprite_h / 2 };
		SDL_RenderCopyEx(TheApp::Instance()->getRenderer(), sprite_texture, &srcrect, &dstrect, orientation+90, &center, SDL_FLIP_NONE);
	}
	else 
	{
		draw_circle(TheApp::Instance()->getRenderer(), (int)_position.x, (int)_position.y, 15, color.r, color.g, color.b, color.a);
		SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), (int)_position.x, (int)_position.y, (int)(_position.x+15*cos(orientation*DEG2RAD)), (int)(_position.y+15*sin(orientation*DEG2RAD)));
	}
}

bool Agent::loadSpriteTexture(char* filename, int _num_frames)
{
	if (_num_frames < 1) return false;

	SDL_Surface *image = IMG_Load(filename);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	sprite_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	sprite_num_frames = _num_frames;
	sprite_w = image->w / sprite_num_frames;
	sprite_h = image->h;
	draw_sprite = true;

	if (image)
		SDL_FreeSurface(image);

	return true;
}



void Agent::VisitSteeringBehavior(AlignmentBehavior* alignmentBehavior)
{
	_steeringBehaviorsName.push_back("Alignment");
}

void Agent::VisitSteeringBehavior(CohesionBehavior* cohesionBehavior)
{
	_steeringBehaviorsName.push_back("Cohesion");
}

void Agent::VisitSteeringBehavior(FleeBehavior* fleeBehavior)
{
	_steeringBehaviorsName.push_back("Flee");
}

void Agent::VisitSteeringBehavior(SeekBehavior* seekBehavior)
{
	_steeringBehaviorsName.push_back("Seek");
}

void Agent::VisitSteeringBehavior(SeparationBehavior* separationBehavior)
{
	_steeringBehaviorsName.push_back("Separation");
}

void Agent::VisitBehaviorPattern(WeightedBlending* weightedBlending)
{
	
}

void Agent::VisitBehaviorPattern(PriorityList* priorityList)
{
	
}
