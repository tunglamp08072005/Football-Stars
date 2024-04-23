#ifndef BALL_H_
#define BALL_H_

#include "baseObject.h"
#define BALL_SPEED 2

class Ball : public BaseObject {
public:
    Ball();
    ~Ball();

    void HandleMove();
    void SetRect(int x, int y) { rect_.x = x; rect_.y = y; }
    void Show(SDL_Surface* des);
    void SetMoveXVal(const int& val) { x_val += val; }
    void SetMoveYVal(const int& val) { y_val += val; }
    SDL_Rect GetRect() const { return rect_; }

private:
    int x_val = 0;
    int y_val = 0;
    bool is_attached = false;
};

#endif // BALL_H_
