/*TODO:
  3. Optimize the rendering function, keep the list for next time rendering to achieve higher performance
  5. There might be undeleted objects, eg. file
*/
#include <QtGui>
#include <QApplication>
#include <QDebug>
#include "q3dsscene.h"
#include "animator.h"

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
/*    Q3dsModel monkey("monkey.3ds");
    Q3dsModel skates("skates.3ds");
    Q3dsModel skates2("skates.3ds");
    Q3dsModel skates3("skates.3ds");
    Q3dsModel venus("venus.3ds");
    Q3dsModel venus2("venus.3ds");
    Q3dsModel venus3("venus.3ds");
    Q3dsModel teapot("teapot.3ds");
    Q3dsScene scene;
    scene.models.append(&monkey);
    scene.models.append(&skates);
    scene.models.append(&skates2);
    scene.models.append(&skates3);
    scene.models.append(&venus);
    scene.models.append(&venus2);
    scene.models.append(&venus3);
    scene.models.append(&teapot);
    venus2.rotate(30,0,0);
    venus2.scale(0.5,0.5,0.5);
    venus2.moveTo(0,200,400);
    venus3.scale(0.25,0.25,0.25);
    venus3.moveTo(0,200,800);
    venus2.rotate(60,0,0);
    skates2.scaleTo(200);
    skates2.rotate(90,0,0);
    skates2.moveTo(0,200,400);
    skates3.scaleTo(100);
    teapot.scaleTo(400);
    teapot.moveTo(200,200,200);
//    skates2.moveTo(0,200,400);
//    skates3.moveTo(0,200,400);
    scene.show();*/
/*
    Q3dsScene scene;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    for(int k=0;k<3;k++)
    {
        Q3dsModel* m=new Q3dsModel("xiao.3ds");
        m->scaleTo(150);
        m->moveTo(i*400,j*400,k*400);
        scene.models.append(m);
    }
    scene.show();
*/
    Q3dsModel head("head.3ds");
    Q3dsModel hair;
    Q3dsModel body("body.3DS");
    hair.replaceColor("Material #2", QColor::fromRgbF(0,1,0,0.8));
    hair.loadModel("hair.3ds");
    Q3dsScene scene;
    scene.models.append(&head);
    scene.models.append(&hair);
    scene.models.append(&body);
    head.scaleTo(800);
    hair.scaleTo(1000);
    hair.moveTo(-50,0,100);
    body.scaleTo(1000);
    body.moveTo(0,0,-800);
    scene.show();
    scene.resize(600,600);
    /*
    Q3dsModel model("head.3ds");
    Q3dsModel m1("hair.3ds");
    Q3dsScene scene;
    scene.models.append(&model);
    scene.models.append(&m1);
    scene.show();
    */
    /*
    //should be something like this:
    Q3dsModel head("head.3ds");
    Q3dsModel hair("hair.3ds");
    hair.connect(&head, "top");
    Q3dsModel body("body.3ds");
    head.connect(&body,"neck");
    Q3dsModel leftArm("arm.3ds");
    leftArm.connect(&body,"leftShoulder");
    Q3dsModel rightArm("arm.3ds");
    rightArm.mirror();
    leftArm.connect(&body,"rightShoulder");
    //.......do for every part
    */
    return app.exec();
}
