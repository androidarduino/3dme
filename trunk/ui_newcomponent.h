/********************************************************************************
** Form generated from reading ui file 'newcomponent.ui'
**
** Created: Tue Nov 24 16:12:32 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NEWCOMPONENT_H
#define UI_NEWCOMPONENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewComponent
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *cname;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_8;
    QComboBox *pointTo;
    QLabel *label_5;
    QLineEdit *bendX;
    QLabel *label_6;
    QLineEdit *bendY;
    QLabel *label_7;
    QLineEdit *bendZ;
    QLabel *label_4;
    QComboBox *axisConjunction;
    QLineEdit *sizeX;
    QLineEdit *sizeY;
    QLineEdit *sizeZ;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_9;
    QComboBox *csizeUnit;
    QCheckBox *stretch;
    QLabel *label_13;
    QComboBox *axisParent;
    QComboBox *myAxis;
    QLabel *label_14;
    QLabel *label_15;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewComponent)
    {
        if (NewComponent->objectName().isEmpty())
            NewComponent->setObjectName(QString::fromUtf8("NewComponent"));
        NewComponent->resize(368, 519);
        verticalLayout = new QVBoxLayout(NewComponent);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(NewComponent);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cname = new QLineEdit(NewComponent);
        cname->setObjectName(QString::fromUtf8("cname"));

        gridLayout->addWidget(cname, 0, 1, 1, 3);

        label_2 = new QLabel(NewComponent);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(NewComponent);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 11, 0, 1, 1);

        label_8 = new QLabel(NewComponent);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 11, 1, 1, 1);

        pointTo = new QComboBox(NewComponent);
        pointTo->setObjectName(QString::fromUtf8("pointTo"));

        gridLayout->addWidget(pointTo, 11, 2, 1, 1);

        label_5 = new QLabel(NewComponent);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 12, 1, 1, 1);

        bendX = new QLineEdit(NewComponent);
        bendX->setObjectName(QString::fromUtf8("bendX"));

        gridLayout->addWidget(bendX, 12, 2, 1, 2);

        label_6 = new QLabel(NewComponent);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 13, 1, 1, 1);

        bendY = new QLineEdit(NewComponent);
        bendY->setObjectName(QString::fromUtf8("bendY"));

        gridLayout->addWidget(bendY, 13, 2, 1, 2);

        label_7 = new QLabel(NewComponent);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 14, 1, 1, 1);

        bendZ = new QLineEdit(NewComponent);
        bendZ->setObjectName(QString::fromUtf8("bendZ"));

        gridLayout->addWidget(bendZ, 14, 2, 1, 2);

        label_4 = new QLabel(NewComponent);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 15, 0, 1, 1);

        axisConjunction = new QComboBox(NewComponent);
        axisConjunction->setObjectName(QString::fromUtf8("axisConjunction"));

        gridLayout->addWidget(axisConjunction, 17, 2, 1, 1);

        sizeX = new QLineEdit(NewComponent);
        sizeX->setObjectName(QString::fromUtf8("sizeX"));

        gridLayout->addWidget(sizeX, 7, 2, 1, 1);

        sizeY = new QLineEdit(NewComponent);
        sizeY->setObjectName(QString::fromUtf8("sizeY"));
        sizeY->setEnabled(false);

        gridLayout->addWidget(sizeY, 8, 2, 1, 1);

        sizeZ = new QLineEdit(NewComponent);
        sizeZ->setObjectName(QString::fromUtf8("sizeZ"));
        sizeZ->setEnabled(false);

        gridLayout->addWidget(sizeZ, 9, 2, 1, 1);

        label_10 = new QLabel(NewComponent);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 7, 1, 1, 1);

        label_11 = new QLabel(NewComponent);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 8, 1, 1, 1);

        label_12 = new QLabel(NewComponent);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 9, 1, 1, 1);

        label_9 = new QLabel(NewComponent);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 3, 1, 1, 1);

        csizeUnit = new QComboBox(NewComponent);
        csizeUnit->setObjectName(QString::fromUtf8("csizeUnit"));

        gridLayout->addWidget(csizeUnit, 3, 2, 1, 1);

        stretch = new QCheckBox(NewComponent);
        stretch->setObjectName(QString::fromUtf8("stretch"));

        gridLayout->addWidget(stretch, 2, 2, 1, 1);

        label_13 = new QLabel(NewComponent);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 17, 1, 1, 1);

        axisParent = new QComboBox(NewComponent);
        axisParent->setObjectName(QString::fromUtf8("axisParent"));

        gridLayout->addWidget(axisParent, 16, 2, 1, 1);

        myAxis = new QComboBox(NewComponent);
        myAxis->setObjectName(QString::fromUtf8("myAxis"));

        gridLayout->addWidget(myAxis, 15, 2, 1, 1);

        label_14 = new QLabel(NewComponent);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_14, 15, 1, 1, 1);

        label_15 = new QLabel(NewComponent);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_15, 16, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(NewComponent);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(NewComponent);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewComponent, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewComponent, SLOT(reject()));
        QObject::connect(stretch, SIGNAL(clicked(bool)), sizeY, SLOT(setEnabled(bool)));
        QObject::connect(stretch, SIGNAL(clicked(bool)), sizeZ, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(NewComponent);
    } // setupUi

    void retranslateUi(QDialog *NewComponent)
    {
        NewComponent->setWindowTitle(QApplication::translate("NewComponent", "Fill in component properties", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewComponent", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewComponent", "Size", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NewComponent", "Direction", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("NewComponent", "Point to:", 0, QApplication::UnicodeUTF8));
        pointTo->clear();
        pointTo->insertItems(0, QStringList()
         << QApplication::translate("NewComponent", "NA", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewComponent", "Up", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewComponent", "Down", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewComponent", "Left", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewComponent", "Right", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewComponent", "Front", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewComponent", "Back", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("NewComponent", "x:", 0, QApplication::UnicodeUTF8));
        bendX->setText(QApplication::translate("NewComponent", "0", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NewComponent", "y:", 0, QApplication::UnicodeUTF8));
        bendY->setText(QApplication::translate("NewComponent", "0", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("NewComponent", "z:", 0, QApplication::UnicodeUTF8));
        bendZ->setText(QApplication::translate("NewComponent", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NewComponent", "Axis", 0, QApplication::UnicodeUTF8));
        sizeX->setText(QApplication::translate("NewComponent", "0", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("NewComponent", "x:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("NewComponent", "y:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("NewComponent", "z:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("NewComponent", "Unit", 0, QApplication::UnicodeUTF8));
        csizeUnit->clear();
        csizeUnit->insertItems(0, QStringList()
         << QApplication::translate("NewComponent", "cm", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewComponent", "mm", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewComponent", "meter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewComponent", "km", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewComponent", "inches", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewComponent", "feet", 0, QApplication::UnicodeUTF8)
        );
        stretch->setText(QApplication::translate("NewComponent", "Stretch", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("NewComponent", ".", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("NewComponent", "Connect", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("NewComponent", "to", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(NewComponent);
    } // retranslateUi

};

namespace Ui {
    class NewComponent: public Ui_NewComponent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCOMPONENT_H
