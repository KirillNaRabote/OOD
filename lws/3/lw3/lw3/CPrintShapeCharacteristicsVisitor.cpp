#include "CPrintShapeCharacteristicsVisitor.h"

CPrintShapeCharacteristicsVisitor::CPrintShapeCharacteristicsVisitor(std::ostream& output)
	: m_output(output)
{
}

void CPrintShapeCharacteristicsVisitor::visitRectangle(const CRectangleDecorator& rectangle) const
{
	m_output << rectangle.GetTypeAsString() << ": P=" << rectangle.GetPerimeter()
		<< " ; S=" << rectangle.GetArea() << ";" << std::endl << std::endl;
}

void CPrintShapeCharacteristicsVisitor::visitCircle(const CCircleDecorator& circle) const
{
	m_output << circle.GetTypeAsString() << ": P=" << circle.GetPerimeter()
		<< " ; S=" << circle.GetArea() << ";" << std::endl << std::endl;
}

void CPrintShapeCharacteristicsVisitor::visitTriangle(const CTriangleDecorator& triangle) const
{
	m_output << triangle.GetTypeAsString() << ": P=" << triangle.GetPerimeter()
		<< " ; S=" << triangle.GetArea() << ";" << std::endl << std::endl;
}