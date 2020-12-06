/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_2;
    QRadioButton *radioButton_3;
    QPushButton *pushButton_3;
    QFrame *line;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QPushButton *pushButton_4;
    QRadioButton *radioButton_5;
    QPushButton *pushButton_5;
    QRadioButton *radioButton_6;
    QPushButton *pushButton_6;
    QRadioButton *radioButton_4;
    QPushButton *pushButton_7;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_8;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(38,38,38)\n"
"  "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(80, 330, 301, 171));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Comic Sans MS"));
        font1.setPointSize(14);
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("color: white"));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 281, 161));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(formLayoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::LabelRole, radioButton);

        radioButton_2 = new QRadioButton(formLayoutWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        sizePolicy1.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy1);

        formLayout->setWidget(1, QFormLayout::LabelRole, radioButton_2);

        pushButton_2 = new QPushButton(formLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(11,96,236);\n"
"border-radius: 10px;\n"
"color: white  "));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButton_2);

        radioButton_3 = new QRadioButton(formLayoutWidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        sizePolicy1.setHeightForWidth(radioButton_3->sizePolicy().hasHeightForWidth());
        radioButton_3->setSizePolicy(sizePolicy1);
        radioButton_3->setLayoutDirection(Qt::LeftToRight);

        formLayout->setWidget(2, QFormLayout::LabelRole, radioButton_3);

        pushButton_3 = new QPushButton(formLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 40));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(11,96,236);\n"
"border-radius: 10px;\n"
"color: white  "));

        formLayout->setWidget(2, QFormLayout::FieldRole, pushButton_3);

        line = new QFrame(formLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(3, QFormLayout::FieldRole, line);

        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(11,96,236);\n"
"border-radius: 10px;\n"
"color: white  "));

        formLayout->setWidget(0, QFormLayout::FieldRole, pushButton);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(410, 330, 301, 171));
        groupBox_2->setFont(font1);
        groupBox_2->setStyleSheet(QString::fromUtf8("color: white"));
        formLayoutWidget_2 = new QWidget(groupBox_2);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 30, 281, 141));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignCenter);
        formLayout_2->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(formLayoutWidget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 40));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(11,96,236);\n"
