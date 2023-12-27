#pragma once
#include "CShapeDecorator.h"
#include "regex"

class CShapeCreator
{
public:
	virtual std::shared_ptr<CShapeDecorator> CreateShape(const std::string& shapeInfo) const = 0;
	virtual ~CShapeCreator() {};

protected:
	const std::regex POINT_REGEX;
	const std::regex CIRCLE_CENTER_REGEX;
	const std::regex CIRCLE_RADIUS_REGEX;

	CShapeCreator()
		: POINT_REGEX("P\\d+=(\\d+),(\\d+)")
		, CIRCLE_CENTER_REGEX("C=(\\d+),(\\d+)")
		, CIRCLE_RADIUS_REGEX("R=(\\d+)")
	{}
};