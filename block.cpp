#include "block.h"
#include <QDebug>

Block::Block(int x, int y, QString name)
{
    mapX = 50;
    mapY = 50;
    width = 50;
    height = 50;
    blockPos = fixPos(x, y);
    posX = blockPos.firstKey();
    posY = blockPos.first();
    imageName = name;
}

QMap<int, int> Block::fixPos(int posX, int posY)
{
    QMap<int, int> pos;
    int x = mapX + (posX / 50 - 1) * width;
    int y = mapY + (posY / 50 - 1) * height;
    pos[x] = y;
    return pos;
}


