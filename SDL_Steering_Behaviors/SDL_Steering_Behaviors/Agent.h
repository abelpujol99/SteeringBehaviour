#pragma once
#include <iostream>
#include <minmax.h>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "SDL_SimpleApp.h"
#include "Vector2D.h"
#include "utils.h"
#include "SteeringBehavior.h"


class Agent
{

protected:
	Vector2D _position;
	Vector2D _velocity;
	Vector2D* _target;

	float mass;
	float orientation;
	float max_force;
	float max_velocity;

	SDL_Color color;

	SDL_Texture *sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;


public:
	Agent(Vector2D initialPosition, Vector2D* target);
	~Agent();
	Vector2D getPosition();
	Vector2D* getTarget();
	Vector2D getVelocity();
	float getMaxVelocity();
	void setPosition(Vector2D position);
	void setTarget(Vector2D target);
	void setVelocity(Vector2D velocity);
	void setMass(float mass);
	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	virtual void update(float dtime, SDL_Event *event) = 0;
	void draw();
	bool loadSpriteTexture(char* filename, int num_frames=1);
};
