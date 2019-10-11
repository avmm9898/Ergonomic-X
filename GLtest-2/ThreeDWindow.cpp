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

#include <QtGui>
#include <QtOpenGL>
#include "ui_mainwindow.h"
#include "ThreeDWindow.h"
#include <iostream>


using namespace std;
const float d2r = 0.01745f;


ThreeDWindow::ThreeDWindow(QWidget *parent)
    : QOpenGLWidget{parent},
      xRot(0),
      yRot(0),
      zRot(0),
      xSRot(0),
      ySRot(0),
      zSRot(0),
      objFileSet{false}
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWindow()));
    timer->start(50);


    IdentityMatrix = Eigen::Matrix3f::Identity();
    //CorrectionRM= Eigen::Matrix3f::Identity();


    glob_translate_x = 0.0f;
    glob_translate_y = 0.0f;
    glob_translate_z = 0.0f;

}

ThreeDWindow::~ThreeDWindow()
{
}


void ThreeDWindow::loadObjFile(std::string filename, struct LpmsDevice *m_lpms)
{
    int i=m_lpms->id;
    if (caseObj[i].parse(filename, m_lpms->type) == true) objFileSet[i] = true;
}



void ThreeDWindow::updateWindow(void)
{  
    update();
}


void ThreeDWindow::initializeGL()
{
    static GLfloat lightPosition[4] = { 0.0, 0.0, 10.0, 0.75 };

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glEnable(GL_COLOR_MATERIAL);

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}



void ThreeDWindow::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(glob_translate_x, glob_translate_y, glob_translate_z);

    glTranslatef(0.0f, 0.0f, -20.0f);

    drawBackground();

    glRotatef(xRot / 16.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot / 16.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(zRot / 16.0f, 0.0f, 0.0f, 1.0f);


    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glRotatef(45, 0.0f, 1.0f, 0.0f);

    drawAxes();


    Eigen::Vector3f l;
    std::list<LpmsDevice *>::iterator it;

    for(int i=0;i<10;i++){
        if (objFileSet[i] == false) {
            //drawPointCube();
            //l = Eigen::Vector3f(2.4f, 0.9f, 1.4f);
        }
        else {

            for (it = MainWindow().lpmsList.begin(); it != MainWindow().lpmsList.end(); ++it) {
                 if((*it)->getme()->id==i){
                     model_view_correction((*it)->getme());
                     updateRMbyQuat((*it)->getme());
                 }
             }



//            model_view_correction(&MainWindow::LPMS_SEARCH_ID[i]);
//            updateRMbyQuat(&MainWindow::LPMS_SEARCH_ID[i]);
            drawLpmsCase(i);
            //l = caseObj[i].getScaledSize() * 0.5f + Eigen::Vector3f(0.2f, 0.2f, 0.2f);

        }
    }

}

void ThreeDWindow::drawBackground(void)
{
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);

    glBegin(GL_QUADS);
    glColor3f((GLfloat) 0.8, (GLfloat) 0.8, (GLfloat) 1.0);
    glVertex3f(-50.0, 50.0, -50.0);
    glVertex3f(-50.0, -50.0, -50.0);

    glColor3f((GLfloat) 0.2, (GLfloat) 0.2, (GLfloat) 1.0);
    glVertex3f(50.0, -50.0, -50.0);
    glVertex3f(50.0, 50.0, -50.0);
    glEnd();

    glEnable(GL_LIGHTING);
    glEnable(GL_CULL_FACE);
}

void ThreeDWindow::updateFieldMap(float magField[ABSMAXPITCH][ABSMAXROLL][ABSMAXYAW][3],
float hardIronOffset[3], float softIronMatrix[3][3])
{
    for (int i=0; i<ABSMAXPITCH; i++) {
        for (int j=0; j<ABSMAXROLL; j++) {
            for (int k=0; k<ABSMAXYAW; k++) {
                for (int l=0; l<3; l++) {
                    this->fieldMap[i][j][k](l) = magField[i][j][k][l];
                }
            }
        }
    }

    for (int i=0; i<3; i++) {
        this->hardIronOffset(i) = hardIronOffset[i];
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            this->softIronMatrix(i, j) = softIronMatrix[i][j];
        }
    }
}


void ThreeDWindow::drawLpmsCase(int n_lpms)
{


    std::vector<ObjFace> faceList = caseObj[n_lpms].getFaceList();

    for (unsigned int i=0; i<faceList.size(); i++) {

        drawTri(RotationMatrix.transpose() * CorrectionRM * faceList[i].vertexList[2],
                RotationMatrix.transpose() * CorrectionRM * faceList[i].vertexList[1],
                RotationMatrix.transpose() * CorrectionRM * faceList[i].vertexList[0], true);
        drawTri(RotationMatrix.transpose() * CorrectionRM * faceList[i].vertexList[0],
                RotationMatrix.transpose() * CorrectionRM * faceList[i].vertexList[1],
                RotationMatrix.transpose() * CorrectionRM * faceList[i].vertexList[2], true);
    }


    glColor3f((GLfloat) 0.9, (GLfloat) 0.9, (GLfloat) 0.9);


}


