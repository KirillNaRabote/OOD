#pragma once
#include "CShapeDecorator.h"
//#include "CShapeVisitor.h"

class CCircleDecorator : public CShapeDecorator
{
public:
	CCircleDecorator(std::shared_ptr<sf::Shape> shape, sf::Vector2f center, float radius);

	float GetArea() const override;
	float GetPerimeter() const override;

	std::string GetTypeAsString() const override;

	std::shared_ptr<sf::Shape> GetShapePtr() const override;

	void Accept(const CShapeVisitor& visitor) const override;

	~CCircleDecorator();

private:
	sf::Vector2f m_center;
	float m_radius;
};