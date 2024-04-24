#include "khungthanh(02).h"
#include "Common_function.h"
#include "ball.h"
#include "MainObject.h"
#include "MainObject(02).h"

extern int scorePlayer1;
extern int scorePlayer2;

bool KhungThanh02::CheckCollision(Ball& ball, MainObject& main_object, MainObject02& main_object02) {
    int ball_x = ball.GetRect().x;
    int ball_y = ball.GetRect().y;
    int ball_w = ball.GetRect().w;
    int ball_h = ball.GetRect().h;
    int ball_x_vel = ball.GetXVal();
    int ball_y_vel = ball.GetYVal();
    if((ball_x <= SCREEN_WIDTH && ball_x >= GOAL_2_X) && (0 <= ball_y && ball_y + BALL_HEIGHT <= GOAL_2_Y))
    {
        if((ball_x >= GOAL_2_X) && (ball_y + BALL_HEIGHT >= GOAL_2_Y))
        {
            ball.SetMoveYVal(-ball_y_vel);
        }
    }
    else if ((ball_x <= SCREEN_WIDTH && ball_x >= GOAL_2_X)&& (ball_y >= GOAL_2_Y + goal02_surface->h && ball_y + BALL_HEIGHT <= SCREEN_HEIGHT))
    {
        if((ball_y <= GOAL_2_Y + goal02_surface->h) && (ball_x <= SCREEN_WIDTH && ball_x >= GOAL_2_X))
        {
            ball.SetMoveYVal(-ball_y_vel);
        }
    }
    else if((ball_x < SCREEN_WIDTH && ball_x > GOAL_2_X) && (GOAL_2_Y <= ball_y && ball_y <= GOAL_2_Y + goal02_surface->h))
    {
        ResetPosition(ball, main_object, main_object02);
        StopBall(ball);
        // Play goal cheering sound effect
        Mix_PlayChannel(-1, gGoalCheeringSound, 0);
        scorePlayer1++;
        std::string newScore = std::to_string(scorePlayer1) + " : " + std::to_string(scorePlayer2);
        scoreText.SetText(newScore);
        return true;
    }
    return false;
}

void KhungThanh02::ResetPosition(Ball& ball, MainObject& main_object, MainObject02& main_object02) {
    ball.SetRect(SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT / 2 - 25);
    main_object.SetRect(SCREEN_WIDTH / 2 - 400, SCREEN_HEIGHT / 2 - 100);
    main_object02.SetRect(SCREEN_WIDTH / 2 + 300, SCREEN_HEIGHT / 2 - 100);
}



void KhungThanh02::StopBall(Ball& ball) {
    ball.SetMoveXVal(0);
    ball.SetMoveYVal(0);
}
