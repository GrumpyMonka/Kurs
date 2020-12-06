#include "game.h"
#include "ui_game.h"

using namespace std;

int razmer;
int** labirint; // 1 - проход ; 0 - стена;
bool** visible;
bool button_3_ready(true);
ofstream fout("log.txt");
int fps = 0;
int time_timer = 0;

QPen *redpen = new QPen(Qt::red);
QPen *whitepen = new QPen(Qt::white);
QPen *transparentpen = new QPen(Qt::transparent);
QBrush *greenBrush = new QBrush(QColor(66,165,23), Qt::SolidPattern);
QBrush *blackBrush = new QBrush(Qt::black, Qt::SolidPattern);  //Dense3Pattern
QBrush *brownBrush = new QBrush(QColor(101,76,20), Qt::SolidPattern);
QBrush *whiteBrush = new QBrush(Qt::white, Qt::SolidPattern);
QBrush *blueBrush = new QBrush(QColor(7,80,243), Qt::SolidPattern);
QBrush *grayBrush = new QBrush(QColor(202,228,242), Qt::SolidPattern);
QBrush *redBrush = new QBrush(Qt::red, Qt::SolidPattern);
QGraphicsPixmapItem* item_hero;
QGraphicsPixmapItem* item_robot;
//QImage image(":/images/Win.png");

struct cell{
    int x;
    int y;
};

cell input, output;
cell hero = {0, 0};
cell robot = {0, 0};
int razmer_h;
vector<int> road;

game::game(QWidget *parent) :QMainWindow(parent), ui(new Ui::game){
    ui->setupUi(this);
    fout << "Запуск Game" << endl;

    ui->statusbar->showMessage("log: Игра запущена...");
    ui->graphicsView->setFrameShape(QFrame::NoFrame);
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    this->setFocus();
   }

game::~game()
{
    delete item_hero;
    delete item_robot;
    delete redpen;
    delete whitepen;
    delete greenBrush;
    delete blackBrush;
    delete brownBrush;
    delete whiteBrush;
    delete blueBrush;
    delete grayBrush;

    for (int i = 0; i < razmer; i++){
        delete [] labirint[i];
    }
    delete [] labirint;
    fout.close();
    delete ui;
}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

void seach_exit(int a){
    vector<int> cell_true;
    for (int i = 1; i < (a - 1); i++){
        if (labirint[i][a - 2]){
            cell_true.push_back(i);
        }
    }

    int ran = randomBetween(0 , cell_true.size() - 1);
    output.x = cell_true[ran];
    output.y = a - 1;
    labirint[output.x][output.y] = 1;
}

bool labirint_ready(int a){
    /*
    fout << endl;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            fout << visible[i][j] << " ";
        }
        fout << endl;
    }
    fout << endl;
*/
    for (int i = 1; i < a; i += 2){
        for (int j = 1; j < a; j += 2){
            if (visible[i][j] == false){
                //fout << "false" << endl;
                return false;
            }
        }
    }
    //fout << "true" << endl;
    return true;
}

void mole(int a, int start_x, int start_y){
    stack<int> Steck_x;
    stack<int> Steck_y;
    Steck_x.push(start_x);
    Steck_y.push(start_y);

    int count = 0;

    button_3_ready = false;
    while (!labirint_ready(a)){ // count--
        count++;
        start_x = Steck_x.top();
        start_y = Steck_y.top();

        int rand_move = randomBetween(0,3);
        //fout << rand_move << endl;
        //fout << "Клетка: " << start_x << " " << start_y << " -> ";
        switch (rand_move){
        case 0:
            if ((start_x + 2) < (a - 1)){
                if (labirint[start_x + 2][start_y] == 0){
                    labirint[start_x + 2][start_y] = 1;
                    labirint[start_x + 1][start_y] = 1;
                }
                visible[start_x + 2][start_y] = true;
                visible[start_x + 1][start_y] = true;
                Steck_x.pop();
                Steck_x.push(start_x + 2);
             //   fout << start_x + 2 << " " << start_y << endl;
            }
            break;
        case 1:
            if ((start_x - 2) > 0){
                if (labirint[start_x - 2][start_y] == 0){
                    labirint[start_x - 2][start_y] = 1;
                    labirint[start_x - 1][start_y] = 1;
                }
                visible[start_x - 2][start_y] = true;
                visible[start_x - 1][start_y] = true;
                Steck_x.pop();
                Steck_x.push(start_x - 2);
               // fout << start_x - 2 << " " << start_y << endl;
            }
            break;
        case 2:
            if ((start_y + 2) < (a - 1)){
                if (labirint[start_x][start_y + 2] == 0){
                    labirint[start_x][start_y + 2] = 1;
                    labirint[start_x][start_y + 1] = 1;
                }
                visible[start_x][start_y + 2] = true;
                visible[start_x][start_y + 1] = true;
                Steck_y.pop();
                Steck_y.push(start_y + 2);
             //   fout << start_x << " " << start_y + 2 << endl;
            }
            break;
        case 3:
            if ((start_y - 2) > 0){
                if (labirint[start_x][start_y - 2] == 0){
                    labirint[start_x][start_y - 2] = 1;
                    labirint[start_x][start_y - 1] = 1;
                }
                visible[start_x][start_y - 2] = true;
                visible[start_x][start_y - 1] = true;
                Steck_y.pop();
                Steck_y.push(start_y - 2);
              //  fout << start_x << " " << start_y - 2 << endl;
            }
            break;
        }
/*
        fout << endl;
        for (int i = 0; i < a; i++){
            for (int j = 0; j < a; j++){
                fout << labirint[i][j] << " ";
            }
            fout << endl;
        }

        fout << endl;
        fout << endl;
        */
    }
    button_3_ready = true;
    fout << "Лабиринт " << a << "x" << a << " шагов для генерации: " << count << endl;
}

