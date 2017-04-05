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
    static void drawPointColud(float pointSize, const QVector3D &center = QVector3D());
};

#endif // ITEMDRAWFUNC_H
