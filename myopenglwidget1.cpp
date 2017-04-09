#include "myopenglwidget1.h"
#include <QOpenGLFunctions>

MyOpenglWidget1::MyOpenglWidget1(QWidget *parent, Qt::WindowFlags f)
    :QOpenGLWidget(parent, f)
{
    m_rTri = 0.0f;
    m_rQuad = 0.0f;
    m_drawFunc = new ItemDrawFunc;
//    QSurfaceFormat format;
//    format.setDepthBufferSize(24);
    //    setFormat(format);
}

MyOpenglWidget1::~MyOpenglWidget1()
{
    delete m_drawFunc;
}

void MyOpenglWidget1::initializeGL()
{

//    initializeOpenGLFunctions();
     glClearColor(0,0,0,1);
     glEnable(GL_DEPTH_TEST);
     glEnable(GL_LIGHT0);
     glEnable(GL_LIGHTING); //启用光照
     glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
     glEnable(GL_COLOR_MATERIAL);
}

void MyOpenglWidget1::resizeGL(int w, int h)
{
    if(h == 0)
    {
        h = 1;
    }
//    glViewport（0,0，w，h）
//     glMatrixMode（GL_PROjECTION）;
//     glLoadIdentity（）;
//     gluPerspective（45，（float）w / h，0.01，100.0）;
//     glMatrixMode（GL_MODELVIEW）;
//     glLoadIdentity（）;
//     gluLookAt（0,0,5,0,0,0,0,1,0）;
//    m_projection.setToIdentity();
//    m_projection.perspective(60.0f, w / float(h), 0.01f, 100.0f);
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (GLfloat)w / (GLfloat)h, 0.01f, 256.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5, 0,0,0,0,1,0);


}

void MyOpenglWidget1::paintGL()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_POLYGON_SMOOTH_HINT);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);


    m_drawFunc->drawVerticalCenterLine(QVector3D(0,1,0), QVector3D(0,-1,0));

//        draw2DQuads(QVector3D(-0.5, 0.0, 0.0), 0.25, 0.25);
    m_drawFunc->draw3DQuads(QVector3D(-0.5,0,3), 0.25, 0.25, 0.25, m_rQuad);

//        draw2DTriangles(QVector3D(0.5, 0.0, 0.0), 0.25, 0.25);
    m_drawFunc->draw3DTriangles(QVector3D(0.5, 0.0, 3), 0.25, 0.25, 0.25, m_rTri);


    m_rQuad += 10;
    m_rTri -= 10;

    qDebug()<<"myopenglwidget1 update";

}


