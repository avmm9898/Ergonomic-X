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
      objFileSet{false}
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWindow()));
    timer->start(0);


    IdentityMatrix = Eigen::Matrix3f::Identity();


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


Eigen::Vector3f glposition;
void ThreeDWindow::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(glob_translate_x, glob_translate_y, glob_translate_z);

    glTranslatef(0.0f, 0.0f, -20.0f);

    //drawBackground();

    glRotatef(xRot / 16.0f, 1.0f, 0.0f, 0.0f);
    //glRotatef(yRot / 16.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(zRot / 16.0f, 0.0f, 0.0f, 1.0f);


    drawAxes();
    //drawFloor();

    Eigen::Vector3f vertex_head;
    Eigen::Vector3f vertex_rUpperArm,vertex_rLowerArm,vertex_rWrist;
    Eigen::Vector3f vertex_lUpperArm,vertex_lLowerArm,vertex_lWrist;
    Eigen::Vector3f vertex_lUpperLeg,vertex_rUpperLeg,vertex_lLowerLeg,vertex_rLowerLeg;

    //these are the parts connected to body directly
    vertex_head[0]=-0.1;
    vertex_head[1]= 2.22f;
    vertex_head[2]=0;

    vertex_rUpperArm[0]=-0.22; //y
    vertex_rUpperArm[1]=1.89; //z
    vertex_rUpperArm[2]=0.7 ; //x

    vertex_lUpperArm[0]=-0.27; //y
    vertex_lUpperArm[1]=1.89; //z
    vertex_lUpperArm[2]=-0.75 ; //x

    vertex_rUpperLeg[0]=-0.12; //y
    vertex_rUpperLeg[1]=0; //z
    vertex_rUpperLeg[2]=0.3 ; //x

    vertex_lUpperLeg[0]=-0.16; //y
    vertex_lUpperLeg[1]=0; //z
    vertex_lUpperLeg[2]=-0.3 ; //x
    //


    Eigen::Vector3f end_rUpperArm=caseObj[2].getendVortex();
    Eigen::Vector3f end_rLowerArm=caseObj[3].getendVortex();
    Eigen::Vector3f end_lUpperArm=caseObj[5].getendVortex();
    Eigen::Vector3f end_lLowerArm=caseObj[6].getendVortex();
    Eigen::Vector3f end_rUpperLeg=caseObj[8].getendVortex();
    Eigen::Vector3f end_lUpperLeg=caseObj[10].getendVortex();


    std::list<LpmsDevice *>::iterator it;
    //loop 12 models
    for(int i=0;i<12;i++){
        if (objFileSet[i] == true) {
            for (it = MainWindow::lpmsList.begin(); it != MainWindow::lpmsList.end(); ++it) {
                if((*it)->getme()->id==i){
                    model_view_correction((*it)->getme());
                    updateRMbyQuat((*it)->getme());

                    glPushMatrix();
                    if((*it)->getme()->type=="body"){
                        glTranslatef(0.0f, 0.0f, 0.0f);
                        BodyRM=RotationMatrix;
                        BodyCRM=CorrectionRM;
                    }
                    else if((*it)->getme()->type=="head"){
                        glposition = BodyRM * BodyCRM * vertex_head;
                        glTranslatef(glposition[0],  glposition[1], glposition[2]);
                    }
                    else if((*it)->getme()->type=="lUpperArm"){
                        glposition = BodyRM * BodyCRM * vertex_lUpperArm;
                        glTranslatef(glposition[0],  glposition[1], glposition[2]);
                        vertex_lLowerArm[0]=glposition[1];
                        vertex_lLowerArm[1]=glposition[2];
                        vertex_lLowerArm[2]=glposition[0];
                        lUpperArmRM=RotationMatrix;
                        lUpperArmCRM=CorrectionRM;
                    }
                    else if((*it)->getme()->type=="lLowerArm"){
                        glposition = lUpperArmRM * lUpperArmCRM * end_lUpperArm;
                        vertex_lLowerArm[0]=glposition[1]+vertex_lLowerArm[0];
                        vertex_lLowerArm[1]=glposition[2]+vertex_lLowerArm[1];
                        vertex_lLowerArm[2]=glposition[0]+vertex_lLowerArm[2];
                        glTranslatef(vertex_lLowerArm[2],  vertex_lLowerArm[0], vertex_lLowerArm[1]);
                        lLowerArmRM=RotationMatrix;
                        lLowerArmCRM=CorrectionRM;

                    }
                    else if((*it)->getme()->type=="lWrist"){
                        glposition = lLowerArmRM * lLowerArmCRM * end_lLowerArm;
                        vertex_lWrist[0]=glposition[1]+vertex_lLowerArm[0];
                        vertex_lWrist[1]=glposition[2]+vertex_lLowerArm[1];
                        vertex_lWrist[2]=glposition[0]+vertex_lLowerArm[2];
                        glTranslatef(vertex_lWrist[2],  vertex_lWrist[0], vertex_lWrist[1]);
                    }
                    else if((*it)->getme()->type=="rUpperArm"){
                        glposition = BodyRM * BodyCRM * vertex_rUpperArm;
                        glTranslatef(glposition[0],  glposition[1], glposition[2]);
                        vertex_rLowerArm[0]=glposition[1];
                        vertex_rLowerArm[1]=glposition[2];
                        vertex_rLowerArm[2]=glposition[0];
                        rUpperArmRM=RotationMatrix;
                        rUpperArmCRM=CorrectionRM;
                    }
                    else if((*it)->getme()->type=="rLowerArm"){
                        glposition = rUpperArmRM * rUpperArmCRM * end_rUpperArm;
                        vertex_rLowerArm[0]=glposition[1]+vertex_rLowerArm[0];
                        vertex_rLowerArm[1]=glposition[2]+vertex_rLowerArm[1];
                        vertex_rLowerArm[2]=glposition[0]+vertex_rLowerArm[2];
                        glTranslatef(vertex_rLowerArm[2],  vertex_rLowerArm[0], vertex_rLowerArm[1]);
                        rLowerArmRM=RotationMatrix;
                        rLowerArmCRM=CorrectionRM;

                    }
                    else if((*it)->getme()->type=="rWrist"){
                        glposition = rLowerArmRM * rLowerArmCRM * end_rLowerArm;
                        vertex_rWrist[0]=glposition[1]+vertex_rLowerArm[0];
                        vertex_rWrist[1]=glposition[2]+vertex_rLowerArm[1];
                        vertex_rWrist[2]=glposition[0]+vertex_rLowerArm[2];
                        glTranslatef(vertex_rWrist[2],  vertex_rWrist[0], vertex_rWrist[1]);
                    }
                    else if((*it)->getme()->type=="rUpperLeg"){
                        glposition = BodyRM * BodyCRM * vertex_rUpperLeg;
                        glTranslatef(glposition[0],  glposition[1], glposition[2]);
                        vertex_rLowerLeg[0]=glposition[1];
                        vertex_rLowerLeg[1]=glposition[2];
                        vertex_rLowerLeg[2]=glposition[0];
                        rUpperLegRM=RotationMatrix;
                        rUpperLegCRM=CorrectionRM;
                    }
                    else if((*it)->getme()->type=="rLowerLeg"){
                        glposition = rUpperLegRM * rUpperLegCRM * end_rUpperLeg;
                        vertex_rLowerLeg[0]=glposition[1]+vertex_rLowerLeg[0];
                        vertex_rLowerLeg[1]=glposition[2]+vertex_rLowerLeg[1];
                        vertex_rLowerLeg[2]=glposition[0]+vertex_rLowerLeg[2];
                        glTranslatef(vertex_rLowerLeg[2],  vertex_rLowerLeg[0], vertex_rLowerLeg[1]);
                    }
                    else if((*it)->getme()->type=="lUpperLeg"){

                        glposition = BodyRM * BodyCRM * vertex_lUpperLeg;
                        glTranslatef(glposition[0],  glposition[1], glposition[2]);
                        vertex_lLowerLeg[0]=glposition[1];
                        vertex_lLowerLeg[1]=glposition[2];
                        vertex_lLowerLeg[2]=glposition[0];
                        lUpperLegRM=RotationMatrix;
                        lUpperLegCRM=CorrectionRM;
                    }
                    else if((*it)->getme()->type=="lLowerLeg"){
                        glposition = lUpperLegRM * lUpperLegCRM * end_lUpperLeg;
                        vertex_lLowerLeg[0]=glposition[1]+vertex_lLowerLeg[0];
                        vertex_lLowerLeg[1]=glposition[2]+vertex_lLowerLeg[1];
                        vertex_lLowerLeg[2]=glposition[0]+vertex_lLowerLeg[2];
                        glTranslatef(vertex_lLowerLeg[2],  vertex_lLowerLeg[0], vertex_lLowerLeg[1]);
                    }

                    drawLpmsCase(i);
                    glPopMatrix();
                }
            }


            //l = caseObj[i].getScaledSize() * 0.5f + Eigen::Vector3f(0.2f, 0.2f, 0.2f);

        }

    }

}

