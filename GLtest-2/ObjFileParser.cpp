/***********************************************************************
** (c) LP-RESEARCH Inc.
** All rights reserved.
** Contact: info@lp-research.com
**
** This file is part of the Open Motion Analysis Toolkit (OpenMAT).
**
** Redistribution and use in source and binary forms, with 
** or without modification, are permitted provided that the 
** following conditions are met:
**
** Redistributions of source code must retain the above copyright 
** notice, this list of conditions and the following disclaimer.
** Redistributions in binary form must reproduce the above copyright 
** notice, this list of conditions and the following disclaimer in 
** the documentation and/or other materials provided with the 
** distribution.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
** FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
** HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***********************************************************************/

#include "ObjFileParser.h"

#define OBJ_FILE_COMMENT 0
#define OBJ_FILE_VERTEX_NORMAL 1
#define OBJ_FILE_VERTEX 2
#define OBJ_FILE_NEWLINE 3
#define OBJ_FILE_FACE 4
#define OBJ_FILE_UNKNOWN 5
#define OBJ_FILE_VERTEX_PART 6
#define OBJ_FILE_NORMAL_PART 7

bool ObjFileParser::parse(std::string filename, std::string type)
{
	bool f;
	float maxSize;
	
	std::vector<Eigen::Vector3f> vertexNormalList;
	std::vector<Eigen::Vector3f> vertexList;
	
	faceList.clear();
	
	fs.open(filename.c_str());
	
	if (fs.is_open() == true) {
		f = true;
		cout << "[ObjFileParser] File " << filename.c_str() <<" opened." << endl;	
	} else {
		cout << "[ObjFileParser] Could not open " << filename.c_str() << endl;	
		return false;
	}
	
	while (fs.is_open() == true && fs.eof() == false) {
		char s[512];	
		int tokenCount;
		Eigen::Vector3f vertex;
		Eigen::Vector3f vertexNormal;
		ObjFace face;
		
		fs.getline(s, 512);
		string l(s);
				
		boost::char_separator<char> sep(" ");
		boost::tokenizer< boost::char_separator<char> > tokens(l, sep);

		int state = OBJ_FILE_NEWLINE;
		BOOST_FOREACH(string t, tokens) {
			switch (state) {
			case OBJ_FILE_NEWLINE:
				if (t == "#") {
					state = OBJ_FILE_COMMENT;
				} else if (t == "vn") {
					state = OBJ_FILE_VERTEX_NORMAL;
					tokenCount = 3;
				} else if (t == "v") {
					state = OBJ_FILE_VERTEX;
					tokenCount = 3;
				} else if (t == "f") {
					state = OBJ_FILE_FACE;
					tokenCount = 3;
				} else {
					state = OBJ_FILE_UNKNOWN;
				}
				break;
			
			case OBJ_FILE_COMMENT:
			case OBJ_FILE_UNKNOWN:
				break;

			case OBJ_FILE_VERTEX_NORMAL:
				if (tokenCount == 0) break;
				
				--tokenCount;
				vertexNormal(tokenCount) = boost::lexical_cast<float>(t);
				break;
				
			case OBJ_FILE_VERTEX:
				if (tokenCount == 0) break;
				
				--tokenCount;
				vertex(tokenCount) = boost::lexical_cast<float>(t);
				break;				

			case OBJ_FILE_FACE:
				if (tokenCount == 0) break;
				
				--tokenCount;
				
				boost::char_separator<char> sep2("//");
				boost::tokenizer< boost::char_separator<char> > tokens2(t, sep2);				
				
				int faceState = OBJ_FILE_VERTEX_PART;
				BOOST_FOREACH(string u, tokens2) {
					int i;
				
					switch (faceState) {
					case OBJ_FILE_VERTEX_PART:
						i = boost::lexical_cast<int>(u);
						try {
							face.vertexList.push_back(vertexList.at(i-1)); 
						} catch (std::out_of_range e) {
							cout << e.what() << endl;
						}
						faceState = OBJ_FILE_NORMAL_PART;
						break;
						
					case OBJ_FILE_NORMAL_PART:
						i = boost::lexical_cast<int>(u);
						try {
							face.faceNormal = vertexNormalList.at(i-1); 
						} catch (std::out_of_range e) {
							cout << e.what() << endl;
						}
						faceState = OBJ_FILE_UNKNOWN;
						break;
					}
				}
				break;
			}
		}
			
		switch (state) {
		case OBJ_FILE_VERTEX_NORMAL:
			if (tokenCount > 0) break;
			vertexNormalList.push_back(vertexNormal);
			break;
							
		case OBJ_FILE_VERTEX:
			if (tokenCount > 0) break;
			vertexList.push_back(vertex);
			break;
					
		case OBJ_FILE_FACE:
			if (tokenCount > 0) break;
			faceList.push_back(face);
			break;
		}
	}

	/* if (vertexList.size() == 0 || vertexList.size() > 5000) {
		cout << "[ObjFileParser] Invalid number of vertices" << endl;	
		return false;
	} */
	
	maxVertex << -9999, -9999, -9999;
	minVertex << 9999, 9999, 9999;
	
	for (unsigned int i=0; i < vertexList.size(); i++) {
		for (unsigned int j=0; j < 3; j++) {
			if (vertexList[i](j) > maxVertex(j)) maxVertex(j) = vertexList[i](j);
			if (vertexList[i](j) < minVertex(j)) minVertex(j) = vertexList[i](j);
		}
	}
    /*
	maxSize = 0;
	for (unsigned int j=0; j < 3; j++) {
		if ((maxVertex(j) - minVertex(j)) > maxSize) maxSize = (maxVertex(j) - minVertex(j));
    }*/

    centerVertex = (maxVertex + minVertex) * 0.5;

    if(type=="head"){
        centerVertex(1) = 5.5f;
    }//0=x,1=z,2=y

    else if(type=="body"){
        centerVertex(1) = maxVertex(1);//0=x,1=z,2=y
    }




    for (unsigned int i=0; i<faceList.size(); i++) {
        for (unsigned int j=0; j<faceList[i].vertexList.size(); j++) {
            for (unsigned int k=0; k<3; k++) {
                faceList[i].vertexList[j](k) = (faceList[i].vertexList[j](k) - centerVertex(k));
            }
        }
    }

    /*
	for (unsigned int i=0; i<faceList.size(); i++) {				
		for (unsigned int j=0; j<faceList[i].vertexList.size(); j++) {
			for (unsigned int k=0; k<3; k++) {
				faceList[i].vertexList[j](k) = (faceList[i].vertexList[j](k) - centerVertex(k)) / maxSize * 4.0f;
			}
		}
	}

	for (unsigned int j=0; j < 3; j++) {
		scaledSize(j) = (maxVertex(j) - minVertex(j)) / maxSize * 4.0f;
    }*/
	
	cout << "[ObjFileParser] Processed vertices: " << vertexList.size() << endl;	
	cout << "[ObjFileParser] Processed vertex normals: " << vertexNormalList.size() << endl;		
	cout << "[ObjFileParser] Processed faces: " << faceList.size() << endl;	
	cout << "[ObjFileParser] Center: " << centerVertex(0) << " " << centerVertex(1) << " " << centerVertex(2) << endl;
	
	fs.close();
	
	return f;
}

std::vector<ObjFace> ObjFileParser::getFaceList(void)
{
    return faceList;
}

std::vector<ObjFace> ObjFileParser::getNewCenterVortex(void)
{
    centerVertex = (maxVertex + minVertex) * 0.5;


    for (unsigned int i=0; i<faceList.size(); i++) {
        for (unsigned int j=0; j<faceList[i].vertexList.size(); j++) {
            for (unsigned int k=0; k<3; k++) {
                faceList[i].vertexList[j](k) = (faceList[i].vertexList[j](k) - centerVertex(k));
            }
        }
    }
    return faceList;
}

Eigen::Vector3f ObjFileParser::getScaledSize(void)
{
	return scaledSize;
}
