#include "CTriangleDecorator.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

CTriangleDecorator::CTriangleDecorator(std::shared_ptr<sf::Shape> shape, sf::Vector2f vertex1, sf::Vector2f vertex2, sf::Vector2f vertex3)
	: CShapeDecorator(shape)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

float CTriangleDecorator::GetDistance(sf::Vector2f vertex1, sf::Vector2f vertex2) const
{
	return std::sqrt(std::pow(vertex1.x - vertex2.x, 2) + std::pow(vertex1.y - vertex2.y, 2));
}

float CTriangleDecorator::GetHalfMeter() const
{
	return GetPerimeter() / 2;
}

float CTriangleDecorator::GetArea() const
{
	return std::sqrt(GetHalfMeter() 
		* (GetHalfMeter() - GetDistance(m_vertex1, m_vertex2)) 
		* (GetHalfMeter() - GetDistance(m_vertex2, m_vertex3)) 
		* (GetHalfMeter() - GetDistance(m_vertex3, m_vertex1)));
}

float CTriangleDecorator::GetPerimeter() const
{
	return GetDistance(m_vertex1, m_vertex2) + GetDistance(m_vertex2, m_vertex3) + GetDistance(m_vertex3, m_vertex1);
}

std::shared_ptr<sf::Shape> CTriangleDecorator::GetShapePtr() const
{
	return CShapeDecorator::GetShapePtr();
}

std::string CTriangleDecorator::GetTypeAsString() const
{
	return "TRIANGLE";
}

CTriangleDecorator::~CTriangleDecorator()
{
}