#ifndef MYOPENGLWIDGET1_H
#define MYOPENGLWIDGET1_H

#include "ItemDrawFunc.h"
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>


class MyOpenglWidget1 : public QOpenGLWidget/*, protected QOpenGLFunctions*/
{
    Q_OBJECT
public:
    MyOpenglWidget1(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    virtual ~MyOpenglWidget1();
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();


private:
    QMatrix4x4 m_projection;
    GLfloat m_rTri;
    GLfloat m_rQuad;
    ItemDrawFunc *m_drawFunc;
};

#endif // MYOPENGLWIDGET1_H
