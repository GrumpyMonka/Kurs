#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <QLabel>
#include <QGLWidget>
#include <QtOpenGL>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusbar->showMessage("log: Программа запущена");

   // ui->gridLayout->addWidget(new QLabel("ok"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int size_lab = 0;
int level_hard = 0;

void MainWindow::on_pushButton_clicked()
{
    ui->radioButton->click();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->radioButton_2->click();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->radioButton_3->click();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->radioButton_4->click();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->radioButton_5->click();
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->radioButton_6->click();
}

void MainWindow::on_pushButton_7_clicked()
{
    if (size_lab && level_hard){
        ui->statusbar->showMessage("log: Игра запущена...");
        hide();
        game *gamewindow = new game();
        gamewindow->showFullScreen();
        //gamewindow->
        //gamewindow-> show();

        gamewindow->Paint3D(size_lab);

        connect(gamewindow, &game::firstWindow, this, &MainWindow::show);
    }else{
        ui->statusbar->showMessage("log: Не все параметры введены.");
    }
}

void MainWindow::on_radioButton_clicked()
{
      size_lab = 19;
}

void MainWindow::on_radioButton_2_clicked()
{
      size_lab = 27;
}

void MainWindow::on_radioButton_3_clicked()
{
      size_lab = 35;
}

void MainWindow::on_radioButton_6_clicked()
{
      level_hard = 3;
}

void MainWindow::on_radioButton_5_clicked()
{
      level_hard = 2;
}

void MainWindow::on_radioButton_4_clicked()
{
      level_hard = 1;
}

void MainWindow::on_pushButton_8_clicked()
{
   qApp->quit();
}
