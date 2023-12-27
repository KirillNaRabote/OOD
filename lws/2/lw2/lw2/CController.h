#pragma once
#include<vector>
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include <SFML/Graphics.hpp>

#include "CShapeDecorator.h"
#include "CRectangleDecorator.h"
#include "CRectangleCreator.h"
#include "CCircleDecorator.h"
#include "CCircleCreator.h"
#include "CTriangleDecorator.h"
#include "CTriangleCreator.h"

class CController
{
public:
	CController(std::vector<std::shared_ptr<CShapeDecorator>>& shapes, std::istream& input, std::ostream& output);

	void ProcessInputFile();
	void PrintParameters() const;
	void DrawShapes() const;

private:
	std::shared_ptr<CShapeDecorator> ParseShapeInfo(const std::string& shapeInfo) const;

	std::vector<std::shared_ptr<CShapeDecorator>>& m_shapes;

	std::istream& m_input;
	std::ostream& m_output;
};