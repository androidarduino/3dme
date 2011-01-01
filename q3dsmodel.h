#ifndef Q3DSMODEL_H
#define Q3DSMODEL_H

#include <lib3ds/file.h>
#include <lib3ds/camera.h>
#include <lib3ds/mesh.h>
#include <lib3ds/node.h>
#include <lib3ds/material.h>
#include <lib3ds/matrix.h>
#include <lib3ds/vector.h>
#include <lib3ds/light.h>
#include <QGLWidget>
#include <QDebug>
#include <QtGui>
#include <QDomDocument>
#include <QDomNode>
#include <QDomElement>

class Player_texture
{
    public:
        int valid;
        void *bitmap;
        GLuint tex_id;
        float scale_x, scale_y;
};

class Q3dsPoint
{
    public:
        float x,y,z;
        Q3dsPoint(){x=y=z=0;}
        void setPos(float* p){
            x=p[0];y=p[1];z=p[2];
        }
};

class Q3dsModel:public QGLWidget
{
    public:
        Q3dsModel(QString modelFile="", QString pName="", QWidget* parent=0);
        void resize(int w, int h);
        void scale(float x, float y, float z);
        void scaleTo(float x);
        void move(float x, float y, float z);
        void moveTo(float x, float y, float z);
        void rotate(float x, float y, float z);
        void rotateTo(float x, float y, float z);
        void display(bool externCall=true);
        void wheel(QWheelEvent* event);
        void key_press(QKeyEvent* event);
        void mouse_move(QMouseEvent* event);
        void replaceColor(QString colorName, QColor color);
        void loadModel(QString fileName);
        void initGL();
        Q3dsPoint& conjunction(QString name);
        void addChildToAxis(Q3dsModel* child, QString axis, QString conjunction);
        void removeChild(Q3dsModel* child);
        void bend(float x, float y, float z);//bend against axis
        QList<Q3dsModel*> allChildren();
        QString name;
        QColor defaultColor;
        Q3dsModel* father;
        bool highlighted;
        void reload();
        float modelSize;
        QString axis();
        QStringList conjunctions();
        QDomElement toXml(QDomDocument* doc);
        void fromXml(QDomElement e, Q3dsModel* p);
    protected:
        void paintGL();
        void initializeGL();
        void resizeGL(int width, int height);
        void mouseMoveEvent(QMouseEvent* event);
        void keyPressEvent(QKeyEvent* event);
        void wheelEvent(QWheelEvent* event);
        virtual void retrieveTexture(QImage& picture, QString fileName);
    private:
        void draw_light(const GLfloat *pos, const GLfloat *color);
        void draw_bounds(Lib3dsVector tgt);
        void light_update(Lib3dsLight *l);
        void render_node(Lib3dsNode *node, bool dryRun=false);
    private:
        int TEX_XSIZE, TEX_YSIZE;
        QString datapath,objName;
        QString currentCamera;
        Lib3dsFile *file;
        bool iflush;
        bool anti_alias;
        int gl_width, gl_height;
        bool show_object, show_bounds, show_cameras, show_lights;
        Lib3dsVector bmin, bmax;
        float	sx, sy, sz, isize;
        float	cx, cy, cz;
        float xRotate,yRotate,zRotate,xOffset,yOffset,zOffset,xScale,yScale,zScale;
        float xBend,yBend,zBend;
        float	view_rotx , view_roty , view_rotz ;
        float	anim_rotz ;
        int	mx, my;
        float zoom;
        QString modelFile;
        QMap<QString, QColor> colorMap;
        QList<Q3dsModel*> children;
        Q3dsPoint _axis;
        bool reGenerate;
        QString axisConjunction, axisPoint;
        QMap<QString, Q3dsPoint> _conjunctions;//conjunctions pool

};

#endif
