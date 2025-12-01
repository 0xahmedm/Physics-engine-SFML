#include <iostream>
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "PhysicsWorld.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    CircleShape c1(40);
    CircleShape c2(30);
    c1.setOrigin(40, 40); 
    c2.setOrigin(30, 30);
	c1.setFillColor(sf::Color::Green);
	c2.setFillColor(sf::Color::Cyan);

	Renderer renderer;
	PhysicsWorld physicsWorld;
	
    renderer.AddDrawable(&c1);
    renderer.AddDrawable(&c2);

	Particle p1(Vector2d(100.f, 100.f), 2.f, 0.1f);
	Particle p2(Vector2d(400.f, 100.f), 1.f, 0.1f);
	//particle.addForce(Vector2d(1000.f, 1000.f));

	physicsWorld.addParticle(&p1);
	physicsWorld.addParticle(&p2);

	Clock clock;
	float dt = 0.f;
	float t = 0.f;

    while (window.isOpen())
    {
        if (clock.getElapsedTime().asSeconds() >= 0.008f) {
            dt = clock.restart().asSeconds();
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Apply force every frame
        p1.addForce(Vector2d(100.f, 100.f));
        p2.addForce(Vector2d(-100.f, 100.f));

        physicsWorld.Update(dt);
        c1.setPosition(p1.postion.x, p1.postion.y);
        c2.setPosition(p2.postion.x, p2.postion.y);
        renderer.Render(&window);
    }
    
    return 0;
}