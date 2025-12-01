#include "PhysicsWorld.h"

const Vector2d PhysicsWorld::gravity(0.f, 9.8f);

void PhysicsWorld::addParticle(Particle* particle)
{
	particles.push_back(particle);
}

void PhysicsWorld::Update(float deltaTime)
{
	for (Particle* particle : particles)
	{
		particle->addForce(particle->mass * gravity);
		particle->Update(deltaTime);
	}
}