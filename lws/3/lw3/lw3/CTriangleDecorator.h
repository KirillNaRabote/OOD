#pragma once
#include "CShapeDecorator.h"
//#include "CShapeVisitor.h"

class CTriangleDecorator : public CShapeDecorator
{
public:
	CTriangleDecorator(std::shared_ptr<sf::Shape> shape, sf::Vector2f vertex1, sf::Vector2f vertex2, sf::Vector2f vertex3);

	float GetArea() const override;
	float GetPerimeter() const override;

	std::string GetTypeAsString() const override;
	std::shared_ptr<sf::Shape> GetShapePtr() const override;

	void Accept(const CShapeVisitor& visitor) const override;

	~CTriangleDecorator();

private:
	float GetDistance(sf::Vector2f vertex1, sf::Vector2f vertex2) const;
	float GetHalfMeter() const;

	sf::Vector2f m_vertex1;
	sf::Vector2f m_vertex2;
	sf::Vector2f m_vertex3;
};