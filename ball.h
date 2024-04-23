#ifndef BALL_H_
#define BALL_H_

#include "baseObject.h"
#define BALL_SPEED 1
#define BALL_WIDTH 31
#define BALL_HEIGHT 32

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
    int GetXVal() const { return x_val; }
    int GetYVal() const { return y_val; }
    SDL_Rect GetRect() const { return rect_; }

    // Khai báo phương thức ResetPosition
    void ResetPosition(SDL_Surface* p_object, SDL_Surface* p_object2);
    void Stop();

private:
    int x_val;
    int y_val;
    bool is_attached;
};

#endif // BALL_H_
