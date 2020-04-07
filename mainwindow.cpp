#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup()
{
    mapStep = 50;
    mapPosX = 50;
    mapPosY = 50;
    mapWidth = 200;
    mapHeight = 200;

    blockPic = ":/img/block.png";

    ui->label->setText(QString("地图规格：%1 x %2").arg(mapWidth).arg(mapHeight));
    ui->label->resize(400, 100);
}

void MainWindow::paintEvent(QPaintEvent */*event*/)
{
    int step = mapStep;
    int w = mapWidth;
    int h = mapHeight;
    int x = mapPosX;
    int y = mapPosY;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    for (int i = 0; i < 5; i++) {
        if (x + step * i > x + w) {
            break;
        }
        painter.drawLine(QPointF(x + step * i, y), QPointF(x + step * i, y+ h));
    }

    for (int j = 0; j < 5; j++) {
        if (y + step * j > y + h) {
            break;
        }
        painter.drawLine(QPointF(x, y + step * j), QPointF(x + w, y + step * j));
    }

    QPixmap pix;
    for (auto b : blocks) {
        QString img = b.imageName;
        pix.load(img);
        painter.drawPixmap(b.posX, b.posY, b.width, b.height, pix);
    }

    pix.load(":/img/block.png");
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    int posX = e->pos().x();
    int posY = e->pos().y();

    Block *b1 = new Block(posX, posY, blockPic);
    if (inMap(posX, posY) && blocks.size() < 20) {
        blocks.push_back(*b1);
        update();
    }
}

bool MainWindow::inMap(int posX, int posY) {
    int x = mapPosX;
    int y = mapPosY;
    int w = mapWidth;
    int h = mapHeight;

    return ((posX >= x) && (posY >= y)) &&
            ((posX <= w + x) && (posY <= h + y)) ;
}

