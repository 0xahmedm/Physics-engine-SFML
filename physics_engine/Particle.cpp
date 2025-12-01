#include "Particle.h"

Particle::Particle(Vector2d postion, float mass, float drag)
{
	this->postion= postion;
	this->mass = mass;
	this->drag = drag;

	this->velocity = Vector2d(0, 0);
	this->acceleration = Vector2d(0, 0);
	this->forces = Vector2d(0, 0);
}

void Particle::Update(float dt)
{
	cout << "Force: " << forces.x << ", " << forces.y << endl;
	cout << "Velocity: " << velocity.x << ", " << velocity.y << endl;
	cout << "Position: " << postion.x << ", " << postion.y << endl;

	if (velocity.getMagnitude() > 0) {
		Vector2d vNorm = velocity.getNormalized();
		float speed = velocity.getMagnitude();
		Vector2d dragForce = -0.5f * drag * speed * speed * vNorm;
		forces += dragForce;
	}


	acceleration = forces * (1.f / mass);
	velocity += dt * acceleration;
	postion += dt * velocity;

	forces = Vector2d(0.f, 0.f);
}

void Particle::addForce(Vector2d force)
{
	this->forces += force;
}