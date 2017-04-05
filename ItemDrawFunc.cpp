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
