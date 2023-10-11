#include "Obstacle.h"

Obstacle::Obstacle(std::vector<Vector2D> &vertices, Vector2D initialPosition, Vector2D* target) : Agent(initialPosition, target)
{
	for (int i = 0; i < vertices.size(); i++) {
		_vertices.push_back(vertices[i]);
	}
	draw_sprite = false;
}

bool Obstacle::IntersectSegment(Vector2D pos, Vector2D raycastVector, Vector2D& intersectionPoint, Vector2D& normalVector)
{
	bool collide = false;
	float minDist = raycastVector.Length() * 2;
	bool inside = true;
	for (int i = 0; i < _vertices.size(); i++) {
		Vector2D p1 = _vertices[i] + _position;
		Vector2D p2 = _vertices[(i + 1) % _vertices.size()] + _position;
		Vector2D segment = p2 - p1;
		Vector2D s = segment;
		Vector2D r = raycastVector;
		if (s.Normalize() == r.Normalize()) continue;

		//T2 = (r_dx*(s_py-r_py) + r_dy*(r_px-s_px))/(s_dx*r_dy - s_dy*r_dx)
		float t2 = (raycastVector.x * (p1.y - pos.y) + raycastVector.y * (pos.x - p1.x)) / (segment.x * raycastVector.y - segment.y * raycastVector.x);

		//T1 = (s_px+s_dx*T2-r_px)/r_dx
		float t1 = ((p1.x + segment.x * t2 - pos.x) / raycastVector.x);
		if (raycastVector.x == 0.f) {
			t1 = ((p1.y + segment.y * t2 - pos.y) / raycastVector.y);
		}
		//std::cout << t1 << std::endl;
		if (t1 >= 0.f && t1 <= raycastVector.Length() && t2 >= 0.f && t2 <= 1.f) {
			collide = true;
			if (t1 < minDist) {
				minDist = t1;
				intersectionPoint = p1 + segment * t2;
				normalVector = Vector2D(-segment.x, -segment.y).Normalize();
			}
			//std::cout << "Segment " << j << " Pos: " << pos.x << ", " << pos.y << " Point: " << intersectionPoint.x << ", " << intersectionPoint.y << " Normal: " << normalVector.x << "," << normalVector.y << " | T2 = " << t2 << ", T1 = " << t1 << std::endl;
			int xd = 0;
			
		}
		else {
			inside = false;
		}
	}
	if (inside) {
		std::cout << "inside" << std::endl;
	}
	return collide;
}

void Obstacle::update(float dtime, SDL_Event* event) {

}

void Obstacle::draw() {
	if (draw_sprite)
	{
		Uint32 sprite;

		if (_velocity.Length() < 5.0)
			sprite = 1;
		else
			sprite = (int)(SDL_GetTicks() / (-0.1 * _velocity.Length() + 250)) % sprite_num_frames;

		SDL_Rect srcrect = { (int)sprite * sprite_w, 0, sprite_w, sprite_h };
		SDL_Rect dstrect = { (int)_position.x - (sprite_w / 2), (int)_position.y - (sprite_h / 2), sprite_w, sprite_h };
		SDL_Point center = { sprite_w / 2, sprite_h / 2 };
		SDL_RenderCopyEx(TheApp::Instance()->getRenderer(), sprite_texture, &srcrect, &dstrect, orientation + 90, &center, SDL_FLIP_NONE);
	}
	else
	{
		//draw_circle(TheApp::Instance()->getRenderer(), (int)_position.x, (int)_position.y, 15, color.r, color.g, color.b, color.a);
		//SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), (int)_position.x, (int)_position.y, (int)(_position.x + 15 * cos(orientation * DEG2RAD)), (int)(_position.y + 15 * sin(orientation * DEG2RAD)));
		int l = _vertices.size();
		SDL_Point* points = new SDL_Point[l + 1];
		for (int i = 0; i < l; i++) {
			points[i] = SDL_Point {(int)(_vertices[i].x + _position.x), (int)(_vertices[i].y + _position.y)};
		}
		points[l] = SDL_Point{ (int)(_vertices[0].x + _position.x), (int)(_vertices[0].y + _position.y) };
		SDL_RenderDrawLines(TheApp::Instance()->getRenderer(), points, l + 1);
		delete[] points;
	}
}