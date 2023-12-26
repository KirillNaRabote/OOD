#include "CController.h"

const std::regex POINT_REGEX("P\\d+=(\\d+),(\\d+)");
const std::regex CIRCLE_CENTER_REGEX("C=(\\d+),(\\d+)");
const std::regex CIRCLE_RADIUS_REGEX("R=(\\d+)");

CController::CController(std::vector<std::shared_ptr<CShapeDecorator>>& shapes, std::istream& input, std::ostream& output)
	: m_shapes(shapes)
	, m_input(input)
	, m_output(output)
{
}

CCircleDecorator CController::CreateCircle(const std::string& circleInfo) const
{
	sf::CircleShape circle;
	circle.setFillColor(sf::Color::Blue);

	sf::Vector2f center;
	float radius = 0;

	std::smatch matches;

	if (std::regex_search(circleInfo.cbegin(), circleInfo.cend(), matches, CIRCLE_CENTER_REGEX))
	{
		center = {std::stof(matches[1]), std::stof(matches[2])};
	}

	if (std::regex_search(circleInfo.cbegin(), circleInfo.cend(), matches, CIRCLE_RADIUS_REGEX))
	{
		radius = std::stof(matches[1]);
	}

	circle.setRadius(radius);
	circle.setPosition(center);

	CCircleDecorator circleD(std::make_shared<sf::CircleShape>(circle), center, radius);

	return circleD;
}

CRectangleDecorator CController::CreateRectangle(const std::string& rectangleInfo) const
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

	return rectangleD;
}

CTriangleDecorator CController::CreateTriangle(const std::string& triangleInfo) const
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

	CTriangleDecorator triangleD(std::make_shared<sf::ConvexShape>(triangle), {100, 100}, {150, 100}, {100, 150});

	return triangleD;
}

std::shared_ptr<CShapeDecorator> CController::ParseShapeInfo(const std::string& shapeInfo) const
{
	std::istringstream strm(shapeInfo);

	std::string shapeType;
	strm >> shapeType;

	shapeType.erase(std::remove_if(shapeType.begin(), shapeType.end(), [](unsigned char c) {
		return !std::isalpha(c);
		}), shapeType.end());

	if (shapeType == "TRIANGLE")
	{
		return std::make_shared<CTriangleDecorator>(CreateTriangle(shapeInfo));
	}
	else if (shapeType == "CIRCLE")
	{
		return std::make_shared<CCircleDecorator>(CreateCircle(shapeInfo));
	}
	else if (shapeType == "RECTANGLE")
	{
		return std::make_shared<CRectangleDecorator>(CreateRectangle(shapeInfo));
	}
	throw std::invalid_argument("Unknown figure\n");
}

void CController::ProcessInputFile()
{
	std::string shapeInfo;

	try
	{
		while (getline(m_input, shapeInfo))
		{
			m_shapes.push_back(ParseShapeInfo(shapeInfo));
		}
	}
	catch (std::exception& ex)
	{
		m_output << ex.what();
	}
}

void CController::PrintParameters() const
{
	for (auto shapePtr : m_shapes)
	{
		m_output << shapePtr.get()->GetTypeAsString() << ": P=" << shapePtr.get()->GetPerimeter()
			<< " ; S=" << shapePtr.get()->GetArea() << ";" << std::endl << std::endl;
	}
}

void CController::DrawShapes() const
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Shapes window");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for (auto shape : m_shapes)
		{
			window.draw(*shape->GetShapePtr());
		}
		window.display();
	}
}