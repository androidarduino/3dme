/*TODO:
  3. Optimize the rendering function, keep the list for next time rendering to achieve higher performance
  5. There might be undeleted objects, eg. file, this couldn't be resolved unless the model is implemented in the class to replace the use of file
  6. Now the conjunctions works fine. next step would be
  to implement the rotation around the conjunctions
  7. Implement the rotation against particular angel/surface
  8. Write a 3d skeleton animation editor, support rotation, pan
  9. There might be a bunch of work to calculate the interval animation
  10.
*/
#include <QtGui>
#include <QApplication>
#include <QDebug>
#include "q3dsscene.h"

int main(int argc, char** argv)
{
    QApplication app(argc,argv);

    Q3dsScene scene;
    Q3dsModel hair("hair.3ds");
    Q3dsModel head("head.3ds");
    Q3dsModel body("body.3DS");
    Q3dsModel arm("arm.3ds");
    Q3dsModel smallarm("arm.3ds");
    Q3dsModel leg("arm.3ds");
    Q3dsModel shank("arm.3ds");
    Q3dsModel arm1("arm.3ds");
    Q3dsModel smallarm1("arm.3ds");
    Q3dsModel leg1("arm.3ds");
    Q3dsModel shank1("arm.3ds");
    body.scaleTo(50);
    head.scaleTo(40);
    hair.scaleTo(50);
    arm.scaleTo(30);
    smallarm.scaleTo(30);
    leg.scaleTo(30);
    shank.scaleTo(30);
    arm1.scaleTo(30);
    smallarm1.scaleTo(30);
    leg1.scaleTo(30);
    shank1.scaleTo(30);

    head.move(0,0,10);
    hair.move(-2,2,3);
    body.moveTo(0,0,0);

    body.addChildToAxis(&head,"_neck", "_neck");
    body.addChildToAxis(&arm,"_shoulder", "_rightshou");
    body.addChildToAxis(&leg,"_shoulder", "_lefthip");
    body.addChildToAxis(&arm1,"_shoulder", "_leftshoul");
    body.addChildToAxis(&leg1,"_shoulder", "_righthip");
    leg.addChildToAxis(&shank,"_shoulder","_elbow");
    arm.addChildToAxis(&smallarm,"_shoulder","_elbow");
    leg1.addChildToAxis(&shank1,"_shoulder","_elbow");
    arm1.addChildToAxis(&smallarm1,"_shoulder","_elbow");
    head.addChildToAxis(&hair,"_headtop","_headtop");

    head.bend(-30,0,0);
    arm.bend(10,10,0);
    smallarm.bend(60,60,60);
    arm1.bend(0,180,0);
    smallarm1.bend(60,60,60);
    leg.bend(0,-90,0);
    shank.bend(0,0,-30);
    leg1.bend(0,-90,0);
    shank1.bend(0,0,-30);

    scene.models.append(&body);
    scene.resize(600,600);
    scene.show();

    /*
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
    */

    return app.exec();
}
