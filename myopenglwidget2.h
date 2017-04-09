#ifndef MYOPENGLWIDGET2_H
#define MYOPENGLWIDGET2_H

#include "ItemDrawFunc.h"
#include <QOpenGLWidget>
#include <QVector3D>


class MyOpenglWidget2: public QOpenGLWidget
{
    Q_OBJECT
public:
    MyOpenglWidget2(QWidget *parent=Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    virtual ~MyOpenglWidget2();
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void drawVerticalCenterLine(const QVector3D &start, const QVector3D &end);

    void draw2DQuads(const QVector3D &center, GLfloat h, GLfloat w); //绘制四边形
    void draw2DTriangles(const QVector3D &center, GLfloat h, GLfloat w);//绘制三角形
    void draw2DPoints(const QVector3D &center, GLfloat size); //绘制点

    void draw3DQuads(const QVector3D &center, GLfloat h, GLfloat w, GLfloat d);
    void draw3DTriangles(const QVector3D &center, GLfloat h, GLfloat w, GLfloat d);
    void draw3DPoints(const QVector3D &center, GLfloat size);

private:
    GLfloat m_rTri;
    GLfloat m_rQuad;
    ItemDrawFunc *m_drawFunc;
};

#endif // MYOPENGLWIDGET2_H
