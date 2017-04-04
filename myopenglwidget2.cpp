#include "myopenglwidget2.h"
#include <QDebug>

MyOpenglWidget2::MyOpenglWidget2(QWidget *parent, Qt::WindowFlags f)
    :QOpenGLWidget(parent, f)
{
     m_rTri = 0;
     m_rQuad = 0;
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
    glOrtho(-1,1,-1,1,-50,50);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MyOpenglWidget2::paintGL()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_POLYGON_SMOOTH_HINT);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

    drawVerticalCenterLine(QVector3D(0,1,0), QVector3D(0,-1,0));

//        draw2DQuads(QVector3D(-0.5, 0.0, 0.0), 0.25, 0.25);
    draw3DQuads(QVector3D(-0.5,0,3), 0.25, 0.25, 0.25);

//        draw2DTriangles(QVector3D(0.5, 0.0, 0.0), 0.25, 0.25);
    draw3DTriangles(QVector3D(0.5, 0.0, 3), 0.25, 0.25, 0.25);


    m_rQuad += 10;
    m_rTri -= 10;

    qDebug()<<m_rQuad<<m_rTri;
}


void MyOpenglWidget2::drawVerticalCenterLine(const QVector3D &start, const QVector3D &end)
{
    glColor3f(1,1,0);
    glBegin(GL_LINES);
    glVertex3f(start.x(),start.y(), start.z());
    glVertex3f(end.x(), end.y(), end.z());
    glEnd();
}

void MyOpenglWidget2::draw2DQuads(const QVector3D &center, GLfloat h, GLfloat w)
{
    glPushMatrix();
    glTranslatef(center.x(),center.y(),center.z());
    drawVerticalCenterLine(QVector3D(0, 1,0), QVector3D(0,-1,0));
    glRotatef(m_rQuad, 0,1,0);
    //    glColor4f(1.0,0.0,0.0,1.0); //set the quad color;

    glBegin(GL_QUADS);
    glColor3f( 1.0, 0.0, 0.0 );glVertex3f(-h,-w,0.0);
    glColor3f( 0.0, 1.0, 0.0 );glVertex3f(h,-w, 0.0);
    glColor3f( 0.0, 0.0, 1.0 );glVertex3f(h,w, 0.0);
    glColor3f( 1.0, 1.0, 0.0 );glVertex3f(-h, w, 0.0);
    glEnd();
    glPopMatrix();

}

void MyOpenglWidget2::draw2DTriangles(const QVector3D &center, GLfloat h, GLfloat w)
{
    glPushMatrix();
    glTranslatef(center.x(), center.y(), center.z());
    drawVerticalCenterLine(QVector3D(0, 1,0), QVector3D(0,-1,0));
    glRotatef(m_rTri, 0, 1, 0);
    glClearColor(0.0,0.0,0.0,0.0);
    //    glColor3f(0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f( 1.0, 0.0, 0.0 );glVertex3f(0,w,0.0);
    glColor3f( 0.0, 1.0, 0.0 ); glVertex3f(h,-w,0);
    glColor3f( 0.0, 0.0, 1.0 );glVertex3f(-h,-w,0.0);
    glEnd();
    glPopMatrix();
}

void MyOpenglWidget2::draw2DPoints(const QVector3D &center, GLfloat size)
{
    glVertex3f(center.x(), center.y(), center.z());
}


void MyOpenglWidget2::draw3DQuads(const QVector3D &center, GLfloat h, GLfloat w, GLfloat d)
{
    glPushMatrix();
    glTranslated(center.x(), center.y(), center.z());

    glRotatef(m_rQuad, 0,1,0);
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

void MyOpenglWidget2::draw3DTriangles(const QVector3D &center, GLfloat h, GLfloat w, GLfloat d)
{
    glPushMatrix();
    glTranslatef(center.x(), center.y(), center.z());
    glRotatef(m_rTri, 0,1,0);

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

void MyOpenglWidget2::draw3DPoints(const QVector3D &center, GLfloat size)
{

}
