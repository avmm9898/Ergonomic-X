/***********************************************************************
** Copyright (C) 2013 LP-Research
** All rights reserved.
** Contact: LP-Research (info@lp-research.com)
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

#ifndef THREE_D_WINDOW
#define THREE_D_WINDOW

#include <QtGui>
#include <QOpenGLWidget>

#include "mainwindow.h"
#include "ImuData.h"
#include "ObjFileParser.h"
#include "LpmsDefinitions.h"

#include <string>
#include <iostream>

#include <Eigen/Dense>
#include <QtConcurrent/QtConcurrent>

using namespace std;


class ThreeDWindow : public QOpenGLWidget
{
    Q_OBJECT

public:	

    ThreeDWindow(QWidget *parent = nullptr);
    ~ThreeDWindow();

	QPoint lastPos;
	int xRot;
	int yRot;
	int zRot;
	int xSRot;
	int ySRot;
	int zSRot;
    ObjFileParser caseObj[5];
	float lpmsCaseScale;
    Eigen::Matrix3f IdentityMatrix;
    Eigen::Matrix3f CorrectionRM;    //使用者視角修正的旋轉矩陣
    Eigen::Matrix3f RotationMatrix;  //來自IMU的旋轉矩陣

	Eigen::Vector3f fieldMap[ABSMAXPITCH][ABSMAXROLL][ABSMAXYAW];
	Eigen::Vector3f hardIronOffset;
	Eigen::Matrix3f softIronMatrix;
    bool objFileSet[5];
	float glob_translate_x;
	float glob_translate_y;
	float glob_translate_z;	

	void drawAxes(void);

    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int width, int height);
	void drawTri(Eigen::Vector3f p0, Eigen::Vector3f p1, Eigen::Vector3f p2, bool fill);
	void drawFloor(void);
    void drawLpmsCase(int n_lpms);
	void drawBackground(void);	
    void loadObjFile(std::string filename, struct LpmsDevice *m_lpms);

signals:


public slots:

	void updateFieldMap(float magField[ABSMAXPITCH][ABSMAXROLL][ABSMAXYAW][3], float hardIronOffset[3], float softIronMatrix[3][3]);
    void updateWindow(void);
	void rotateBy(int xAngle, int yAngle, int zAngle);
	void rotateSceneBy(int xAngle, int yAngle, int zAngle);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);	

	void wheelEvent(QWheelEvent *event);
    void updateRMbyQuat(struct LpmsDevice *m_lpms);
    void model_view_correction(struct LpmsDevice *m_lpms);
private:

};

#endif
