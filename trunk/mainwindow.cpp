#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newcomponent.h"
#include "ui_newcomponent.h"

//TODO:
//implement modify button
//use a Q3dsAnimation object as the document object, all docs should be
//stored in this object, and saving/loading functions should be moved to
//this class.

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->size, SIGNAL(valueChanged(int)),this, SLOT(resize(int)));
    connect(ui->view, SIGNAL(clicked()),this, SLOT(viewRotate()));
    connect(ui->add, SIGNAL(clicked()),this, SLOT(add()));
    connect(ui->bend, SIGNAL(clicked()),this, SLOT(bend()));
    connect(ui->move, SIGNAL(clicked()),this, SLOT(move()));
    connect(ui->rotate, SIGNAL(clicked()),this, SLOT(rotate()));
    connect(ui->actionConnect, SIGNAL(triggered()),this, SLOT(connectit()));
    connect(ui->actionTop, SIGNAL(triggered()),this, SLOT(top()));
    connect(ui->actionFront, SIGNAL(triggered()),this, SLOT(front()));
    connect(ui->actionLeft, SIGNAL(triggered()),this, SLOT(left()));
    connect(ui->actionRight, SIGNAL(triggered()),this, SLOT(right()));
    connect(ui->action45_Degree, SIGNAL(triggered()),this, SLOT(v45()));
    connect(ui->action135_Degree, SIGNAL(triggered()),this, SLOT(v135()));
    connect(ui->actionSpin_Around, SIGNAL(triggered()),this, SLOT(spin()));
    connect(ui->actionPan, SIGNAL(triggered()),this, SLOT(pan()));
    connect(ui->actionZoom_in, SIGNAL(triggered()),this, SLOT(zoomIn()));
    connect(ui->actionZoom_out, SIGNAL(triggered()),this, SLOT(zoomOut()));
    connect(ui->actionOpen, SIGNAL(triggered()),this, SLOT(open()));
    connect(ui->actionSave, SIGNAL(triggered()),this, SLOT(save()));
    connect(ui->actionExit, SIGNAL(triggered()),this, SLOT(exit()));
    connect(ui->chooser, SIGNAL(currentIndexChanged(int)),this, SLOT(componentChosen(int)));
    connect(ui->modify, SIGNAL(clicked()),this, SLOT(modify()));
    connect(ui->del, SIGNAL(clicked()),this, SLOT(del()));
    connect(ui->color, SIGNAL(clicked()),this, SLOT(color()));
    timer.stop();
    connect(&timer, SIGNAL(timeout()), this, SLOT(timeup()));

    connect(ui->actions, SIGNAL(currentIndexChanged(QString)), this, SLOT(actionSelected(QString)));
    connect(ui->keyframes, SIGNAL(currentTextChanged(QString)), this, SLOT(frameSelected(QString)));
    connect(ui->delay, SIGNAL(valueChanged(double)), this, SLOT(delayChanged(double)));
    connect(ui->curve, SIGNAL(currentIndexChanged(QString)), this, SLOT(curveChanged(QString)));
    connect(ui->addFrame, SIGNAL(clicked()), this, SLOT(addFrame()));
    connect(ui->actionAdd, SIGNAL(triggered()), this, SLOT(addAction()));
    connect(ui->addFrame, SIGNAL(clicked()), this, SLOT(addFrame()));

    scene()->editingMode="View Rotate";
}

MainWindow::~MainWindow()
{
    delete ui;
}

Q3dsScene* MainWindow::scene()
{
    return ui->scene;
}

void MainWindow::updateModels()
{
    disableUI=true;
    QList<Q3dsModel*> list;
    foreach(Q3dsModel* m, scene()->models)
    {
        list<<m;
        list<<m->allChildren();
    }
    ui->chooser->clear();
    chooserModels.clear();
    foreach(Q3dsModel* m, list)
    {
        ui->chooser->addItem(m->name);
        chooserModels.append(m);
    }
    qDebug()<<"no problem here";
    disableUI=false;
    //this->updateInfo();
}

