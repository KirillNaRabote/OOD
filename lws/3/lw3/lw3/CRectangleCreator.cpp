#include "CRectangleCreator.h"

CRectangleCreator& CRectangleCreator::GetInstance() {
	static CRectangleCreator instance;
	return instance;
}

std::shared_ptr<CShapeDecorator> CRectangleCreator::CreateShape(const std::string& rectangleInfo) const
{
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Yellow);

	std::vector<sf::Vector2f> rectangleVertices;

	std::string::const_iterator searchStart(rectangleInfo.cbegin());
	std::smatch matches;

	while (std::regex_search(searchStart, rectangleInfo.cend(), matches, POINT_REGEX)) {
		rectangleVertices.push_back({ std::stof(matches[1]), std::stof(matches[2]) });
		searchStart = matches.suffix().first;
	}

	sf::Vector2f topLeft;
	sf::Vector2f bottomRight;

	if (rectangleVertices[0].x < rectangleVertices[1].x)
	{
		topLeft.x = rectangleVertices[0].x;
		bottomRight.x = rectangleVertices[1].x;
	}
	else
	{
		topLeft.x = rectangleVertices[1].x;
		bottomRight.x = rectangleVertices[0].x;
	}

	if (rectangleVertices[0].y < rectangleVertices[1].y)
	{
		topLeft.y = rectangleVertices[0].y;
		bottomRight.y = rectangleVertices[1].y;
	}
	else
	{
		topLeft.y = rectangleVertices[1].y;
		bottomRight.y = rectangleVertices[0].y;
	}

	rectangle.setPosition(topLeft);
	rectangle.setSize({ bottomRight.x - topLeft.x, bottomRight.y - topLeft.y });

	CRectangleDecorator rectangleD(std::make_shared<sf::RectangleShape>(rectangle), topLeft, bottomRight);

	return std::make_shared<CRectangleDecorator>(rectangleD);
}