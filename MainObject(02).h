#ifndef MAINOBJECT02_H_
#define MAINOBJECT02_H_

#include "Common_function.h"
#include "ball.h"

#define WIDTH_MAIN_OBJECT_2 77
#define HEIGHT_MAIN_OBJECT_2 92

class MainObject02 : public BaseObject{
public:
    MainObject02();
    ~MainObject02();
    void load_p_object2(SDL_Surface* _p_object2);
    void Show(SDL_Surface* des);
    void HandleMove();
    void HandleInputAction(SDL_Event events);
    void HandleMoveWithGoalLimit();
    bool CheckCollision(SDL_Rect a, SDL_Rect b);
    void HandleBallCollision(Ball& ball);
    void HandleMoveWithGoalLimit02();
private:
    int x_val2, y_val2;
    bool isMovingUp;
    bool isMovingDown;
    bool isMovingLeft;
    bool isMovingRight;
};

#endif /* MAINOBJECT02_H_ */
