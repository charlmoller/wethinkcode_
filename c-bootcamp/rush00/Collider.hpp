#ifndef COLLIDER_HPP
#define COLLIDER_HPP

class Collider {
private:
    float x;
    float y;
    float xv;
    float yv;
    int active;

public:
    int getActive(void);
    void toggleActive(void);
    void activate(float yp, float xp, float yvp, float xvp);
    float getX(void);
    float getY(void);
    void setPos(float y, float x);
    void setVel(float y, float x);
    void update(void);
    Collider();
    ~Collider();
    Collider(const Collider& cc);
    Collider& operator=(const Collider& cc);
};

#endif