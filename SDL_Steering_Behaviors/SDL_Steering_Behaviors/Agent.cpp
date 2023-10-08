#include "Agent.h"

#include "BehaviorPattern.h"

using namespace std;

Agent::Agent(Vector2D initialPosition, Vector2D* target) :
				 sprite_texture(0),
                 _position(initialPosition),
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
	             draw_sprite(false){}

Agent::Agent(Vector2D initialPosition):
				 sprite_texture(0),
				 _position(initialPosition),
				 _target(new Vector2D(0)),
				 _velocity(Vector2D(0,0)),
				 mass(0.5f),
				 max_force(50),
				 max_velocity(200),
				 orientation(0),
				 color({ 255,255,255,255 }),
				 sprite_num_frames(0),
				 sprite_w(0),
				 sprite_h(0),
				 draw_sprite(false){}

Agent::~Agent()
{
	SDL_DestroyTexture(sprite_texture);

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