#pragma once
#include "CShapeCreator.h"
#include "CTriangleDecorator.h"

#include <regex>

class CTriangleCreator : public CShapeCreator
{
public:
	std::shared_ptr<CShapeDecorator> CreateShape(const std::string& triangleInfo) const override;

	static CTriangleCreator& GetInstance();

private:
	CTriangleCreator() {};
	~CTriangleCreator() {};

	void operator=(const CTriangleCreator&);
};