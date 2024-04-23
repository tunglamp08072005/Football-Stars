#ifndef KHUNGTHANH_H_INCLUDED_2
#define KHUNGTHANH_H_INCLUDED_2

#include "ball.h"
#include "Common_function.h"
#include "MainObject.h"
#include "MainObject(02).h"

class KhungThanh02 {
public:
    static bool CheckCollision(Ball& ball, MainObject& main_object, MainObject02& main_object02);
    static void ResetPosition(Ball& ball, MainObject& main_object, MainObject02& main_object02);
    static void StopBall(Ball& ball);
};

#endif // KHUNGTHANH_H_INCLUDED_2
