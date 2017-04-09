#include "myopenglwidget2.h"
#include <QDebug>

MyOpenglWidget2::MyOpenglWidget2(QWidget *parent, Qt::WindowFlags f)
    :QOpenGLWidget(parent, f),m_drawFunc(NULL)
{
     m_rTri = 0;
     m_rQuad = 0;
     m_drawFunc = new ItemDrawFunc;
}

MyOpenglWidget2::~MyOpenglWidget2()
{
    delete m_drawFunc;
}

void MyOpenglWidget2::initializeGL()
{
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}

void MyOpenglWidget2::resizeGL(int w, int h)
{
    if(h == 0)
    {
        h = 1;
    }
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-1,1,0,1,-50,50);
    glOrtho(-1,1, -1,1,-100,10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MyOpenglWidget2::paintGL()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_POLYGON_SMOOTH_HINT);//enable polygon smooth
    glEnable(GL_POINT_SMOOTH_HINT);  //enable point smooth
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST); //set polygon smooth leve
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);   //set point smooth leve
    glEnable (GL_SMOOTH);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //draw Point cloud
//    m_drawFunc->drawPointColud(8.0);
    m_drawFunc->drawCenterLine(QVector3D(-1,0,0), QVector3D(1,0,0));
    m_drawFunc->drawCenterLine(QVector3D(0,-1,0), QVector3D(0,1,0));

    //实现先旋转再移动的效果=>实际使用中要先移动再旋转.
    GLfloat h = 0.1;
    GLfloat w = 0.1;

//    glRotatef(60,0,0,1);   //再旋转
//    glTranslatef(0.5,0,0); //先移动
    glTranslatef(0.5,0,0); //先移动
    glRotatef(60,0,0,1);   //再旋转
    m_drawFunc->draw2DQuads(QVector3D(0,0,0),h,w);
    glFlush();

//    m_rQuad += 10;
//    m_rTri -= 10;
}
