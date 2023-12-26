#include "CShapeDecorator.h"

CShapeDecorator::CShapeDecorator(std::shared_ptr<sf::Shape> shape)
	: m_shape(shape)
{
}

std::size_t CShapeDecorator::getPointCount() const
{
	return 0;
}

sf::Vector2f CShapeDecorator::getPoint(std::size_t index) const
{
	sf::Vector2f v = { 0, 0 };
	return v;
}

std::shared_ptr<sf::Shape> CShapeDecorator::GetShapePtr() const
{
	return m_shape;
}