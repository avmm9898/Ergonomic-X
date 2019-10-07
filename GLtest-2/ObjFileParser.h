/****************************************************************************
**
** Copyright (C) 2011 LP-Research
** All rights reserved.
** Contact: LP-Research (klaus@lp-research.com)
**
** This file is part of the Open Motion Analysis Toolkit (OpenMAT).
**
** OpenMAT is free software: you can redistribute it and/or modify it under 
** the terms of the GNU General Public License as published by the Free 
** Software Foundation, either version 3 of the License, or (at your option) 
** any later version.
** 
** OpenMAT is distributed in the hope that it will be useful, but WITHOUT 
** ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
** FITNESS FOR A PARTICULAR PURPOSE. See the GNU \ General Public License 
** for more details.
** 
** You should have received a copy of the GNU General Public License along 
** with the OpenMAT library. If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/
#pragma once
#ifndef OBJ_FILE_PARSER
#define OBJ_FILE_PARSER

#include <fstream>
#include <string>
#include <iostream>

#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>
#include <boost/shared_ptr.hpp>

#include <Eigen/Dense>

using namespace std;

class ObjFace {
public:
	std::vector<Eigen::Vector3f> vertexList;
	Eigen::Vector3f faceNormal;
};

class ObjFileParser {
public:
    bool parse(string filename, std::string type);
	std::vector<ObjFace> getFaceList(void);
    std::vector<ObjFace> getNewCenterVortex(void);
	Eigen::Vector3f getScaledSize(void);
	
	std::vector<ObjFace> faceList;

	ifstream fs;	
	Eigen::Vector3f centerVertex;
	Eigen::Vector3f minVertex;
	Eigen::Vector3f maxVertex;
	Eigen::Vector3f scaledSize;
};

#endif
