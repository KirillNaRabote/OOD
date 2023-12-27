#pragma once
#include "CShapeCreator.h"
#include "CCircleDecorator.h"
#include <regex>

class CCircleCreator : public CShapeCreator
{
public:
	std::shared_ptr<CShapeDecorator> CreateShape(const std::string& circleInfo) const override;

	static CCircleCreator& GetInstance();

private:
	CCircleCreator() {};
	~CCircleCreator() {};

	void operator=(const CCircleCreator&);
};