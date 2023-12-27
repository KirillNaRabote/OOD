#include "CRectangleDecorator.h"

CRectangleDecorator::CRectangleDecorator(std::shared_ptr<sf::Shape> shape, sf::Vector2f topLeft, sf::Vector2f bottomRight)
	: CShapeDecorator(shape)
	, m_topLeft(topLeft)
	, m_bottomRight(bottomRight)
{
}

float CRectangleDecorator::GetWidth() const
{
	return abs(m_bottomRight.x - m_topLeft.x);
}

float CRectangleDecorator::GetHeight() const
{
	return abs(m_bottomRight.y - m_topLeft.y);
}

float CRectangleDecorator::GetArea() const
{
	return GetWidth() * GetHeight();
}

float CRectangleDecorator::GetPerimeter() const
{
	return 2 * GetWidth() + 2 * GetHeight();
}

std::shared_ptr<sf::Shape> CRectangleDecorator::GetShapePtr() const
{
	return CShapeDecorator::GetShapePtr();
}

std::string CRectangleDecorator::GetTypeAsString() const
{
	return "RECTANGLE";
}

CRectangleDecorator::~CRectangleDecorator()
{
}