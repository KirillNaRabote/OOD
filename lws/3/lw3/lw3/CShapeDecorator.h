#pragma once
#include <SFML/Graphics.hpp>
//#include "CShapeVisitor.h"
class CShapeVisitor;

class CShapeDecorator : public sf::Shape
{
public:
	CShapeDecorator(std::shared_ptr<sf::Shape> shape);

	std::size_t getPointCount() const override;
	sf::Vector2f getPoint(std::size_t index) const override;

	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;

	virtual std::string GetTypeAsString() const = 0;

	virtual std::shared_ptr<sf::Shape> GetShapePtr() const = 0;

	virtual void Accept(const CShapeVisitor& visitor) const = 0;

private:
	std::shared_ptr<sf::Shape> m_shape;
};