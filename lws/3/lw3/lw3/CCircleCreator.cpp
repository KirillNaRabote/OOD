#include "CCircleCreator.h"

std::shared_ptr<CShapeDecorator> CCircleCreator::CreateShape(const std::string& circleInfo) const
{
	sf::CircleShape circle;
	circle.setFillColor(sf::Color::Blue);

	sf::Vector2f center;
	float radius = 0;

	std::smatch matches;

	if (std::regex_search(circleInfo.cbegin(), circleInfo.cend(), matches, CIRCLE_CENTER_REGEX))
	{
		center = { std::stof(matches[1]), std::stof(matches[2]) };
	}

	if (std::regex_search(circleInfo.cbegin(), circleInfo.cend(), matches, CIRCLE_RADIUS_REGEX))
	{
		radius = std::stof(matches[1]);
	}

	circle.setRadius(radius);
	circle.setPosition(center);

	CCircleDecorator circleD(std::make_shared<sf::CircleShape>(circle), center, radius);

	return std::make_shared<CCircleDecorator>(circleD);
}

CCircleCreator& CCircleCreator::GetInstance()
{
	static CCircleCreator instance;
	return instance;
}