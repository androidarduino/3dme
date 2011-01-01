#ifndef NEWCOMPONENT_H
#define NEWCOMPONENT_H

#include <QtGui/QDialog>
#include "q3dsmodel.h"

namespace Ui {
    class NewComponent;
}

class Q3dsModel;

class NewComponent : public QDialog {
    Q_OBJECT
public:
    NewComponent(QWidget *parent, QList<Q3dsModel*>* models, Q3dsModel* newModel);
    ~NewComponent();
    virtual void accept();
protected:
    void changeEvent(QEvent *e);
    Q3dsModel* candidateModel;
    QList<Q3dsModel*>* existingModels;
public:
    Ui::NewComponent *m_ui;
private slots:
    void parentChanged(int index);
    bool validateInput();
    void pointTo(int index);
    void setDir(float x, float y, float z);
};

#endif // NEWCOMPONENT_H
