#ifndef KHUNGTHANH_H_INCLUDED
#define KHUNGTHANH_H_INCLUDED

#include "ball.h"
#include "Common_function.h"
#include "MainObject.h"
#include "MainObject(02).h"

class KhungThanh {
public:
    static bool CheckCollision(Ball& ball, MainObject& main_object, MainObject02& main_object02);
    static void ResetPosition(Ball& ball, MainObject& main_object, MainObject02& main_object02);
    static void StopBall(Ball& ball);
};

#endif // KHUNGTHANH_H_INCLUDED
