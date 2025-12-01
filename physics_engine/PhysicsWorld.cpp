#include "PhysicsWorld.h"

const Vector2d PhysicsWorld::gravity(0.f, 9.8f);

void elasticCollision(Particle* p1, Particle* p2)
{
    Vector2d x1 = p1->postion;
    Vector2d x2 = p2->postion;

    Vector2d v1 = p1->velocity;
    Vector2d v2 = p2->velocity;

    float m1 = p1->mass;
    float m2 = p2->mass;

    Vector2d normal = (x1 - x2).getNormalized();

    float relVel = (v1 - v2).Dot(normal);

    if (relVel > 0)
        return;

    float impulse = (2.0f * relVel) / (m1 + m2);

    p1->velocity = v1 - normal * (impulse * m2);
    p2->velocity = v2 + normal * (impulse * m1);
}

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

	checkCollision();
}


void PhysicsWorld::checkCollision()
{
    for (auto it1 = particles.begin(); it1 != particles.end(); ++it1)
    {
        for (auto it2 = std::next(it1); it2 != particles.end(); ++it2)
        {
            Particle* p1 = *it1;
            Particle* p2 = *it2;

            if (p1->collider.checkCollision(p2->collider))
            {
                elasticCollision(p1, p2);
            }
        }
    }
}

//void PhysicsWorld::checktwoCircleCollision()
//{
//}
//
//void PhysicsWorld::checkAABBCollision()
//{
//}
//
//void PhysicsWorld::checkSatCollision()
//{
//}
