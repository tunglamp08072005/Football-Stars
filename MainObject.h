#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "Common_function.h"
#include "Ball.h"

#define WIDTH_MAIN_OBJECT 71
#define HEIGHT_MAIN_OBJECT 93

class MainObject : public BaseObject {
public:
    MainObject();
    ~MainObject();

    void HandleInputAction(SDL_Event events);
    void HandleMove();
    void Show(SDL_Surface* des);

    bool CheckCollision(SDL_Rect a, SDL_Rect b);
    void HandleBallCollision(Ball& ball);
    void KickBall(Ball& ball);
    void HandleMoveWithGoalLimit();
    void HandleMoveWithGoalLimit02();
private:
    int x_val;
    int y_val;
    bool isMovingUp;
    bool isMovingDown;
    bool isMovingLeft;
    bool isMovingRight;
};

#endif // MAIN_OBJECT_H_
