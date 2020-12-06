#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QFont>
#include <QTimer>
#include <QTime>
#include <QGraphicsObject>
#include <QKeyEvent>
#include <QLayout>
#include <QLabel>
#include <QString>
#include <vector>
#include <QBrush>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <fstream>
#include <QtMath>
#include "time.h"
#include <QByteArray>
#include <QFile>
#include <windows.h>
#include <QMessageBox>
#include <QInputDialog>
#include <QApplication>
#include <QFont>
#include <QSize>
#include <QPixmap>
#include <QQueue>

namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    void Paint3D(int a);
    void LogRecoder(QString log);
    QPixmap *pic_hero = new QPixmap(":/images/face.png");
    QPixmap *pic_win_man = new QPixmap(":/images/Robowin.png");
    QPixmap *pic_win_robot = new QPixmap(":/images/Peoplewin.png");
    QPixmap *pic_robot = new QPixmap(":/images/robot.gif");
    QPixmap *pic_gen = new QPixmap(":/images/gen.png");
    ~game();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void slotAlarmTimer();
    void slotAlartFps();

    void Reset_Scene();

    void win_message_robot();
    void win_message_man();
    void move_hero(int a, int move_x, int move_y);
    void move_robot(int a, int move_x, int move_y);
    void navigator();

private:
        Ui::game *ui;
        QGraphicsScene *scene;
        QTimer *timer_paint;
        QTimer *timer_fps;
        QTimer *robot_time;
       // QTimer *timer_

        void keyPressEvent(QKeyEvent *event);
};

#endif // GAME_H