vector<vector<int>> Convert(int a){
    vector<vector<int>> list;

    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            list.push_back(vector<int>());
        }
    }

    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            if (labirint[i][j]){
                if ((i+1) < a){
                    if (labirint[i+1][j]){
                        list[i*a + j].push_back((i+1)*a + j);
                    }
                }
                if ((i-1) >= 0){
                    if (labirint[i-1][j]){
                        list[i*a + j].push_back((i-1)*a + j);
                    }
                }
                if ((j+1) < a){
                    if (labirint[i][j+1]){
                        list[i*a + j].push_back(i*a + j + 1);
                    }
                }
                if ((j-1) >= 0){
                    if (labirint[i][j-1]){
                        list[i*a + j].push_back(i*a + j - 1);
                    }
                }
            }
        }
    }
    return list;
}

vector<int> Sweet_cell(vector<vector<int>> pole, int a){
    /*
    for (int i = 0; i < a*a; i++){
        //fout << i << ": " << pole[i].size() << endl;
        fout << i << ": ";
        for (int j = 0; j < pole[i].size(); j++){
            fout << pole[i][j] << " ";
        }
        fout << endl;
    }
    */

    vector<int> dist(a*a);
    int start = output.x*a + output.y;
    for (int i = 0; i < a*a; i++){
        dist[i] = -1;
    }

    QQueue<int> Steck;
    Steck.push_back(start);
    dist[start] = 0;

    int v;
    while (!Steck.empty()) {
        v = Steck.front();
        //fout << "start " << v << endl;
        Steck.pop_front();
        for (int i = 0; i < pole[v].size(); i++) {
            if (dist[pole[v][i]] == -1) {
                Steck.push_back(pole[v][i]);
                dist[pole[v][i]] = dist[v] + 1;
            }
        }
    }
    /*
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++){
            fout << labirint[i][j] << " ";
        }
        fout << endl;
    }
    fout << endl;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++){
            fout << dist[i*a + j] << " ";
        }
        fout << endl;
    }
    fout << endl;
    */
    return dist;
}

bool flag(false);
vector<int> Seach_point(int a, vector<vector<int>> pole, int in_x,int in_y,int out_x, int out_y){
    vector<int> result;
    //fout << "Вход: " << in_x << " " << in_y << " " << out_x << " " << out_y << endl;
    if ((in_x == out_x) && (in_y == out_y)){
        flag = true;
        result.push_back(in_x*a + in_y);
        return result;
    }
    for (int i = 0; i < pole[in_x*a + in_y].size(); i++){
        if (!visible[pole[in_x*a + in_y][i]/a][pole[in_x*a + in_y][i]%a]){
            visible[pole[in_x*a + in_y][i]/a][pole[in_x*a + in_y][i]%a] = true;
            result = Seach_point(a, pole, pole[in_x*a + in_y][i]/a, pole[in_x*a + in_y][i]%a, out_x, out_y);
         }
        if (flag){
            result.push_back(in_x*a + in_y);
            /*
            for (int j = 0; j < result.size(); j++){
                fout << result[j] << " ";
            }
            fout << endl;
            */
            return result;
        }
    }
    return result;
}

