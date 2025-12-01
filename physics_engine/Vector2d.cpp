#include "Vector2d.h">

Vector2d::Vector2d()
{
	this->x = 0.0f;
	this->y = 0.0f;
}

Vector2d::Vector2d(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2d Vector2d::operator+(Vector2d other)
{
	return Vector2d(this->x + other.x, this->y + other.y);
}

Vector2d Vector2d::operator-(Vector2d other)
{
	return Vector2d(this->x - other.x, this->y - other.y);
}

Vector2d Vector2d::operator+=(Vector2d other)
{
	return Vector2d(this->x += other.x, this->y += other.y);
}

Vector2d Vector2d::operator-=(Vector2d other)
{
	return Vector2d(this->x -= other.x, this->y -= other.y);
}

Vector2d Vector2d::operator=(Vector2d other)
{
	return Vector2d(this->x = other.x, this->y = other.y);
}

bool Vector2d::operator==(Vector2d other)
{
	if (this->x == other.x && this->y == other.y)
	{
		return true;
	}
	return false;
}

Vector2d Vector2d::operator*(float a)
{
	return Vector2d(this->x * a, this->y * a);
}

Vector2d Vector2d::operator*=(float a)
{
	return Vector2d(this->x *= a, this->y *= a);
}

float Vector2d::Dot(Vector2d other)
{
	return this->x * other.x + this->y * other.y;
}

float Vector2d::getMagnitude()
{
	return sqrt((this->x) * (this->x) + (this->y) * (this->y));
}

Vector2d Vector2d::getNormalized()
{
	float mag = getMagnitude();
	if (mag == 0.f)
	{
		return Vector2d(0.f, 0.f);
	}
	return Vector2d(this->x / mag, this->y / mag);
}

void Vector2d::normalize()
{
	float mag = getMagnitude();
	if (mag == 0.f)
	{
		this->x = 0.f;
		this->y = 0.f;
	}
	else
	{
		this->x /= mag;
		this->y /= mag;
	}
}

Vector2d::operator Vector2f()
{
	return Vector2f(static_cast<float>(this->x), static_cast<float>(this->y));
}

Vector2d Vector2d::getNormal()
{
	return Vector2d(-this->y, this->x);
}

void Vector2d::print()
{
	cout << "Vector2d(" << this->x << ", " << this->y << ")" << endl;
}



Vector2d operator*(float a, Vector2d vector)
{
	return vector * a;
}

Vector2d operator*=(float a, Vector2d vector)
{
	return vector *= a;
}
