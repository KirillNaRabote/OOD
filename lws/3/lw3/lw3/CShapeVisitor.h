#pragma once
#include "CRectangleDecorator.h"
#include "CCircleDecorator.h"
#include "CTriangleDecorator.h"

class CShapeVisitor
{
public:
	virtual void visitRectangle(const CRectangleDecorator& rectangle) const = 0;
	virtual void visitCircle(const CCircleDecorator& rectangle) const = 0;
	virtual void visitTriangle(const CTriangleDecorator& rectangle) const = 0;

	virtual ~CShapeVisitor() {};
};