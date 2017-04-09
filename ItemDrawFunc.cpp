/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    ItemDrawFunc.cpp
 * @brief
 *******************************************************************************
 */
#include "ItemDrawFunc.h"

ItemDrawFunc::ItemDrawFunc()
{

}

void ItemDrawFunc::drawPointColud(float pointSize, const QVector3D &center)
{
    //draw Point cloud
    glPointSize(pointSize);
    glBegin(GL_POINTS);
    for(int i = 0; i<1000; ++i)
    {
        float r = qrand() % 10000 / 10000.00f;
        float g = qrand() % 10000 / 10000.00f;
        float b = qrand() % 10000 / 10000.00f;
        glColor3f(r, g, b);
        glVertex3f(r, g, b);
    }
    glEnd();
    glFlush();
}


void ItemDrawFunc::drawVerticalCenterLine(const QVector3D &start, const QVector3D &end)
{
    glColor3f(1,1,0);
    glBegin(GL_LINES);
    glVertex3f(start.x(),start.y(), start.z());
    glVertex3f(end.x(), end.y(), end.z());
    glEnd();
}

void ItemDrawFunc::draw2DQuads(const QVector3D &center, GLfloat h, GLfloat w, GLfloat radiu)
{
    glPushMatrix();
    glTranslatef(center.x(),center.y(),center.z());
    drawVerticalCenterLine(QVector3D(0, 1,0), QVector3D(0,-1,0));
    glRotatef(radiu, 0,1,0);
    //    glColor4f(1.0,0.0,0.0,1.0); //set the quad color;

    glBegin(GL_QUADS);
    glColor3f( 1.0, 0.0, 0.0 );glVertex3f(-h,-w,0.0);
    glColor3f( 0.0, 1.0, 0.0 );glVertex3f(h,-w, 0.0);
    glColor3f( 0.0, 0.0, 1.0 );glVertex3f(h,w, 0.0);
    glColor3f( 1.0, 1.0, 0.0 );glVertex3f(-h, w, 0.0);
    glEnd();
    glPopMatrix();

}

void ItemDrawFunc::draw2DTriangles(const QVector3D &center, GLfloat h, GLfloat w, GLfloat radiu)
{

    glPushMatrix();
    glTranslatef(center.x(), center.y(), center.z());
    drawVerticalCenterLine(QVector3D(0, 1,0), QVector3D(0,-1,0));
    glRotatef(radiu, 0, 1, 0);
    glClearColor(0.0,0.0,0.0,0.0);
    //    glColor3f(0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f( 1.0, 0.0, 0.0 );glVertex3f(0,w,0.0);
    glColor3f( 0.0, 1.0, 0.0 ); glVertex3f(h,-w,0);
    glColor3f( 0.0, 0.0, 1.0 );glVertex3f(-h,-w,0.0);
    glEnd();
    glPopMatrix();
}


void ItemDrawFunc::draw3DQuads(const QVector3D &center, GLfloat h, GLfloat w, GLfloat d, GLfloat radiu)
{
    glPushMatrix();
    glTranslated(center.x(), center.y(), center.z());

    glRotatef(radiu, 0,1,0);
    glBegin(GL_QUADS);
    //1top
    glColor3f( 1.0, 0.5, 0.0 );
    glVertex3f( h, w, -d);
    glVertex3f(-h, w, -d);
    glVertex3f(-h, w,  d);
    glVertex3f( h, w,  d);

    //2bottom
    glColor3f( 0.0, 1.0, 0.0 );
    glVertex3f( h, -w,  d);
    glVertex3f(-h, -w,  d);
    glVertex3f(-h, -w, -d);
    glVertex3f( h, -w, -d);

    //3front
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( h,  w,  d);
    glVertex3f(-h,  w,  d);
    glVertex3f(-h, -w,  d);
    glVertex3f( h, -w,  d);

    //4back
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f( h, -w,  -d);
    glVertex3f(-h, -w,  -d);
    glVertex3f(-h,  w,  -d);
    glVertex3f( h,  w,  -d);

    //5
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f(-h, w,  d);
    glVertex3f(-h, w, -d);
    glVertex3f(-h,-w, -d);
    glVertex3f(-h,-w,  d);

    //6
    glColor3f( 1.0, 0.0, 1.0 );
    glVertex3f(h,  w, -d);
    glVertex3f(h,  w,  d);
    glVertex3f(h, -w,  d);
    glVertex3f(h, -w, -d);
    glEnd();

    drawVerticalCenterLine(QVector3D(0,1,0), QVector3D(0,-1,0));
    glPopMatrix();

}

void ItemDrawFunc::draw3DTriangles(const QVector3D &center, GLfloat h, GLfloat w, GLfloat d, GLfloat radiu)
{
    glPushMatrix();
    glTranslatef(center.x(), center.y(), center.z());
    glRotatef(radiu, 0,1,0);

    glBegin( GL_TRIANGLES );
    glColor3f(1.0, 0.0, 0.0 );glVertex3f(0, h, 0.0 );
    glColor3f(0.0, 1.0, 0.0 );glVertex3f(-w, -h, d );
    glColor3f(0.0, 0.0, 1.0 );glVertex3f(w, -h, d );

    glColor3f(1.0, 0.0, 0.0 );glVertex3f(0.0, h, 0.0 );
    glColor3f(0.0, 0.0, 1.0 );glVertex3f(w, -h,  d );
    glColor3f(0.0, 1.0, 0.0 );glVertex3f(w, -h, -d );

    glColor3f(1.0, 0.0, 0.0 );glVertex3f(0.0, h, 0.0 );
    glColor3f(0.0, 1.0, 0.0 );glVertex3f(w, -h, -d );
    glColor3f(0.0, 0.0, 1.0 );glVertex3f(-w, -h, -d );

    glColor3f(1.0, 0.0, 0.0 );glVertex3f(0.0, h,0.0 );
    glColor3f(0.0, 0.0, 1.0 );glVertex3f(-w, -h, -d );
    glColor3f(0.0, 1.0, 0.0 );glVertex3f(-w, -h,  d );
    glEnd();
    drawVerticalCenterLine(QVector3D(0,1,0), QVector3D(0,-1,0));
    glPopMatrix();
}
