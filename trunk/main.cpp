/*TODO:
  3. Optimize the rendering function, keep the list for next time rendering to achieve higher performance
  5. There might be undeleted objects, eg. file
*/
#include <QtGui>
#include <QApplication>
#include <QDebug>
#include "q3dsscene.h"

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
    Q3dsScene scene;
    scene.models.append(&monkey);
    scene.models.append(&skates);
    scene.models.append(&skates2);
    scene.models.append(&skates3);
    scene.models.append(&venus);
    scene.models.append(&venus2);
    scene.models.append(&venus3);
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
//    skates2.moveTo(0,200,400);
//    skates3.moveTo(0,200,400);
    scene.show();
*/
    Q3dsModel head("head.3ds");
    Q3dsModel hair("hair.3ds");
    Q3dsScene scene;
    scene.models.append(&head);
    scene.models.append(&hair);
    head.scaleTo(800);
    hair.scaleTo(800);
    scene.show();
    scene.resize(600,600);
    return app.exec();
}
