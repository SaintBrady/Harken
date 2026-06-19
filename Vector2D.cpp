#include <cmath>
#include "vector2d.h"
#include <iostream>

Vector2D::Vector2D()
{
    x = 0.0f;
    y = 0.0f;
}

Vector2D::Vector2D(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2D& Vector2D::Normalized()
{
    float magnitude = sqrt((x*x) + (y*y));

    Vector2D* vec = new Vector2D(x/magnitude, y/magnitude);
    return *vec;
}

Vector2D& Vector2D::Add(const Vector2D& v)
{
    this->x += v.x;
    this->y += v.y;

    return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D& v)
{
    this->x -= v.x;
    this->y -= v.y;

    return *this;
}

Vector2D& Vector2D::Multiply(const Vector2D& v)
{
    this->x *= v.x;
    this->y *= v.y;

    return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& v)
{
    this->x /= v.x;
    this->y /= v.y;

    return *this;
}

Vector2D& operator+(Vector2D& v1, const Vector2D& v2)
{
    return v1.Add(v2);
}

Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
{
    return v1.Subtract(v2);
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
{
    return v1.Multiply(v2);
}

Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
{
    return v1.Divide(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& v)
{
    return this->Add(v);
}

Vector2D& Vector2D::operator-=(const Vector2D& v)
{
    return this->Subtract(v);
}

Vector2D& Vector2D::operator*=(const Vector2D& v)
{
    return this->Multiply(v);
}

Vector2D& Vector2D::operator/=(const Vector2D& v)
{
    return this->Divide(v);
}

Vector2D& Vector2D::operator/=(float scalar){
	x /= scalar;
	y /= scalar;
	return *this;
}

void Vector2D::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& v)
{
    stream << "(" << v.x << ", " << v.y << ")";
    return stream;
}