#include "animator.h"

Model::Model()
{

}

void Model::loadModel(QString fileName)
{
    Lib3dsFile *file=lib3ds_file_load(fileName.toAscii().constData());
    qDebug()<<file->nodes;
    qDebug()<<"running";
}
