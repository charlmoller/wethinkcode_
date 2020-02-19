#include "Collider.hpp"

Collider::Collider()
{
    active = 0;
}

Collider::~Collider() {}

int Collider::getActive(void)
{
    return active;
}

void Collider::toggleActive(void)
{
    active = active ? 0 : 1;
}

void Collider::activate(float yp, float xp, float yvp, float xvp)
{
    active = 1;
    y = yp;
    x = xp;
    yv = yvp;
    xv = xvp;
}

float Collider::getX(void)
{
    return x;
}

float Collider::getY(void)
{
    return y;
}

void Collider::update(void)
{
    y += yv;
    x += xv;
}

void Collider::setPos(float py, float px)
{
    y = py;
    x = px;
}

void Collider::setVel(float y, float x)
{
    yv = y;
    xv = x;
}

Collider::Collider(const Collider& cc)
{
    x = cc.x;
}
Collider& Collider::operator=(const Collider& cc)
{
    x = cc.x;
    return *this;
}