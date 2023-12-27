#include "CTriangleCreator.h"

std::shared_ptr<CShapeDecorator> CTriangleCreator::CreateShape(const std::string& triangleInfo) const
{
	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	triangle.setFillColor(sf::Color::Magenta);

	std::string::const_iterator searchStart(triangleInfo.cbegin());
	std::smatch matches;

	size_t vertexCounter = 0;

	while (std::regex_search(searchStart, triangleInfo.cend(), matches, POINT_REGEX)) {
		triangle.setPoint(vertexCounter, sf::Vector2f(std::stof(matches[1]), std::stof(matches[2])));
		searchStart = matches.suffix().first;
		vertexCounter++;
	}

	CTriangleDecorator triangleD(std::make_shared<sf::ConvexShape>(triangle), { 100, 100 }, { 150, 100 }, { 100, 150 });

	return std::make_shared<CTriangleDecorator>(triangleD);
}

CTriangleCreator& CTriangleCreator::GetInstance()
{
	static CTriangleCreator instance;
	return instance;
}