void ThreeDWindow::drawAxes(void)
{
    glDisable(GL_LIGHTING);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 0.0, 0.0f);
    glVertex3f(-50.0, 0.0, 0.0f);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0, -50.0, 0.0f);
    glVertex3f(0.0, 50.0, 0.0f);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0, 0.0, -50.0f);
    glVertex3f(0.0, 0.0, 50.0f);
    glEnd();
    glEnable(GL_LIGHTING);
}

void ThreeDWindow::drawFloor(void)
{
    glBegin(GL_LINES);
    glColor3f(0.8f, 0.8f, 0.8f);
    for (float i=-10; i <= 10; i+=0.2f) {
        if (i != 0) {
            glVertex3f(i, 0.0f, -10.0f);
            glVertex3f(i, 0.0f, 10.0f);
            glVertex3f(-10.0f, 0.0f, i);
            glVertex3f(10.0f, 0.0f, i);
        }
    }
    glEnd();
}

void ThreeDWindow::resizeGL(int width, int height)
{

    glViewport(0, 0, (GLint)width, (GLint)height);               //重置當前的視口


    //int side = qMin(width, height);

    //glViewport((width - side) / 2, (height - side) / 2, side, side);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.6, +0.6, -0.6, +0.6, 4.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_NORMALIZE);
}



void ThreeDWindow::drawTri(Eigen::Vector3f p0, Eigen::Vector3f p1, Eigen::Vector3f p2, bool fill)
{	
    Eigen::Vector3f a, b, c, d;
    a = p1 - p0;
    b = p2 - p0;
    c = a.cross(b);
    d = c / c.norm();

    if (fill == true) {
        glBegin(GL_TRIANGLES);
    } else {
        glBegin(GL_LINE_LOOP);
    }

    glNormal3f(d(0), d(1), d(2));

    glVertex3f(p0(0), p0(1), p0(2));
    glVertex3f(p1(0), p1(1), p1(2));
    glVertex3f(p2(0), p2(1), p2(2));

    glEnd();

}


void ThreeDWindow::rotateBy(int xAngle, int yAngle, int zAngle)
{
    xRot += xAngle;
    yRot += yAngle;
    zRot += zAngle;
    update();
}

void ThreeDWindow::rotateSceneBy(int xAngle, int yAngle, int zAngle)
{
    xSRot += xAngle;
    ySRot += yAngle;
    zSRot += zAngle;
    update();
}

void ThreeDWindow::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void ThreeDWindow::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        rotateBy(8 * dy, 8 * dx, 0);
    } else if (event->buttons() & Qt::RightButton) {
        rotateSceneBy(8 * dy, 8 * dy, 8 * dx);
    }

    lastPos = event->pos();
}

void ThreeDWindow::wheelEvent(QWheelEvent *event)
{
    glob_translate_z += (float)event->angleDelta().y() / 100.0f;
}
void ThreeDWindow::updateRMbyQuat(struct LpmsDevice *m_lpms)
{
    /*ps1
    float qw=m_lpms->quat_ajusted.scalar();
    float qx=m_lpms->quat_ajusted.x();
    float qy=m_lpms->quat_ajusted.y();
    float qz=m_lpms->quat_ajusted.z();
    */
    float qw=m_lpms->quat_raw.scalar();
    float qx=m_lpms->quat_raw.x();
    float qy=m_lpms->quat_raw.y();
    float qz=m_lpms->quat_raw.z();


    float xx      = qx * qx;
    float xy      = qx * qy;
    float xz      = qx * qz;
    float xw      = qx * qw;

    float yy      = qy * qy;
    float yz      = qy * qz;
    float yw      = qy * qw;

    float zz      = qz * qz;
    float zw      = qz * qw;


    RotationMatrix(0,0)= 1.f - 2.f * ( yy + zz );
    RotationMatrix(0,1)=     2.f * ( xy - zw );
    RotationMatrix(0,2)=     2.f * ( xz + yw );
    RotationMatrix(1,0)=     2.f * ( xy + zw );
    RotationMatrix(1,1)= 1.f - 2.f * ( xx + zz );
    RotationMatrix(1,2) =     2.f * ( yz - xw );
    RotationMatrix(2,0)=     2.f * ( xz - yw );
    RotationMatrix(2,1) =     2.f * ( yz + xw );
    RotationMatrix(2,2) = 1.f - 2.f * ( xx + yy );
}
void ThreeDWindow::model_view_correction(struct LpmsDevice *m_lpms){

    Eigen::Matrix3f scale;

    scale <<	1, 0, 0,
            0, 0, -1,
            0, 1, 0;


    CorrectionRM = Eigen::AngleAxisf(m_lpms->viewX * d2r, Eigen::Vector3f::UnitX()) *
            Eigen::AngleAxisf(m_lpms->viewY * d2r, Eigen::Vector3f::UnitY()) *
            Eigen::AngleAxisf(m_lpms->viewZ * d2r, Eigen::Vector3f::UnitZ());
    CorrectionRM=CorrectionRM*scale;

}
