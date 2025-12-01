#include <iostream>
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "PhysicsWorld.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    CircleShape c1(30);
    CircleShape c2(50);
    c1.setOrigin(30, 30); 
    c2.setOrigin(50, 50);
	c1.setFillColor(sf::Color::Green);
	c2.setFillColor(sf::Color::Cyan);

	Renderer renderer;
	PhysicsWorld physicsWorld;
	
    renderer.AddDrawable(&c1);
    renderer.AddDrawable(&c2);

	Particle p1(Vector2d(200.f, 50.f), 1.f, 0.1f,c1.getRadius());
	Particle p2(Vector2d(700.f, 50.f), 1.f, 0.1f,c2.getRadius());
	//particle.addForce(Vector2d(1000.f, 1000.f));
   
    p1.velocity = Vector2d(200, 100);
    p2.velocity = Vector2d(-200, 100);

	physicsWorld.addParticle(&p1);
	physicsWorld.addParticle(&p2);

	Clock clock;
	float dt = 0.f;
	float t = 0.f;

    while (window.isOpen())
    {
        dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Apply force every frame
        //p1.addForce(Vector2d(100.f, 100.f));
        //p2.addForce(Vector2d(-100.f, 100.f));

        physicsWorld.Update(dt);
        c1.setPosition(p1.postion.x, p1.postion.y);
        c2.setPosition(p2.postion.x, p2.postion.y);
        renderer.Render(&window);
    }
    
    return 0;
}