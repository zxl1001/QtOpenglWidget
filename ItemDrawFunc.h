/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    ItemDrawFunc.h
 * @brief
 *******************************************************************************
 */
#ifndef ITEMDRAWFUNC_H
#define ITEMDRAWFUNC_H
#include <QMatrix4x4>
#include "GL/gl.h"
#include "GL/glu.h"

class ItemDrawFunc
{
public:
    ItemDrawFunc();

    void drawVerticalCenterLine(const QVector3D &start, const QVector3D &end);

    void draw2DQuads(const QVector3D &center, GLfloat h, GLfloat w, GLfloat radiu); //绘制四边形
    void draw2DTriangles(const QVector3D &center, GLfloat h, GLfloat w, GLfloat radiu);//绘制三角形

    void draw3DQuads(const QVector3D &center, GLfloat h, GLfloat w, GLfloat d, GLfloat radiu);
    void draw3DTriangles(const QVector3D &center, GLfloat h, GLfloat w, GLfloat d, GLfloat radiu);

    void drawPointColud(float pointSize, const QVector3D &center = QVector3D());
};

#endif // ITEMDRAWFUNC_H
