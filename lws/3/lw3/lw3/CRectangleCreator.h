#pragma once
#include "CShapeCreator.h"
#include "CRectangleDecorator.h"
#include "regex"

class CRectangleCreator : public CShapeCreator
{
public:
	std::shared_ptr<CShapeDecorator> CreateShape(const std::string& rectangleInfo) const override;

	static CRectangleCreator& GetInstance();

private:
	CRectangleCreator() {};
	~CRectangleCreator() {};

	void operator=(const CRectangleCreator&);
};