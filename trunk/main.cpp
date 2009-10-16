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

    Q3dsModel head("head.3ds");
    Q3dsScene scene;
    Q3dsModel body("body.3DS");
    head.scaleTo(40);
    head.move(0,0,10);
    body.scaleTo(50);
    body.moveTo(0,0,0);
    body.addChildToAxis(&head,"_neck");
    scene.models.append(&body);
    //scene.models.append(&body);
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