void ThreeDWindow::drawBackground(void)
{
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);

    glBegin(GL_QUADS);
    glColor3f((GLfloat) 1, (GLfloat) 1, (GLfloat) 1.0);
    glVertex3f(-50.0, 50.0, -50.0);
    glVertex3f(-50.0, -50.0, -50.0);

    glColor3f((GLfloat) 1, (GLfloat) 1, (GLfloat) 1.0);
    glVertex3f(50.0, -50.0, -50.0);
    glVertex3f(50.0, 50.0, -50.0);
    glEnd();

    glEnable(GL_LIGHTING);
    glEnable(GL_CULL_FACE);
}



void ThreeDWindow::drawLpmsCase(int n_lpms)
{
    Eigen::Matrix3f M;
    M = Eigen::AngleAxisf(-90 * d2r, Eigen::Vector3f::UnitX()) *
            Eigen::AngleAxisf(0 * d2r, Eigen::Vector3f::UnitY()) *
            Eigen::AngleAxisf(0 * d2r, Eigen::Vector3f::UnitZ());

    std::vector<ObjFace> faceList = caseObj[n_lpms].getFaceList();
    //glColor3f((GLfloat) 0.9, (GLfloat) 0.9, (GLfloat) 0.9);
    glColor3f((GLfloat) 184/255, (GLfloat) 151/255, (GLfloat) 128/255);
    for (unsigned int i=0; i<faceList.size(); i++) {

        drawTri(RotationMatrix * CorrectionRM * faceList[i].vertexList[2],
                RotationMatrix * CorrectionRM * faceList[i].vertexList[1],
                RotationMatrix * CorrectionRM * faceList[i].vertexList[0], true);
        drawTri(RotationMatrix * CorrectionRM * faceList[i].vertexList[0],
                RotationMatrix * CorrectionRM * faceList[i].vertexList[1],
                RotationMatrix * CorrectionRM * faceList[i].vertexList[2], true);
    }

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
    for (float i=-5; i <= 5; i+=1.0f) {
        if (i != 0) {
            glVertex3f(i, -5.0f, 0.0f);
            glVertex3f(i, 5.0f, 0.0f);
            glVertex3f(-5.0f, i, 0.0f);
            glVertex3f(5.0f, i, 0.0f);
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


void ThreeDWindow::rotateBy(float xAngle, float yAngle, float zAngle)
{
    xRot += xAngle;
    yRot += yAngle;
    zRot += zAngle;
    update();
}


void ThreeDWindow::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void ThreeDWindow::mouseMoveEvent(QMouseEvent *event)
{
    float dx = event->x() - lastPos.x();
    float dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::RightButton) {
        rotateBy(8 * dy, 8 * dy, 8* dx);
    }
    else if (event->buttons() & Qt::LeftButton)
    {
        glob_translate_x +=dx/100.f;
        glob_translate_y +=-dy/100.f;  //方向和視圖相反
    }
    lastPos = event->pos();
}

void ThreeDWindow::wheelEvent(QWheelEvent *event)
{
    glob_translate_z += (float)event->angleDelta().y() / 100.0f;
}
void ThreeDWindow::updateRMbyQuat(struct LpmsDevice *m_lpms)
{

    QMatrix3x3 a;
    a=m_lpms->quat_raw.toRotationMatrix();

    a=a.transposed();

    RotationMatrix(0,0)=a(0,0);
    RotationMatrix(0,1)=a(0,1);
    RotationMatrix(0,2)=a(0,2);
    RotationMatrix(1,0)=a(1,0);
    RotationMatrix(1,1)=a(1,1);
    RotationMatrix(1,2)=a(1,2);
    RotationMatrix(2,0)=a(2,0);
    RotationMatrix(2,1)=a(2,1);
    RotationMatrix(2,2)=a(2,2);

    /*ps1
    float qw=m_lpms->quat_ajusted.scalar();
    float qx=m_lpms->quat_ajusted.x();
    float qy=m_lpms->quat_ajusted.y();
    float qz=m_lpms->quat_ajusted.z();
    */
    //    float qw=m_lpms->quat_raw.scalar();
    //    float qx=m_lpms->quat_raw.x();
    //    float qy=m_lpms->quat_raw.y();
    //    float qz=m_lpms->quat_raw.z();

    //    float xx      = qx * qx;
    //    float xy      = qx * qy;
    //    float xz      = qx * qz;
    //    float xw      = qx * qw;

    //    float yy      = qy * qy;
    //    float yz      = qy * qz;
    //    float yw      = qy * qw;

    //    float zz      = qz * qz;
    //    float zw      = qz * qw;
    //    RotationMatrix(0,0)= 1.f - 2.f * ( yy + zz );
    //    RotationMatrix(0,1)=     2.f * ( xy - zw );
    //    RotationMatrix(0,2)=     2.f * ( xz + yw );
    //    RotationMatrix(1,0)=     2.f * ( xy + zw );
    //    RotationMatrix(1,1)= 1.f - 2.f * ( xx + zz );
    //    RotationMatrix(1,2) =     2.f * ( yz - xw );
    //    RotationMatrix(2,0)=     2.f * ( xz - yw );
    //    RotationMatrix(2,1) =     2.f * ( yz + xw );
    //    RotationMatrix(2,2) = 1.f - 2.f * ( xx + yy );
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