vector<int> Seach_road(vector<int> road, vector<vector<int>> list, int a, int in_x, int in_y,  int out_x, int out_y){
    vector<int> vision;
    vector<int> result;
    int radius = a/4;
    result.push_back(in_x*a + in_y);

    cell v;
    while(result[result.size() - 1] != (out_x*a + out_y)){
        v = {result[result.size() - 1]/a , result[result.size() - 1]%a};
        int min = road[v.x*a + v.y];
        for (int i = -radius; i <= radius; i++){
            for(int j = -radius; j <= radius; j++){
                if(((i*i + j*j) <= (radius*radius)) && ((v.x + i) > -1) && ((v.y + j) > -1) && ((v.x + i) < a) && ((v.y + j) < a)){
                    if ((road[(v.x + i)*a + v.y + j] != -1) && (road[(v.x + i)*a + v.y + j] < min)){
                        min = road[(v.x + i)*a + v.y + j];
                        vision.clear();
                        vision.push_back((v.x + i)*a + v.y + j);
                    }else{
                        if ((road[(v.x + i)*a + v.y + j] != -1) && (road[(v.x + i)*a + v.y + j] == min)){
                            vision.push_back((v.x + i)*a + v.y + j);
                        }
                    }
                }
            }
        }
        /*
        for (int i = 0; i < vision.size(); i++){
            fout << vision[i] << " ";
        }
        fout << endl;
        */
        int randnum = randomBetween(0, vision.size() - 1);
        result.push_back(vision[randnum]);
        vision.clear();
    }
/*
    for (int i = 0; i < result.size(); i++){
        fout << result[i] << "  ";
    }
    fout << endl;
*/
    vision = result;
    result.clear();
    result.push_back(vision[0]);
    result.push_back(vision[0]);
    result.push_back(vision[0]);
    result.push_back(vision[0]);
    result.push_back(vision[0]);
    result.push_back(vision[0]);
    result.push_back(vision[0]);
    result.push_back(vision[0]);
    vector<int> temp;
    for (int i = 1; i < vision.size(); i++){
        for (int k = 0; k < a; k++){
            for (int j = 0; j < a; j++){
                visible[k][j] = false;
            }
        }
        flag = false;
        temp = Seach_point(a, list, vision[i-1]/a, vision[i-1]%a, vision[i]/a, vision[i]%a);
        temp.pop_back();

        for (int j = (temp.size()-1); j >= 0; j--){
            result.push_back(temp[j]);
        }

    }
/*
    for (int i = 0; i < result.size(); i++){
        fout << result[i] << "  ";
    }
    fout << endl;
*/
    return result;
}

int counter_robot = 0;
void game::navigator(){
    //fout << "x, y " << robot.x << " " << robot.y;
    if ((robot.x == output.x) && (robot.y == output.y)){
        return;
    }
    move_robot(razmer, (road[counter_robot + 1]/razmer - road[counter_robot]/razmer), (road[counter_robot + 1]%razmer - road[counter_robot]%razmer));
    counter_robot++;
}

void game::LogRecoder(QString log){
    ui->statusbar->showMessage("log: " + log);
    //fout << "log: " << log.toUtf8() << endl;
}

void game::win_message_man(){
    timer_paint->stop();
    timer_fps->stop();
    robot_time->stop();
    scene->clear();

    item_hero = scene->addPixmap(*pic_win_man);
    item_hero->setPos(-320,-252);

}

void game::win_message_robot(){
   // QMessageBox::about(this, "Лабириет 2D" , "Победа ");
    timer_paint->stop();
    timer_fps->stop();
    robot_time->stop();
    scene->clear();
    /*
    QPixmap pic2(":/images/face.png");
    QSize PicSize(400, 300);
    pic2 = pic2.scaled(PicSize,Qt::KeepAspectRatio);
    scene->addPixmap(pic2);
    */
    item_hero = scene->addPixmap(*pic_win_robot);
    item_hero->setPos(-320,-252);
  //  scene->addItem(item);
    //scene->addPixmap(QPixmap::fromImage(image));

    //scene->addText("Победа");
    //QFont *myfont = new QFont();
    //myfont->setPixelSize(200);
    //scene->setFont(*myfont);
}

void game::move_hero(int a, int move_x, int move_y){
    if (hero.x == output.x && hero.y == output.y){
        return;
    }
    cell temp = hero;
    temp.x += move_x;
    temp.y += move_y;

    if ((temp.x > -1) && (temp.x < (a)) && (temp.y > -1) && (temp.y < (a)) && (labirint[temp.x][temp.y])){
        hero = temp;
        if (hero.x == output.x && hero.y == output.y){
            ui->statusbar->showMessage("log: Победа");
            win_message_man();
        }
    }
}

