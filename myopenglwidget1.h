#ifndef MYOPENGLWIDGET1_H
#define MYOPENGLWIDGET1_H
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include "GL/glu.h"

class MyOpenglWidget1 : public QOpenGLWidget/*, protected QOpenGLFunctions*/
{
    Q_OBJECT
public:
    MyOpenglWidget1(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
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
    QMatrix4x4 m_projection;
    GLfloat m_rTri;
    GLfloat m_rQuad;
};

#endif // MYOPENGLWIDGET1_H
