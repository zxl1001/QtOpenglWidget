#include "myopenglwidget1.h"
#include <QOpenGLFunctions>

MyOpenglWidget1::MyOpenglWidget1(QWidget *parent, Qt::WindowFlags f)
    :QOpenGLWidget(parent, f)
{
    m_rTri = 0.0f;
    m_rQuad = 0.0f;
//    QSurfaceFormat format;
//    format.setDepthBufferSize(24);
//    setFormat(format);
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


    drawVerticalCenterLine(QVector3D(0,1,0), QVector3D(0,-1,0));

//        draw2DQuads(QVector3D(-0.5, 0.0, 0.0), 0.25, 0.25);
    draw3DQuads(QVector3D(-0.5,0,3), 0.25, 0.25, 0.25);

//        draw2DTriangles(QVector3D(0.5, 0.0, 0.0), 0.25, 0.25);
    draw3DTriangles(QVector3D(0.5, 0.0, 3), 0.25, 0.25, 0.25);


    m_rQuad += 10;
    m_rTri -= 10;

    qDebug()<<m_rQuad<<m_rTri;

}

void MyOpenglWidget1::drawVerticalCenterLine(const QVector3D &start, const QVector3D &end)
{
    glColor3f(1,1,0);
    glBegin(GL_LINES);
    glVertex3f(start.x(),start.y(), start.z());
    glVertex3f(end.x(), end.y(), end.z());
    glEnd();
}

void MyOpenglWidget1::draw2DQuads(const QVector3D &center, GLfloat h, GLfloat w)
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

void MyOpenglWidget1::draw2DTriangles(const QVector3D &center, GLfloat h, GLfloat w)
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

void MyOpenglWidget1::draw2DPoints(const QVector3D &center, GLfloat size)
{
    glVertex3f(center.x(), center.y(), center.z());
}


void MyOpenglWidget1::draw3DQuads(const QVector3D &center, GLfloat h, GLfloat w, GLfloat d)
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

void MyOpenglWidget1::draw3DTriangles(const QVector3D &center, GLfloat h, GLfloat w, GLfloat d)
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

void MyOpenglWidget1::draw3DPoints(const QVector3D &center, GLfloat size)
{

}


