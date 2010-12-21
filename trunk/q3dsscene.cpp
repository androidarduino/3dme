#include "q3dsscene.h"

Q3dsScene::Q3dsScene(QWidget* parent):QGLWidget(parent)
{
    setMouseTracking(true);
    rot_x=45;
    rot_y=0;
    rot_z=0;
    zoom=1.0;
    pan_x=pan_y=0;
    editingMode="View Rotate";
    selectedComponent=NULL;
}

void Q3dsScene::paintGL()
{
    //gluLookAt(0,0,-2000,0,0,0,0,1,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //adjust to see the models
    glTranslated(pan_x,pan_y,-300);
    glRotatef(-90,1,0,0);
    //end adjust
    glRotatef(rot_x, 1,0,0);
    glRotatef(rot_y, 0,1,0);
    glRotatef(rot_z, 0,0,1);
    glScalef(zoom,zoom,zoom);
    foreach(Q3dsModel* model, models)
        model->display(true);
}

void Q3dsScene::initializeGL()
{
    models.at(0)->initGL();
}

void Q3dsScene::resizeGL(int width, int height)
{
//    foreach(Q3dsModel* model, models)
//        model->resize(width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1.0*width/height,0.1,1000);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,width,height);
}

void Q3dsScene::Q3dsScene::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons()==Qt::LeftButton)
    {
        float r1=0.1 * (event->x() - mx);
        float r2=0.1 * (event->y() - my);
        if(editingMode=="View Pan")
        {
            pan_x+=10*r1;
            pan_y-=10*r2;
        }
        if(editingMode=="View Rotate")
        {
            rot_z += r1;
            rot_x += r2;
        }
        if(editingMode=="Bend"&&selectedComponent!=NULL)
        {
            selectedComponent->bend(0,r1,r2);
        }
        if(editingMode=="Move"&&selectedComponent!=NULL)
        {
            selectedComponent->move(0,-r1*2,-r2*2);
        }
        if(editingMode=="Rotate"&&selectedComponent!=NULL)
        {

        }
        update();
    }
    mx = event->x();
    my = event->y();
}

void Q3dsScene::mouseReleaseEvent(QMouseEvent*)
{
    if(editingMode=="View Pan")
        editingMode="View Rotate";
}

void Q3dsScene::keyPressEvent(QKeyEvent* event)
{
    foreach(Q3dsModel* model, models)
        model->key_press(event);;
    update();
}

void Q3dsScene::wheelEvent(QWheelEvent* event)
{
    float r=event->delta()*0.1;
    if(editingMode=="View Pan")
    {
    }
    if(editingMode=="View Rotate")
    {
    }
    if(editingMode=="Bend"&&selectedComponent!=NULL)
    {
        selectedComponent->bend(r,0,0);
    }
    if(editingMode=="Move"&&selectedComponent!=NULL)
    {
        selectedComponent->move(r,0,0);
    }
    if(editingMode=="Rotate"&&selectedComponent!=NULL)
    {
    }
    update();
}


