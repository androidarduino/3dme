#ifndef Q3DSSCENE_H
#define Q3DSSCENE_H

#include "q3dsmodel.h"

/*
  TODO:
        1. Q3dsScene to support cameras
        2. Q3dsScene rotate around an axis
  */

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
        Q3dsModel* selectedComponent;
    protected:
        void paintGL();
        void initializeGL();
        void resizeGL(int width, int height);
        void mouseMoveEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void keyPressEvent(QKeyEvent* event);
        void wheelEvent(QWheelEvent* event);
    private:
        float mx,my;
    public:
        float rot_x, rot_y, rot_z, pan_x, pan_y;
        float zoom;
        QString editingMode;
};


#endif
