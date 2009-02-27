#ifndef Q3DSSCENE_H
#define Q3DSSCENE_H

#include "q3dsmodel.h"

class Q3dsScene:public QGLWidget
{
    public:
        Q3dsScene(QWidget* parent=0);
        //loadGeometry(QString fileName);
        //loadSkyBox(QString fileName);
        //setCameraTo(float x, float y, float z);
        //moveCamera(float dx, float dy, float dz);
        //cameraLookAt(float dx, float dy, float dz);
        //cameraZoom(float zoom, float viewAngel);
        QList<Q3dsModel*> models;
    protected:
        void paintGL();
        void initializeGL();
        void resizeGL(int width, int height);
        void mouseMoveEvent(QMouseEvent* event);
        void keyPressEvent(QKeyEvent* event);
        void wheelEvent(QWheelEvent* event);
    private:
        float mx,my,rot_x, rot_z;
};

Q3dsScene::Q3dsScene(QWidget* parent):QGLWidget(parent)
{
    setMouseTracking(true);
    rot_x=rot_z=0;
}

void Q3dsScene::paintGL()
{
    //gluLookAt(0,0,-2000,0,0,0,0,1,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glRotatef(rot_x, 1,0,0);
//    glRotatef(rot_z, 0,0,1);
    foreach(Q3dsModel* model, models)
        model->display();
}

void Q3dsScene::initializeGL()
{
    models.at(0)->initGL();
}

void Q3dsScene::resizeGL(int width, int height)
{
    foreach(Q3dsModel* model, models)
        model->resize(width,height);
    glViewport(0,0,width,height);
}

void Q3dsScene::Q3dsScene::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons()==Qt::LeftButton)
    {
        rot_z += 0.1 * (event->x() - mx);
        rot_x += 0.1 * (event->y() - my);
        update();
    }
    mx = event->x();
    my = event->y();
    foreach(Q3dsModel* model, models)
        model->mouse_move(event);
}

void Q3dsScene::keyPressEvent(QKeyEvent* event)
{
    foreach(Q3dsModel* model, models)
        model->key_press(event);;
    update();
}

void Q3dsScene::wheelEvent(QWheelEvent* event)
{
    foreach(Q3dsModel* model, models)
        model->wheel(event);;
    update();
}

#endif
