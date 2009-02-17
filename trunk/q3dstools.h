#ifndef Q3DSTOOLS_H
#define Q3DSTOOLS_H

#include <lib3ds/file.h>
#include <lib3ds/camera.h>
#include <lib3ds/mesh.h>
#include <lib3ds/node.h>
#include <lib3ds/material.h>
#include <lib3ds/matrix.h>
#include <lib3ds/vector.h>
#include <lib3ds/light.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <QGLWidget>
class Q3dsTools
{
    public:
        static GLuint cameraList;
        static GLuint lightList;	/* Icon display lists */
        Q3dsTools();
        static GLuint getCameraList();
        static GLuint getLightList();
        static void drawSolidCylinder(double r, double h, int slices);
        static void drawSolidBox(double bx, double by, double bz);
        static void create_icons();
};

GLuint Q3dsTools::cameraList;//must be declared again outside the class
GLuint Q3dsTools::lightList;

Q3dsTools::Q3dsTools()
{
    create_icons();
}
GLuint Q3dsTools::getCameraList()
{
    return cameraList;
}
GLuint Q3dsTools::getLightList()
{
    return lightList;
}
void Q3dsTools::drawSolidCylinder(double r, double h, int slices)
{
    GLUquadricObj *qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_SMOOTH);
    glPushMatrix();
    glTranslated(0., 0., -h/2);
    gluCylinder( qobj, r, r, h, slices, 1 );
    glPushMatrix();
    glRotated(180., 1.,0.,0.);
    gluDisk( qobj, 0., r, slices, 1 );
    glPopMatrix();
    glTranslated(0., 0., h);
    gluDisk( qobj, 0., r, slices, 1 );
    glPopMatrix();
}
void Q3dsTools::drawSolidBox(double bx, double by, double bz)
{
    glBegin(GL_POLYGON);
    glNormal3d(0.,0.,1.);
    glVertex3d(bx,by,bz);
    glVertex3d(-bx,by,bz);
    glVertex3d(-bx,-by,bz);
    glVertex3d(bx,-by,bz);
    glEnd();
    glBegin(GL_POLYGON);
    glNormal3d(0.,0.,-1.);
    glVertex3d(-bx,by,-bz);
    glVertex3d(bx,by,-bz);
    glVertex3d(bx,-by,-bz);
    glVertex3d(-bx,-by,-bz);
    glEnd();
    glBegin(GL_POLYGON);
    glNormal3d(0.,-1.,0.);
    glVertex3d(-bx,by,bz);
    glVertex3d(bx,by,bz);
    glVertex3d(bx,by,-bz);
    glVertex3d(-bx,by,-bz);
    glEnd();
    glBegin(GL_POLYGON);
    glNormal3d(0.,-1.,0.);
    glVertex3d(bx,-by,bz);
    glVertex3d(-bx,-by,bz);
    glVertex3d(-bx,-by,-bz);
    glVertex3d(bx,-by,-bz);
    glEnd();
    glBegin(GL_POLYGON);
    glNormal3d(1.,0.,0.);
    glVertex3d(bx,by,bz);
    glVertex3d(bx,-by,bz);
    glVertex3d(bx,-by,-bz);
    glVertex3d(bx,by,-bz);
    glEnd();
    glBegin(GL_POLYGON);
    glNormal3d(-1.,0.,0.);
    glVertex3d(-bx,by,-bz);
    glVertex3d(-bx,-by,-bz);
    glVertex3d(-bx,-by,bz);
    glVertex3d(-bx,by,bz);
    glEnd();
}
/*!
 * Create camera and light icons
 */
void Q3dsTools::create_icons()
{
    GLUquadricObj *qobj;
#define	CBX	.25	// camera body dimensions
#define	CBY	1.5
#define	CBZ	1.
    const GLfloat dgrey[4] = {.25,.25,.25,1.};
    const GLfloat grey[4] = {.5,.5,.5,1.};
    const GLfloat lgrey[4] = {.75,.75,.75,1.};
    const GLfloat black[4] = {0.,0.,0.,1.};
    qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_SMOOTH);
    cameraList = glGenLists(1);
    glNewList(cameraList, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT, dgrey);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lgrey);
    glMaterialfv(GL_FRONT, GL_SPECULAR, black);
    glEnable(GL_CULL_FACE);
    Q3dsTools::drawSolidBox(CBX,CBY,CBZ);
    glPushMatrix();
    glTranslatef(0.,.9,1.8);
    glRotatef(90., 0.,1.,0.);
    Q3dsTools::drawSolidCylinder(1., CBX*2, 12);
    glTranslatef(0.,-1.8,0.);
    Q3dsTools::drawSolidCylinder(1., CBX*2, 12);
    glPopMatrix();
    glDisable(GL_CULL_FACE);
    glPushMatrix();
    glTranslated(0.,CBY,0.);
    glRotated(-90., 1.,0.,0.);
    gluCylinder(qobj, .2, .5, 1., 12, 1);
    glPopMatrix();
    glEndList();

    lightList = glGenLists(1);
    glNewList(lightList, GL_COMPILE);
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, dgrey);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, dgrey);
    glMaterialfv(GL_FRONT, GL_SPECULAR, grey);
    glEnable(GL_CULL_FACE);
    gluSphere(qobj, .5, 12., 6.);
    glRotated(180.,1.,0.,0.);
    glMaterialfv(GL_FRONT, GL_EMISSION, dgrey);
    gluCylinder(qobj, .2, .2, 1., 12, 1);
    glPopMatrix();
    glEndList();
}



#endif
