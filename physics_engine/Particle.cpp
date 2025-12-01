#include "Particle.h"

Particle::Particle(Vector2d postion, float mass, float drag, float r)
{
	this->postion= postion;
	this->mass = mass;
	this->drag = drag;
	this->collider = Collider();
	this->collider.r = r;

	this->velocity = Vector2d(0, 0);
	this->acceleration = Vector2d(0, 0);
	this->forces = Vector2d(0, 0);
}

void Particle::Update(float dt)
{
	collider.center = postion;

	/*cout << "Force: " << forces.x << ", " << forces.y << endl;
	cout << "Velocity: " << velocity.x << ", " << velocity.y << endl;
	cout << "Position: " << postion.x << ", " << postion.y << endl;*/

	acceleration = forces * (1.0f / mass);

	float damping = 1.0f - drag * dt;
	if (damping < 0.0f) damping = 0.0f;

	velocity *= damping;

	velocity += acceleration * dt;

	postion += velocity * dt;

	forces = Vector2d(0.f, 0.f);
}

void Particle::addForce(Vector2d force)
{
	this->forces += force;
}