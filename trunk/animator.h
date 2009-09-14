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

class Vector//һ����ά���������ṩ�ǶȺ�λ�����ֱ�﷽ʽ
{
    public:
        double ax,ay,az,dx,dy,dz,length;
};

class Node//һ�����֣���С�ȣ���������ת�ƶ�
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

class Pose//һ�����ƣ������еĹؽڽǶȺ͸��ڵ��λ�þ���
{
    public:
        QMap<Node*, Vector> angles;
        double time;//ͬʱ�洢�˵���һ��������ʱ��
        void * curve;//���ж���������ߣ���ʵ�ϲ����������Ƶ��߼����룬ֻ��Ϊ�˷���ϳ�
};

class Animation//һϵ���������һ���������ڴ˼����м��������������
{
    public:
        QList<Pose*> cartoons;
};

class Model//ģ�ͣ�������һϵ�ж���������
{
    public:
        Model();
        QList<Node*> nodes;
        void doAnimation();
        void loadModel(QString fileName);
        void loadAnimation(QString fileName);
};

#endif // ANIMATOR_H
