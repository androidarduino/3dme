#include "newcomponent.h"
#include "ui_newcomponent.h"

NewComponent::NewComponent(QWidget *parent, QList<Q3dsModel*>* models, Q3dsModel* newModel) :
    QDialog(parent),
    m_ui(new Ui::NewComponent)
{
    m_ui->setupUi(this);
    existingModels=models;
    candidateModel=newModel;
    //TODO:fetch the name, size, direction and axis from newModel
    //to allow modifying them
    //populate in myAxis, axisParent, and change axisConjunction according to axisParent selection
    m_ui->myAxis->insertItems(0,newModel->conjunctions());
    foreach(Q3dsModel* m, *models)
        m_ui->axisParent->insertItem(0,m->name);

    connect(m_ui->axisParent, SIGNAL(currentIndexChanged(int)), this, SLOT(parentChanged(int)));
    connect(m_ui->pointTo, SIGNAL(currentIndexChanged(int)),this,SLOT(pointTo(int)));
}

void NewComponent::accept()
{
    if(!validateInput())
        QMessageBox::warning(this, tr("Please Verify Input Values"),
                             tr("Name must not be duplicate to existing names, <br> Sizes must not be zero."));
    else
        QDialog::accept();
}

void NewComponent::pointTo(int index)
{
    QString dir=m_ui->pointTo->itemText(index);
    //up, down, left, right, front, back
    if(dir=="Up")
        setDir(0,90,0);
    if(dir=="Down")
        setDir(0,-90,0);
    if(dir=="Left")
        setDir(0,0,90);
    if(dir=="Right")
        setDir(0,0,-90);
    if(dir=="Front")
        setDir(0,0,0);
    if(dir=="Back")
        setDir(180,0,0);
}

void NewComponent::setDir(float x, float y, float z)
{
    m_ui->bendX->setText(QString("%1").arg(x));
    m_ui->bendY->setText(QString("%1").arg(y));
    m_ui->bendZ->setText(QString("%1").arg(z));
}

bool NewComponent::validateInput()
{
    //check for the following:
    /*
      1. name is valid, not duplicate
      2. size valid
      */
    QString name=this->m_ui->cname->text();
    if(name=="")
        return false;
    foreach(Q3dsModel* m, *existingModels)
        if(m->name==name)
            return false;
    if(m_ui->sizeX->text().toFloat()==0)
        return false;
    if(m_ui->stretch->checkState()==Qt::Checked)
        if(m_ui->sizeY->text().toFloat()==0||m_ui->sizeZ->text().toFloat()==0)
            return false;
    return true;
}

void NewComponent::parentChanged(int index)
{
    m_ui->axisConjunction->clear();
    foreach(Q3dsModel* model, *existingModels)
        if(model->name==m_ui->axisParent->itemText(index))
            m_ui->axisConjunction->insertItems(0,model->conjunctions());
}

NewComponent::~NewComponent()
{
    delete m_ui;
}

void NewComponent::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
