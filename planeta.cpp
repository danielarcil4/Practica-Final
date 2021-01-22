#include "planeta.h"

float Planeta::getVx() const
{
    return Vx;
}

void Planeta::setVx(float value)
{
    Vx = value;
}

float Planeta::getVy() const
{
    return Vy;
}

void Planeta::setVy(float value)
{
    Vy = value;
}

double Planeta::getAngulo() const
{
    return angulo;
}

void Planeta::setAngulo(double value)
{
    angulo = value;
}

double Planeta::getDistancia() const
{
    return distancia;
}

void Planeta::setDistancia(double value)
{
    distancia = value;
}

double Planeta::getAx() const
{
    return ax;
}

void Planeta::setAx(double value)
{
    ax = value;
}

double Planeta::getAy() const
{
    return ay;
}

void Planeta::setAy(double value)
{
    ay = value;
}

double Planeta::getVx0() const
{
    return Vx0;
}

void Planeta::setVx0(double value)
{
    Vx0 = value;
}

double Planeta::getVy0() const
{
    return Vy0;
}

void Planeta::setVy0(double value)
{
    Vy0 = value;
}

Planeta::Planeta(int r_)
{
    r = r_;
}

QRectF Planeta::boundingRect() const
{
    return QRectF(-r,-r,r*2,r*2);
}

void Planeta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(r==20)
        painter->setBrush(Qt::yellow);
    else
        painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}
