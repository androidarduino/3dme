#ifndef ANIMATOR_H
#define ANIMATOR_H
#include <QList>
#include <QMap>
#include <QString>
#include <QDebug>
#include <lib3ds/file.h>
#include <lib3ds/camera.h>
#include <lib3ds/mesh.h>
#include <lib3ds/node.h>
#include <lib3ds/material.h>
#include <lib3ds/matrix.h>
#include <lib3ds/vector.h>
#include <lib3ds/light.h>

class Vector//一个三维向量，可提供角度和位移两种表达方式
{
    public:
        double ax,ay,az,dx,dy,dz,length;
};

class Node//一个部分，如小腿，可绕轴旋转移动
{
    public:
        QString name;
        double width, height, depth;
        double x,y,z;
        double cx,cy,cz;
        QList<GLuint> displayLists;
        Vector* axis;
        QList<Vector*> conjunctions;
        void rotate(const Vector& v);
};

class Pose//一个姿势，由所有的关节角度和根节点的位置决定
{
    public:
        QMap<Node*, Vector> angles;
        double time;//同时存储了到下一个动作的时间
        void * curve;//还有动作完成曲线，事实上并不属于姿势的逻辑范畴，只是为了方便合成
};

class Animation//一系列姿势组成一个动画，在此计算中间的所有姿势坐标
{
    public:
        QList<Pose*> cartoons;
};

class Model//模型，可以做一系列动画和姿势
{
    public:
        Model();
        QList<Node*> nodes;
        void doAnimation();
        void loadModel(QString fileName);
        void loadAnimation(QString fileName);
};

#endif // ANIMATOR_H
