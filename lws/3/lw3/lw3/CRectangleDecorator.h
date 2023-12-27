#pragma once
#include <SFML/Graphics.hpp>
#include "CShapeDecorator.h"
//#include "CShapeVisitor.h"

class CRectangleDecorator : public CShapeDecorator
{
public:
	CRectangleDecorator(std::shared_ptr<sf::Shape> shape, sf::Vector2f topLeft, sf::Vector2f bottomRight);

	float GetArea() const override;
	float GetPerimeter() const override;
	 
	std::string GetTypeAsString() const override;
	std::shared_ptr<sf::Shape> GetShapePtr() const override;

	void Accept(const CShapeVisitor& visitor) const override;

	~CRectangleDecorator();

private:
	float GetWidth() const;
	float GetHeight() const;

	sf::Vector2f m_topLeft;
	sf::Vector2f m_bottomRight;
};