void game::move_robot(int a, int move_x, int move_y){
    //fout << " move " << move_x << " " << move_y << endl;
    if (robot.x == output.x && robot.y == output.y){
        return;
    }
    cell temp = robot;
    temp.x += move_x;
    temp.y += move_y;

    if ((temp.x > -1) && (temp.x < (a)) && (temp.y > -1) && (temp.y < (a)) && (labirint[temp.x][temp.y])){
        robot = temp;
        if (robot.x == output.x && robot.y == output.y){
            ui->statusbar->showMessage("log: Победа");
            win_message_robot();
        }
    }
}

void game::slotAlartFps(){
    //Reset_Scene();
    time_timer++;
    ui->label_2->setText("fps: " + QString::number(fps));
    fps = 0;
    QString str = "";

    if (time_timer/60 > 9){
        str = QString::number(time_timer/60) + ":";
    }else{
        str = "0" + QString::number(time_timer/60) + ":";
    }

    if (time_timer%60 > 9){
        str += QString::number(time_timer%60);
    }else{
        str += "0" + QString::number(time_timer%60);
    }
    ui->label->setText(str);

}

void game::Paint3D(int a){
    razmer = a;
    ui->statusbar->showMessage("log: Paint3D был запущен.");

    labirint = new int*[a];
    visible = new bool*[a];
    for(int i = 0; i < a; i++){
        labirint[i] = new int[a];
        visible[i] = new bool[a];
    }

    for (int i = 0; i < razmer; i++){
        for (int j = 0; j < razmer; j++){
            labirint[i][j] = 0;
            if((i == 0) || (j == 0) || (i == (razmer - 1)) || (j == (razmer - 1))){
                visible[i][j] = true;
            }else{
                visible[i][j] = false;
            }
        }
    }
/*
    fout << endl;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            fout << visible[i][j] << " ";
        }
        fout << endl;
    }
*/
    hero.x = 0;
    hero.y = 0;

    item_hero = scene->addPixmap(*pic_hero);
    scene->addItem(item_hero);
    item_robot = scene->addPixmap(*pic_robot);
    scene->addItem(item_robot);

    timer_paint = new QTimer();
    connect(timer_paint, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));

    timer_fps = new QTimer();
    connect(timer_fps, SIGNAL(timeout()), this, SLOT(slotAlartFps()));
   // timer_fps->start(1000);

    robot_time = new QTimer();
    connect(robot_time, SIGNAL(timeout()), this, SLOT(navigator()));

 //   Reset_Scene();

  //  delay();
  //  delay();
    ui->pushButton_3->click();
}

void game::on_pushButton_clicked()
{
    this->setFocus();
    delete timer_paint;
    delete timer_fps;
    delete robot_time;
    emit firstWindow();
    this->close();
}

void game::on_pushButton_2_clicked()
{
    this->setFocus();

    ui->pushButton_2->setEnabled(false);

}

void game::Reset_Scene(){
    razmer_h = ui->graphicsView->width();
    razmer_h /= 2;\
    int razmer_w = ui->graphicsView->height();

    if (razmer_w < razmer_h){
        razmer_h = razmer_w;
    }

    int razmer_used = razmer;

    int h_used = razmer_h - razmer_h/50; // уменьшаем размер лабиринта на 2% для удобства отображения
    int line = h_used/razmer_used;

    fout << "log: razmer: " << razmer_h << endl;

    scene->clear();

    for (int i = 0; i < razmer_used; i ++){
        for (int j = 0; j < razmer_used; j++){
            if (labirint[i][j]){
                scene->addRect(j*line - (razmer_used/2*line) - razmer_h/2, i*line - (razmer_used/2*line), line, line, *whitepen, *grayBrush);
                scene->addRect(j*line - (razmer_used/2*line) + razmer_h/2, i*line - (razmer_used/2*line), line, line, *whitepen, *grayBrush);
            }else{
                scene->addRect(j*line - (razmer_used/2*line) - razmer_h/2, i*line - (razmer_used/2*line), line, line, *whitepen, *brownBrush);
                scene->addRect(j*line - (razmer_used/2*line) + razmer_h/2, i*line - (razmer_used/2*line), line, line, *whitepen, *brownBrush);
            }
        }
    }
    *pic_robot = pic_robot->scaled(QSize(line - (line/4), line - (line/4)),Qt::KeepAspectRatio);
    item_robot = scene->addPixmap(*pic_robot);

    *pic_hero = pic_hero->scaled(QSize(line - (line/4), line - (line/4)),Qt::KeepAspectRatio);
    item_hero = scene->addPixmap(*pic_hero);

}