void MainWindow::resize(int newSize)
{
    scene()->selectedComponent->scaleTo(newSize);
    update();
}
void MainWindow::bend()
{
    scene()->editingMode="Bend";
}
void MainWindow::viewRotate()
{
    scene()->editingMode="View Rotate";
}
void MainWindow::move()
{
    scene()->editingMode="Move";
}
void MainWindow::rotate()
{
    scene()->editingMode="Rotate";
}
void MainWindow::connectit()
{

}
void MainWindow::top()
{
    scene()->rot_x=90;
    scene()->rot_y=0;
    scene()->rot_z=0;
    scene()->update();
}
void MainWindow::front()
{
    scene()->rot_x=0;
    scene()->rot_y=0;
    scene()->rot_z=0;
    scene()->update();
}
void MainWindow::left()
{
    scene()->rot_x=0;
    scene()->rot_y=0;
    scene()->rot_z=90;
    scene()->update();
}
void MainWindow::right()
{
    scene()->rot_x=0;
    scene()->rot_y=0;
    scene()->rot_z=270;
    scene()->update();
}
void MainWindow::v45()
{
    scene()->rot_x=0;
    scene()->rot_y=0;
    scene()->rot_z=45;
    scene()->update();
}
void MainWindow::v135()
{
    scene()->rot_x=0;
    scene()->rot_y=0;
    scene()->rot_z=135;
    scene()->update();
}
void MainWindow::spin()
{
    target_z=(int)scene()->rot_z;
    timer.setInterval(20);
    timer.start();
}
void MainWindow::pan()
{
    scene()->editingMode="View Pan";
    ui->view->setChecked(true);
}
void MainWindow::zoomIn()
{
    scene()->zoom*=1.2;
    scene()->update();
}
void MainWindow::zoomOut()
{
    scene()->zoom/=1.2;
    scene()->update();
}
void MainWindow::timeup()
{
    scene()->update();
    scene()->rot_z+=6;
    if(scene()->rot_z>=360+target_z)
    {
        scene()->rot_z=target_z;
        timer.stop();
    }
}
void MainWindow::open()
{
    //open a file and parse the models to a set of q3dsmodel
    QString fn=QFileDialog::getOpenFileName();
    QDomDocument doc;
    QFile file(fn);
    if (!file.open(QIODevice::ReadOnly))
        return;
    doc.setContent(&file);
    file.close();
    scene()->models.clear();
    //TODO: delete the old models
    QDomNodeList nodes=doc.childNodes();
    for(int i=0;i<nodes.count();i++)
    {
        QDomElement e=nodes.at(i).toElement();
        Q3dsModel* m=new Q3dsModel();
        m->fromXml(e, NULL);
        scene()->models<<m;
    }
    qDebug()<<"Model rebuilding finished......";
    updateModels();
}
void MainWindow::save()
{
    //convert the model tree to a xml file and save
    QDomDocument doc;
    foreach(Q3dsModel* m, scene()->models)
        doc.appendChild(m->toXml(&doc));
    QString fn=QFileDialog::getSaveFileName();
    QFile data(fn);
    if (data.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream out(&data);
        out<<doc;
    }
    data.close();
}
void MainWindow::exit()
{
    //check for dirty files and prompt saving
}
void MainWindow::componentChosen(int index)
{
    if(disableUI)
        return;
    foreach(Q3dsModel* m, chooserModels)
    {
        m->highlighted=false;
        m->reload();
    }
    qDebug()<<index;
    if(chooserModels.count()>index)
    {
        chooserModels.at(index)->highlighted=true;
        chooserModels.at(index)->reload();
        scene()->selectedComponent=chooserModels.at(index);
    }
    updateInfo();
}
void MainWindow::updateInfo()
{
    //fill in size, color, axis
    //update info
    ui->size->setValue(scene()->selectedComponent->modelSize);
    QString info;
    info="<b>Axis:</b> "+scene()->selectedComponent->axis();
    info+="<br><b>Color:</b>"+scene()->selectedComponent->defaultColor.name();
    info+="<br><b>Conjunctions:</b><br>";
    info+=scene()->selectedComponent->conjunctions().join("<br>");
    ui->info->setText(info);
    scene()->update();
}
void MainWindow::add()
{
    //open file
    QString fn=QFileDialog::getOpenFileName(this, "Select a component to import", "*.3ds");
    if(fn=="")
        return;
    Q3dsModel* model=new Q3dsModel(fn);
    NewComponent nc(this, &chooserModels, model);;
    int r=nc.exec();
    if(r==QDialog::Rejected)
    {
        delete model;
        return;
    }
    //ask for name
    model->name=nc.m_ui->cname->text();
    //ask for size
    model->scaleTo(nc.m_ui->sizeX->text().toFloat());//TODO: need to add stretch
    //ask for direction
    model->bend(nc.m_ui->bendX->text().toFloat(),
                nc.m_ui->bendY->text().toFloat(),
                nc.m_ui->bendZ->text().toFloat());
    //ask for axis
    //1. search and find parent pointer
    QString parentName = nc.m_ui->axisParent->currentText();
    Q3dsModel* parentPointer=0;
    foreach(Q3dsModel* m, chooserModels)
        if(m->name==parentName)
            parentPointer=m;
    qDebug()<<parentName<<parentPointer;
    //2. add
    QString myAxis=nc.m_ui->myAxis->currentText();
    QString axisConjunction=nc.m_ui->axisConjunction->currentText();
    parentPointer->addChildToAxis(model,myAxis,axisConjunction);
    this->updateModels();
}
void MainWindow::del()
{
    //confirm that this and its children will be all deleted
    if(QMessageBox::question(this, tr("Confirm Deleting"),
                         tr("This will delete this component and all component connected to it, do you want to continue?"),
                         QMessageBox::Yes | QMessageBox::No, QMessageBox::No)!=QMessageBox::Yes)
        return;
    //find the object and remove it from its parent's children list
    QString modelName=this->ui->chooser->currentText();
    Q3dsModel* p=0;
    foreach(Q3dsModel* m, chooserModels)
        if(m->name==modelName)
            p=m;
    Q3dsModel* pFather=p->father;
    pFather->removeChild(p);
    //delete p; TODO: delete its children
    this->updateModels();
}
void MainWindow::modify()
{
    //create a newcomponent dialog
    //fill the dialog with current selected component's properties
    //when accepted, retrive the properties and assign them to the component
}
void MainWindow::color()
{
    QColor color=scene()->selectedComponent->defaultColor;
    color=QColorDialog::getColor(color,this);
    if(color.isValid())
        scene()->selectedComponent->defaultColor=color;
    updateInfo();
}
void MainWindow::axis()
{
    //ask for axis, if nothing is assigned, float it as root
}

void MainWindow::actionSelected(QString actionName)
{
  //on action selected, load all key frames associated with the action
  //and select the first frame

}
void MainWindow::frameSelected(QString frameName)
{
  //on frame selected, display the frame

}
void MainWindow::delaySelected(double delaySecond)
{
  //on delay changed, change key frame properties

}
void MainWindow::curveSelected(QString curveName)
{
  //on curve changed, change key frame properties

}
void MainWindow::addFrame()
{
  //on adding new frame, insert into the frame list, select the new frame

}
void MainWindow::addAction()
{
  //on adding new action, insert into the action list, select the new action
  /*QString actionName=QInputDialog::getText();
  if(actionName=="")
      return;
  ui->actions->addItem(actionName);
  ui->actions->setCurrentIndex(ui->actions->count());
  //TODO: the document should be updated as well
  */
}
