#ifndef FRAME_H
#define FRAME_H
#include <QString>
#include <QList>
#include <QColor>
#include <QMap>
#include "q3dsmodel.h"

class Q3dAnimation
{
private:

class Change
{
public:
    Change(Q3dsModel* m){setModel(m);}
    void setModel(Q3dsModel* m){model=m;}
    Q3dsModel* model;
    //We can animate the following properties,
    //variables indicate changes:
    Q3dsPoint scale, move, rotate, bend;
    QString replaceColorName;
    QColor replaceColor;
    QString replaceTextureName, textureFileName;
    float transparency;
};

class Frame
{
public:
    int id;
    static long frameIdCount;
    QList<Change*> changes;
};

class Step
{
public:
    enum CurveTypes{Flat, Drop, Rise, Hill};//may need more types
    Step(){}
    Frame* frame;
    float span;
    CurveTypes curve;
};

class Action
{
public:
    Action(){}
    QString name;
    QList<Step*> steps;
};

public:
    Q3dAnimation();
    ~Q3dAnimation();
    QString save();//save to xml
    void load(QString xml);//load from xml
    void doAction(QString actionName);//do an action
    void addAction(QString actionName);//add an action
    int addFrame(long fromFrameId=0);//returns frame id, if para!=0, copy it
    void makeChange(long frameId, Q3dsModel* model, QString propertyName, QString newValue);
private:
    QList<Frame*> frames;
    QList<Action*> actions;
    QMap<QString, QString> meta;
    QList<Q3dsModel*> models;
};

#endif // FRAME_H
