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
    glOrtho(-1,1,0,1,-50,50);
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
    //draw Point cloud
    m_drawFunc->drawPointColud(8.0);
    qDebug()<<"myopenglwidget2 Point cloud update";
    m_rQuad += 10;
    m_rTri -= 10;
}
