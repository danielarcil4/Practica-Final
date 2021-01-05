#ifndef PLANETA_H
#define PLANETA_H

#include <QGraphicsEllipseItem>
#include <QPainter>

class Planeta: public QGraphicsEllipseItem
{
    int r;
    double angulo,distancia,ax,ay,Vx,Vy,Vx0,Vy0;
public:
    Planeta(int r_);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget = nullptr);

    float getVx() const;
    void setVx(float value);
    float getVy() const;
    void setVy(float value);
    double getAngulo() const;
    void setAngulo(double value);
    double getDistancia() const;
    void setDistancia(double value);
    double getAx() const;
    void setAx(double value);
    double getAy() const;
    void setAy(double value);
    double getVx0() const;
    void setVx0(double value);
    double getVy0() const;
    void setVy0(double value);
};

#endif // PLANETA_H
