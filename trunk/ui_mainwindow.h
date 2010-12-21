/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sat Jan 16 19:46:05 2010
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDial>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "q3dsscene.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImport;
    QAction *actionMove;
    QAction *actionResize;
    QAction *actionRename;
    QAction *actionRotate;
    QAction *actionBend;
    QAction *actionConnect;
    QAction *actionPan;
    QAction *actionSpin_Around;
    QAction *actionZoom_in;
    QAction *actionZoom_out;
    QAction *actionTop;
    QAction *actionFront;
    QAction *actionLeft;
    QAction *actionRight;
    QAction *action45_Degree;
    QAction *action135_Degree;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionAdd;
    QAction *actionRemove;
    QAction *actionAdd_2;
    QAction *actionRemove_2;
    QAction *actionAdd_Frame;
    QAction *actionRemove_Frame;
    QAction *actionAnimal_Editing_Mode;
    QAction *actionAction_Editing_Mode;
    QAction *actionDoll_sitemap;
    QAction *actionNew_from_Current;
    QAction *actionNew_from_Frame_0;
    QAction *actionDelete;
    QAction *actionPreview;
    QAction *actionAbout;
    QAction *actionHow_to;
    QAction *actionOnline_manual;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *animalEditor;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *chooser;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *add;
    QToolButton *del;
    QToolButton *modify;
    QFrame *line;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *size;
    QPushButton *pushButton;
    QPushButton *color;
    QFrame *line_2;
    QRadioButton *view;
    QRadioButton *bend;
    QRadioButton *move;
    QRadioButton *rotate;
    QRadioButton *scale;
    QFrame *line_3;
    QLabel *info;
    QSpacerItem *verticalSpacer;
    Q3dsScene *scene;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QListWidget *listWidget;
    QFrame *actionEditor;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QComboBox *actions;
    QListWidget *keyframes;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *addFrame;
    QToolButton *removeFrame;
    QToolButton *moveStepUp;
    QToolButton *moveStepDown;
    QDoubleSpinBox *delay;
    QComboBox *curve;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *actionPreviewForward;
    QDial *actionPreviewSpeed;
    QToolButton *actionPreviewBack;
    QMenuBar *menuBar;
    QMenu *menuModel;
    QMenu *menuView;
    QMenu *menuFile;
    QMenu *menuAction;
    QMenu *menuFrame;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(647, 471);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QString::fromUtf8("actionImport"));
        actionMove = new QAction(MainWindow);
        actionMove->setObjectName(QString::fromUtf8("actionMove"));
        actionResize = new QAction(MainWindow);
        actionResize->setObjectName(QString::fromUtf8("actionResize"));
        actionRename = new QAction(MainWindow);
        actionRename->setObjectName(QString::fromUtf8("actionRename"));
        actionRotate = new QAction(MainWindow);
        actionRotate->setObjectName(QString::fromUtf8("actionRotate"));
        actionBend = new QAction(MainWindow);
        actionBend->setObjectName(QString::fromUtf8("actionBend"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionPan = new QAction(MainWindow);
        actionPan->setObjectName(QString::fromUtf8("actionPan"));
        actionSpin_Around = new QAction(MainWindow);
        actionSpin_Around->setObjectName(QString::fromUtf8("actionSpin_Around"));
        actionZoom_in = new QAction(MainWindow);
        actionZoom_in->setObjectName(QString::fromUtf8("actionZoom_in"));
        actionZoom_out = new QAction(MainWindow);
        actionZoom_out->setObjectName(QString::fromUtf8("actionZoom_out"));
        actionTop = new QAction(MainWindow);
        actionTop->setObjectName(QString::fromUtf8("actionTop"));
        actionFront = new QAction(MainWindow);
        actionFront->setObjectName(QString::fromUtf8("actionFront"));
        actionLeft = new QAction(MainWindow);
        actionLeft->setObjectName(QString::fromUtf8("actionLeft"));
        actionRight = new QAction(MainWindow);
        actionRight->setObjectName(QString::fromUtf8("actionRight"));
        action45_Degree = new QAction(MainWindow);
        action45_Degree->setObjectName(QString::fromUtf8("action45_Degree"));
        action135_Degree = new QAction(MainWindow);
        action135_Degree->setObjectName(QString::fromUtf8("action135_Degree"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QString::fromUtf8("actionAdd"));
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName(QString::fromUtf8("actionRemove"));
        actionAdd_2 = new QAction(MainWindow);
        actionAdd_2->setObjectName(QString::fromUtf8("actionAdd_2"));
        actionRemove_2 = new QAction(MainWindow);
        actionRemove_2->setObjectName(QString::fromUtf8("actionRemove_2"));
        actionAdd_Frame = new QAction(MainWindow);
        actionAdd_Frame->setObjectName(QString::fromUtf8("actionAdd_Frame"));
        actionRemove_Frame = new QAction(MainWindow);
        actionRemove_Frame->setObjectName(QString::fromUtf8("actionRemove_Frame"));
        actionAnimal_Editing_Mode = new QAction(MainWindow);
        actionAnimal_Editing_Mode->setObjectName(QString::fromUtf8("actionAnimal_Editing_Mode"));
        actionAction_Editing_Mode = new QAction(MainWindow);
        actionAction_Editing_Mode->setObjectName(QString::fromUtf8("actionAction_Editing_Mode"));
        actionDoll_sitemap = new QAction(MainWindow);
        actionDoll_sitemap->setObjectName(QString::fromUtf8("actionDoll_sitemap"));
        actionNew_from_Current = new QAction(MainWindow);
        actionNew_from_Current->setObjectName(QString::fromUtf8("actionNew_from_Current"));
        actionNew_from_Frame_0 = new QAction(MainWindow);
        actionNew_from_Frame_0->setObjectName(QString::fromUtf8("actionNew_from_Frame_0"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionPreview = new QAction(MainWindow);
        actionPreview->setObjectName(QString::fromUtf8("actionPreview"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionHow_to = new QAction(MainWindow);
        actionHow_to->setObjectName(QString::fromUtf8("actionHow_to"));
        actionOnline_manual = new QAction(MainWindow);
        actionOnline_manual->setObjectName(QString::fromUtf8("actionOnline_manual"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        animalEditor = new QFrame(centralWidget);
        animalEditor->setObjectName(QString::fromUtf8("animalEditor"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(animalEditor->sizePolicy().hasHeightForWidth());
        animalEditor->setSizePolicy(sizePolicy1);
        animalEditor->setFrameShape(QFrame::StyledPanel);
        animalEditor->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(animalEditor);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(animalEditor);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        chooser = new QComboBox(animalEditor);
        chooser->setObjectName(QString::fromUtf8("chooser"));
        chooser->setEditable(false);

        verticalLayout->addWidget(chooser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        add = new QToolButton(animalEditor);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout_2->addWidget(add);

        del = new QToolButton(animalEditor);
        del->setObjectName(QString::fromUtf8("del"));

        horizontalLayout_2->addWidget(del);

        modify = new QToolButton(animalEditor);
        modify->setObjectName(QString::fromUtf8("modify"));

        horizontalLayout_2->addWidget(modify);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(animalEditor);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_2 = new QLabel(animalEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        size = new QDoubleSpinBox(animalEditor);
        size->setObjectName(QString::fromUtf8("size"));
        size->setMaximum(1e+08);

        horizontalLayout_3->addWidget(size);


        verticalLayout->addLayout(horizontalLayout_3);

        pushButton = new QPushButton(animalEditor);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        color = new QPushButton(animalEditor);
        color->setObjectName(QString::fromUtf8("color"));

        verticalLayout->addWidget(color);

        line_2 = new QFrame(animalEditor);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        view = new QRadioButton(animalEditor);
        view->setObjectName(QString::fromUtf8("view"));
        view->setChecked(true);

        verticalLayout->addWidget(view);

        bend = new QRadioButton(animalEditor);
        bend->setObjectName(QString::fromUtf8("bend"));

        verticalLayout->addWidget(bend);

        move = new QRadioButton(animalEditor);
        move->setObjectName(QString::fromUtf8("move"));

        verticalLayout->addWidget(move);

        rotate = new QRadioButton(animalEditor);
        rotate->setObjectName(QString::fromUtf8("rotate"));

        verticalLayout->addWidget(rotate);

        scale = new QRadioButton(animalEditor);
        scale->setObjectName(QString::fromUtf8("scale"));

        verticalLayout->addWidget(scale);

        line_3 = new QFrame(animalEditor);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        info = new QLabel(animalEditor);
        info->setObjectName(QString::fromUtf8("info"));

        verticalLayout->addWidget(info);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(animalEditor);

        scene = new Q3dsScene(centralWidget);
        scene->setObjectName(QString::fromUtf8("scene"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scene->sizePolicy().hasHeightForWidth());
        scene->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(scene);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setMargin(11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_3->addWidget(listWidget);


        horizontalLayout->addWidget(frame);

        actionEditor = new QFrame(centralWidget);
        actionEditor->setObjectName(QString::fromUtf8("actionEditor"));
        actionEditor->setEnabled(true);
        sizePolicy1.setHeightForWidth(actionEditor->sizePolicy().hasHeightForWidth());
        actionEditor->setSizePolicy(sizePolicy1);
        actionEditor->setFrameShape(QFrame::StyledPanel);
        actionEditor->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(actionEditor);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setMargin(11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(actionEditor);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        actions = new QComboBox(actionEditor);
        actions->setObjectName(QString::fromUtf8("actions"));

        verticalLayout_2->addWidget(actions);

        keyframes = new QListWidget(actionEditor);
        keyframes->setObjectName(QString::fromUtf8("keyframes"));

        verticalLayout_2->addWidget(keyframes);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        addFrame = new QToolButton(actionEditor);
        addFrame->setObjectName(QString::fromUtf8("addFrame"));

        horizontalLayout_5->addWidget(addFrame);

        removeFrame = new QToolButton(actionEditor);
        removeFrame->setObjectName(QString::fromUtf8("removeFrame"));

        horizontalLayout_5->addWidget(removeFrame);

        moveStepUp = new QToolButton(actionEditor);
        moveStepUp->setObjectName(QString::fromUtf8("moveStepUp"));

        horizontalLayout_5->addWidget(moveStepUp);

        moveStepDown = new QToolButton(actionEditor);
        moveStepDown->setObjectName(QString::fromUtf8("moveStepDown"));

        horizontalLayout_5->addWidget(moveStepDown);


        verticalLayout_2->addLayout(horizontalLayout_5);

        delay = new QDoubleSpinBox(actionEditor);
        delay->setObjectName(QString::fromUtf8("delay"));
        delay->setFocusPolicy(Qt::WheelFocus);
        delay->setMaximum(999.99);
        delay->setValue(1);

        verticalLayout_2->addWidget(delay);

        curve = new QComboBox(actionEditor);
        curve->setObjectName(QString::fromUtf8("curve"));

        verticalLayout_2->addWidget(curve);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        actionPreviewForward = new QToolButton(actionEditor);
        actionPreviewForward->setObjectName(QString::fromUtf8("actionPreviewForward"));

        horizontalLayout_4->addWidget(actionPreviewForward);

        actionPreviewSpeed = new QDial(actionEditor);
        actionPreviewSpeed->setObjectName(QString::fromUtf8("actionPreviewSpeed"));

        horizontalLayout_4->addWidget(actionPreviewSpeed);

        actionPreviewBack = new QToolButton(actionEditor);
        actionPreviewBack->setObjectName(QString::fromUtf8("actionPreviewBack"));

        horizontalLayout_4->addWidget(actionPreviewBack);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout->addWidget(actionEditor);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 647, 25));
        menuModel = new QMenu(menuBar);
        menuModel->setObjectName(QString::fromUtf8("menuModel"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAction = new QMenu(menuBar);
        menuAction->setObjectName(QString::fromUtf8("menuAction"));
        menuFrame = new QMenu(menuBar);
        menuFrame->setObjectName(QString::fromUtf8("menuFrame"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setAllowedAreas(Qt::AllToolBarAreas);
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuModel->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuFrame->menuAction());
        menuBar->addAction(menuAction->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuModel->addAction(actionImport);
        menuModel->addSeparator();
        menuModel->addAction(actionRename);
        menuModel->addAction(actionResize);
        menuModel->addAction(actionRotate);
        menuModel->addAction(actionMove);
        menuModel->addAction(actionBend);
        menuView->addAction(actionPan);
        menuView->addAction(actionSpin_Around);
        menuView->addAction(actionZoom_in);
        menuView->addAction(actionZoom_out);
        menuView->addSeparator();
        menuView->addAction(actionTop);
        menuView->addAction(actionFront);
        menuView->addAction(actionLeft);
        menuView->addAction(actionRight);
        menuView->addAction(action45_Degree);
        menuView->addAction(action135_Degree);
        menuView->addSeparator();
        menuView->addAction(actionDoll_sitemap);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuAction->addAction(actionAdd);
        menuAction->addAction(actionRemove);
        menuAction->addSeparator();
        menuAction->addAction(actionAdd_Frame);
        menuAction->addAction(actionRemove_Frame);
        menuAction->addSeparator();
        menuAction->addAction(actionPreview);
        menuFrame->addAction(actionNew_from_Current);
        menuFrame->addAction(actionNew_from_Frame_0);
        menuFrame->addAction(actionDelete);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionHow_to);
        menuHelp->addAction(actionOnline_manual);
        mainToolBar->addAction(actionTop);
        mainToolBar->addAction(actionFront);
        mainToolBar->addAction(actionLeft);
        mainToolBar->addAction(actionRight);
        mainToolBar->addAction(action45_Degree);
        mainToolBar->addAction(action135_Degree);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSpin_Around);
        mainToolBar->addAction(actionPan);
        mainToolBar->addAction(actionZoom_in);
        mainToolBar->addAction(actionZoom_out);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionImport->setText(QApplication::translate("MainWindow", "Import", 0, QApplication::UnicodeUTF8));
        actionMove->setText(QApplication::translate("MainWindow", "Move", 0, QApplication::UnicodeUTF8));
        actionResize->setText(QApplication::translate("MainWindow", "Resize", 0, QApplication::UnicodeUTF8));
        actionRename->setText(QApplication::translate("MainWindow", "Rename", 0, QApplication::UnicodeUTF8));
        actionRotate->setText(QApplication::translate("MainWindow", "Rotate", 0, QApplication::UnicodeUTF8));
        actionBend->setText(QApplication::translate("MainWindow", "Bend", 0, QApplication::UnicodeUTF8));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        actionPan->setText(QApplication::translate("MainWindow", "Pan", 0, QApplication::UnicodeUTF8));
        actionSpin_Around->setText(QApplication::translate("MainWindow", "Spin", 0, QApplication::UnicodeUTF8));
        actionZoom_in->setText(QApplication::translate("MainWindow", "Zoom in", 0, QApplication::UnicodeUTF8));
        actionZoom_out->setText(QApplication::translate("MainWindow", "Zoom out", 0, QApplication::UnicodeUTF8));
        actionTop->setText(QApplication::translate("MainWindow", "Top", 0, QApplication::UnicodeUTF8));
        actionFront->setText(QApplication::translate("MainWindow", "Front", 0, QApplication::UnicodeUTF8));
        actionLeft->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        actionRight->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        action45_Degree->setText(QApplication::translate("MainWindow", "45", 0, QApplication::UnicodeUTF8));
        action135_Degree->setText(QApplication::translate("MainWindow", "135", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open Figure", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save Figure", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionAdd->setText(QApplication::translate("MainWindow", "New Action", 0, QApplication::UnicodeUTF8));
        actionRemove->setText(QApplication::translate("MainWindow", "Remove Action", 0, QApplication::UnicodeUTF8));
        actionAdd_2->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        actionRemove_2->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        actionAdd_Frame->setText(QApplication::translate("MainWindow", "Add Frame", 0, QApplication::UnicodeUTF8));
        actionRemove_Frame->setText(QApplication::translate("MainWindow", "Remove Frame", 0, QApplication::UnicodeUTF8));
        actionAnimal_Editing_Mode->setText(QApplication::translate("MainWindow", "Animal Editing Mode", 0, QApplication::UnicodeUTF8));
        actionAction_Editing_Mode->setText(QApplication::translate("MainWindow", "Action Editing Mode", 0, QApplication::UnicodeUTF8));
        actionDoll_sitemap->setText(QApplication::translate("MainWindow", "Figure sitemap", 0, QApplication::UnicodeUTF8));
        actionNew_from_Current->setText(QApplication::translate("MainWindow", "New from Current", 0, QApplication::UnicodeUTF8));
        actionNew_from_Frame_0->setText(QApplication::translate("MainWindow", "New from Frame 0", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        actionPreview->setText(QApplication::translate("MainWindow", "Preview", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionHow_to->setText(QApplication::translate("MainWindow", "How to", 0, QApplication::UnicodeUTF8));
        actionOnline_manual->setText(QApplication::translate("MainWindow", "Online manual", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Component", 0, QApplication::UnicodeUTF8));
        add->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        del->setText(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        modify->setText(QApplication::translate("MainWindow", "Modify", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Size & Color", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Texture", 0, QApplication::UnicodeUTF8));
        color->setText(QApplication::translate("MainWindow", "Color", 0, QApplication::UnicodeUTF8));
        view->setText(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        bend->setText(QApplication::translate("MainWindow", "Bend", 0, QApplication::UnicodeUTF8));
        move->setText(QApplication::translate("MainWindow", "Move", 0, QApplication::UnicodeUTF8));
        rotate->setText(QApplication::translate("MainWindow", "Rotate", 0, QApplication::UnicodeUTF8));
        scale->setText(QApplication::translate("MainWindow", "Scale", 0, QApplication::UnicodeUTF8));
        info->setText(QApplication::translate("MainWindow", "Component: ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Frames", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Action", 0, QApplication::UnicodeUTF8));
        actions->clear();
        actions->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Freeze", 0, QApplication::UnicodeUTF8)
        );
        addFrame->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        removeFrame->setText(QApplication::translate("MainWindow", " -", 0, QApplication::UnicodeUTF8));
        moveStepUp->setText(QApplication::translate("MainWindow", "^", 0, QApplication::UnicodeUTF8));
        moveStepDown->setText(QApplication::translate("MainWindow", "v", 0, QApplication::UnicodeUTF8));
        delay->setSuffix(QString());
        curve->clear();
        curve->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Flat", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Drop", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Raise", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Hill", 0, QApplication::UnicodeUTF8)
        );
        actionPreviewForward->setText(QApplication::translate("MainWindow", ">", 0, QApplication::UnicodeUTF8));
        actionPreviewBack->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        menuModel->setTitle(QApplication::translate("MainWindow", "Model", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuAction->setTitle(QApplication::translate("MainWindow", "Action", 0, QApplication::UnicodeUTF8));
        menuFrame->setTitle(QApplication::translate("MainWindow", "Frame", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
