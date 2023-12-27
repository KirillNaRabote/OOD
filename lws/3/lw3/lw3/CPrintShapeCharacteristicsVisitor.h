#pragma once
#include "CShapeVisitor.h"

class CPrintShapeCharacteristicsVisitor : public CShapeVisitor
{
public:
	CPrintShapeCharacteristicsVisitor(std::ostream& output);

	void visitRectangle(const CRectangleDecorator& rectangle) const override;
	void visitCircle(const CCircleDecorator& circle) const override;
	void visitTriangle(const CTriangleDecorator& triangle) const override;

private:
	std::ostream& m_output;
};