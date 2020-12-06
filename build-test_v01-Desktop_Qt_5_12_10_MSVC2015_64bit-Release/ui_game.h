/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QStatusBar *statusbar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QString::fromUtf8("game"));
        game->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Stroke(RUS BY LYAJKA)"));
        game->setFont(font);
        game->setFocusPolicy(Qt::NoFocus);
        game->setStyleSheet(QString::fromUtf8("background-color: rgb(38,38,38)"));
        centralwidget = new QWidget(game);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Modern"));
        font1.setPointSize(48);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        graphicsView->setFont(font1);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(140, 50));
        pushButton_2->setMaximumSize(QSize(140, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Comic Sans MS"));
        font2.setPointSize(12);
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(11,96,236);\n"
"border-radius: 10px;\n"
"color: white  "));

        gridLayout_2->addWidget(pushButton_2, 2, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Comic Sans MS"));
        font3.setPointSize(20);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("color: red;"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(140, 50));
        pushButton_3->setMaximumSize(QSize(140, 50));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(11,96,236);\n"
"border-radius: 10px;\n"
"color: white  "));

        gridLayout_2->addWidget(pushButton_3, 3, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(140, 50));
        pushButton->setMaximumSize(QSize(140, 50));
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(11,96,236);\n"
"border-radius: 10px;\n"
"color: white  "));

        gridLayout_2->addWidget(pushButton, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Comic Sans MS"));
        font4.setPointSize(14);
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("color: white"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        game->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(game);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        game->setStatusBar(statusbar);
        menuBar = new QMenuBar(game);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 20));
        game->setMenuBar(menuBar);

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QMainWindow *game)
    {
        game->setWindowTitle(QApplication::translate("game", "MainWindow", nullptr));
        pushButton_2->setText(QApplication::translate("game", "\320\235\320\260\321\207\320\260\321\202\321\214", nullptr));
        label->setText(QApplication::translate("game", "00:00", nullptr));
        pushButton_3->setText(QApplication::translate("game", "\320\237\320\265\321\200\320\265\321\201\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        pushButton->setText(QApplication::translate("game", "\320\222\321\213\320\271\321\202\320\270 \320\262 \320\233\320\260\321\203\320\275\321\207\320\265\321\200", nullptr));
        label_2->setText(QApplication::translate("game", "fps: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
