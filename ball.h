#ifndef BALL_H_
#define BALL_H_

#include "baseObject.h"
#define BALL_SPEED 5

class Ball : public BaseObject {
public:
    Ball();
    ~Ball();

    void HandleMove();
    void SetRect(int x, int y) { rect_.x = x; rect_.y = y; }
    void HandleInputAction(SDL_Event events);
    void Show(SDL_Surface* des);
    void SetAttached(bool attached);
    void SetMoveXVal(const int& val) { x_val = val; }
    void SetMoveYVal(const int& val) { y_val = val; }
    SDL_Rect GetRect() const { return rect_; }

private:
    int x_val;
    int y_val;
    bool is_attached;
};

#endif // BALL_H_