"border-radius: 10px;\n"
"color: white  "));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pushButton_4);

        radioButton_5 = new QRadioButton(formLayoutWidget_2);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        sizePolicy1.setHeightForWidth(radioButton_5->sizePolicy().hasHeightForWidth());
        radioButton_5->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, radioButton_5);

        pushButton_5 = new QPushButton(formLayoutWidget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 40));
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(11,96,236);\n"
"border-radius: 10px;\n"
"color: white  "));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, pushButton_5);

        radioButton_6 = new QRadioButton(formLayoutWidget_2);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(radioButton_6->sizePolicy().hasHeightForWidth());
        radioButton_6->setSizePolicy(sizePolicy2);
        radioButton_6->setLayoutDirection(Qt::LeftToRight);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, radioButton_6);

        pushButton_6 = new QPushButton(formLayoutWidget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 40));
        pushButton_6->setFont(font1);
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(11,96,236);\n"
"border-radius: 10px;\n"
"color: white  "));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, pushButton_6);

        radioButton_4 = new QRadioButton(formLayoutWidget_2);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        sizePolicy1.setHeightForWidth(radioButton_4->sizePolicy().hasHeightForWidth());
        radioButton_4->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, radioButton_4);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(650, 510, 140, 40));
        pushButton_7->setFont(font1);
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(11,96,236);\n"
"border-radius: 10px;\n"
"color: white\n"
"  "));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, -10, 321, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Comic Sans MS"));
        font2.setPointSize(32);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: red;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 401, 261));
        label_2->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"  "));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Pictures/maze.jpg")));
        label_2->setScaledContents(true);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(10, 510, 140, 40));
        pushButton_8->setFont(font1);
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(11,96,236);\n"
"border-radius: 10px;\n"
"color: white  "));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(430, 40, 371, 271));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Comic Sans MS"));
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(211,232,245)"));
        label_3->setWordWrap(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\233\320\260\320\261\320\270\321\200\320\270\320\275\321\202 2D \320\273\320\260\321\203\320\275\321\207\320\265\321\200", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\200\320\260\320\267\320\274\320\265\321\200:", nullptr));
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "27x27", nullptr));
        radioButton_3->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "35x35", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "19x19", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214:", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Easy", nullptr));
        radioButton_5->setText(QString());
        pushButton_5->setText(QApplication::translate("MainWindow", "Middle", nullptr));
        radioButton_6->setText(QString());
        pushButton_6->setText(QApplication::translate("MainWindow", "Hard", nullptr));
        radioButton_4->setText(QString());
        pushButton_7->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\270\320\263\321\200\320\260\321\202\321\214", nullptr));
        label->setText(QApplication::translate("MainWindow", "<p><b>\320\233\320\260\320\261\320\270\321\200\320\270\320\275\321\202 2D</b></p>", nullptr));
        label_2->setText(QString());
        pushButton_8->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">\320\237\321\200\320\270\320\262\320\265\321\202\321\201\321\202\320\262\321\203\321\216 \321\202\320\265\320\261\321\217 \321\201\320\276\320\273\320\264\320\260\321\202. \320\242\321\213 \320\275\320\260\320\274 \320\275\321\203\320\266\320\265\320\275 \320\262 \320\262\320\276\320\271\320\275\320\265 \320\277\321\200\320\276\321\202\320\270\320\262 \320\272\320\270\320\261\320\276\321\200\320\263\320\276\320\262. \320\224\320\265\320\273\320\276 \320\262 \321\202\320\276\320\274, \321\207\321\202\320\276 \320\262 \320\274\321\213 \320\275\320\260\321\210\320\273\320\270 \320\274\320\260\321\210\320\270\320\275\321\203 \320\262\321\200\320\265\320\274\320\265\320\275\320\270. \320\232\321\205\320\274\320\265... \320\275\321\203 \320\272\320\260\320\272 \321\201\320\272\320\260\320\267\320\260\321\202\321\214 \320\275\320\260\321\210\320\273\320\270, \320\277\321\200\320\276\320\261\320\273\320\265\320\274\320\260 \320\273\320\270\321\210\321\214 \320\262"
                        " \321\202\320\276\320\274, \321\207\321\202\320\276 \320\276\320\275\320\260 \321\201\320\277\321\200\321\217\321\202\320\260\320\275\320\260 \320\262 \320\273\320\260\320\261\320\270\321\200\320\270\320\275\321\202\320\265. \320\235\321\203\320\266\320\275\320\276 \320\264\320\276\320\261\321\200\320\260\321\202\321\214\321\201\321\217 \320\264\320\276 \320\275\320\265\321\221 \321\200\320\260\320\275\321\214\321\210\320\265 \320\272\320\270\320\261\320\276\321\200\320\263\320\276\320\262 \320\270 \321\202\320\276\320\263\320\264\320\260 \320\274\321\213 \321\201\320\274\320\276\320\266\320\265\320\274 \320\277\321\200\320\265\320\264\320\276\321\202\320\262\321\200\320\260\321\202\320\270\321\202\321\214 \320\275\320\260\321\210\320\265\321\201\321\202\320\262\320\270\320\265. \320\222\320\276\321\202 \321\202\320\265\320\261\320\265 \321\200\321\216\320\272\320\267\320\260\320\272 \321\201 \320\265\320\264\320\276\320\271. \320\220 \321\202\320\265\320\277\320\265\321\200\321\214 \320\262\320\277\320\265\321"
                        "\200\321\221\320\264, \321\207\320\265\320\273\320\276\320\262\320\265\321\207\320\265\321\201\321\202\320\262\320\276 \321\200\320\260\321\201\321\201\321\207\320\270\321\202\321\213\320\262\320\260\320\265\321\202 \320\275\320\260 \321\202\320\265\320\261\321\217.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
