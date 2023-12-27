#include "CCircleDecorator.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include "CShapeVisitor.h"

CCircleDecorator::CCircleDecorator(std::shared_ptr<sf::Shape> shape, sf::Vector2f center, float radius)
	: CShapeDecorator(shape)
	, m_center(center)
	, m_radius(radius)
{
}

void CCircleDecorator::Accept(const CShapeVisitor& visitor) const
{
	visitor.visitCircle(*this);
}


float CCircleDecorator::GetArea() const
{
	return M_PI * m_radius * m_radius;
}

float CCircleDecorator::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

std::shared_ptr<sf::Shape> CCircleDecorator::GetShapePtr() const
{
	return CShapeDecorator::GetShapePtr();
}

std::string CCircleDecorator::GetTypeAsString() const
{
	return "CIRCLE";
}

CCircleDecorator::~CCircleDecorator()
{
}