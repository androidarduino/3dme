#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QMap>
#include <QTimer>
#include "q3dsscene.h"

/*
  1. on action selected, load all key frames associated with the action
  and select the first frame
  2. on frame selected, display the frame
  3. on delay/curve changed, change key frame properties
  4. on adding new frame, insert into the frame list, select the new frame
  5. on adding new action, insert into the action list, select the new action
  6. on selecting animal editing mode, disable action editing panel, enable all other editing optinos
  7. on selecting action editing mode, disable the following:
  axis editing in property page; model import; model rename; model deletion
  8. when saving, save all the actions
  9. when loading, load all the actions
  */

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Q3dsScene* scene();
    void updateModels();

private:
    Ui::MainWindow *ui;
private slots:
    void resize(int newSize);
    void add();
    void bend();
    void move();
    void rotate();
    void viewRotate();
    void connectit();
    void top();
    void front();
    void left();
    void right();
    void v45();
    void v135();
    void spin();
    void pan();
    void zoomIn();
    void zoomOut();
    void open();
    void save();
    void exit();
    void del();
    void modify();
    void color();
    void axis();
    void componentChosen(int index);

    void timeup();

    void actionSelected(QString actionName);
    void frameSelected(QString frameName);
    void delaySelected(double delaySecond);
    void curveSelected(QString curveName);
    void addFrame();
    void addAction();
private:
    QMap<QString, Q3dsModel*> models;
    QTimer timer;
    int target_z;
    QList<Q3dsModel*> chooserModels;
    void updateInfo();
    bool disableUI;
};

#endif // MAINWINDOW_H
