#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QDebug>
#include "block.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setup();
    bool inMap(int posX, int posY);

protected:
    void paintEvent(QPaintEvent */*event*/);
    void mousePressEvent(QMouseEvent * event);

private:
    Ui::MainWindow *ui;

    QVector<Block> blocks;

    int mapPosX;
    int mapPosY;
    int mapWidth;
    int mapHeight;
    int mapStep;

    QString blockPic;
};
#endif // MAINWINDOW_H
