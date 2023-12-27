#include "CController.h"

CController::CController(std::vector<std::shared_ptr<CShapeDecorator>>& shapes, std::istream& input, std::ostream& output)
	: m_shapes(shapes)
	, m_input(input)
	, m_output(output)
{
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
		return CTriangleCreator::GetInstance().CreateShape(shapeInfo);
	}
	else if (shapeType == "CIRCLE")
	{
		return CCircleCreator::GetInstance().CreateShape(shapeInfo);
	}
	else if (shapeType == "RECTANGLE")
	{
		return CRectangleCreator::GetInstance().CreateShape(shapeInfo);
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