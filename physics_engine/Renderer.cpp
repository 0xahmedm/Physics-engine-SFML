#include "Renderer.h"

void Renderer::AddDrawable(Drawable* drawable)
{
	this->drawables.push_back(drawable);
}

void Renderer::Render(RenderWindow* window)
{
	window->clear();
	for (auto& drawable : drawables)
	{
		window->draw(*drawable);
	}
	window->display();
}