void game::slotAlarmTimer(){
    fps++;

    int razmer_used = razmer;

    //fout << "log: razmer: " << razmer_h << endl;

    int h_used = razmer_h - razmer_h/50; // уменьшаем размер лабиринта на 2% для удобства отображения
    int line = h_used/razmer_used;
    //ui->statusbar->showMessage("log: Высота: " + QString::number(h_used) + " Линия: " + QString::number(line) + " Шаг: " + QString::number(line/8));
    /*
    while (old_hero.size()){
        QRect temp = new QRect()
        scene->addRect(old_hero[old_hero.size() - 1].y*line - (razmer_used/2*line) + (line/8), old_hero[old_hero.size() - 1].x*line - (razmer_used/2*line) + (line/8), line - (line/4), line - (line/4), *transparentpen, *grayBrush);
        old_hero.pop_back();
    }*/


    item_hero->setPos(hero.y*line - (razmer_used/2*line) + (line/8) - razmer_h/2, hero.x*line - (razmer_used/2*line) + (line/8));
    item_robot->setPos(robot.y*line - (razmer_used/2*line) + (line/8) + razmer_h/2, robot.x*line - (razmer_used/2*line) + (line/8));

    //scene->setSceneRect(hero.y*line - (razmer_used/2*line) + (line/8), hero.y*line - (razmer_used/2*line) + (line/8), line, line);
    //scene->addRect(hero.y*line - (razmer_used/2*line) + (line/8), hero.x*line - (razmer_used/2*line) + (line/8), line - (line/4), line - (line/4), *transparentpen, *redBrush);
    //ui->graphicsView->setScene(scene);

}

void game::keyPressEvent(QKeyEvent *event)
{
    ui->statusbar->showMessage("log: Нажата клавиша: " + QString::number(event->key()));
    if ((event->key() == Qt::Key_W) || (event->key() == Qt::Key_Up) || (event->key() == 1062)){
            ui->statusbar->showMessage("log: up");
            move_hero(razmer, -1, 0);
    }
    if ((event->key() == Qt::Key_S) || (event->key() == Qt::Key_Down) || (event->key() == 1067)){
            ui->statusbar->showMessage("log: down");
            move_hero(razmer, 1, 0);
    }
    if ((event->key() == Qt::Key_A) || (event->key() == Qt::Key_Left) || (event->key() == 1060)){
            ui->statusbar->showMessage("log: left");
            move_hero(razmer, 0, -1);
    }
    if ((event->key() == Qt::Key_D) || (event->key() == Qt::Key_Right) || (event->key() == 1042)){
            ui->statusbar->showMessage("log: right");
            move_hero(razmer, 0, 1);
    }
    if (event->key() == 16777220){
        //Reset_Scene();
        ui->pushButton_2->click();
    }
    if (event->key() == 32){
        //Reset_Scene();
        ui->pushButton_3->click();
    }
}

void game::on_pushButton_3_clicked()
{
    this->setFocus();
    ui->pushButton_3->setEnabled(false);

    time_timer = 0;
    ui->pushButton_2->setEnabled(true);
    timer_paint->stop();
    timer_fps->stop();
    robot_time->stop();
    for (int i = 0; i < razmer; i++){
        for (int j = 0; j < razmer; j++){
            labirint[i][j] = 0;
            if((i == 0) || (j == 0) || (i == (razmer - 1)) || (j == (razmer - 1))){
                visible[i][j] = true;
            }else{
                visible[i][j] = false;
            }
        }
    }

    int rand_start = randomBetween(1 , (razmer/2 )) * 2 - 1;
    labirint[rand_start][1] = 1;
    visible[rand_start][1] = true;
    fout << "Генерация с клетки: " << rand_start << " 1" << endl;

    clock_t start, end;
    start = clock();
    mole(razmer, rand_start, 1);
    end = clock();

    input.x = rand_start;
    input.y = 0;
    labirint[input.x][input.y] = 1;
    hero = input;
    robot = input;
    counter_robot = 0;

    seach_exit(razmer);

    Reset_Scene();

    timer_paint->start(10);

    vector<vector<int>> list = Convert(razmer);
    fout << "log: Convert" << endl;
    vector<int> sweets = Sweet_cell(list, razmer);
    fout << "log: Sweet_cell" << endl;
    road = Seach_road(sweets, list, razmer, robot.x, robot.y, output.x, output.y);

    for (int i = 0; i < road.size(); i++){
        fout << road[i] << "  ";
    }
    fout << endl;
    //ui->statusbar->showMessage("Время генерации лабиринта: " + QString::number(difftime(end, start)));
    fout << "Время генерации: " << difftime(end, start) << endl;

    timer_fps->start(1000);
    robot_time->start(300);

    ui->pushButton_3->setEnabled(true);
}
