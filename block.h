#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QMap>
/***
 * 砖块类：用于显示图片
 * */

class Block
{
public:
    Block(int x, int y, QString name);

    int mapX;
    int mapY;
    int posX;
    int posY;
    QString imageName;
    int width;
    int height;

    QMap<int, int> fixPos(int posX, int posY);
    QMap<int, int> blockPos;
};

#endif // BLOCK_H
