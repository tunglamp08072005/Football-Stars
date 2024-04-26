#include "khungthanh.h"
#include "Common_function.h"
#include "ball.h"
#include "MainObject.h"
#include "MainObject(02).h"
#include "TextObject.h"

extern int scorePlayer1;
extern int scorePlayer2;

bool KhungThanh::CheckCollision(Ball& ball, MainObject& main_object, MainObject02& main_object02) {
    int ball_x = ball.GetRect().x;
    int ball_y = ball.GetRect().y;
    int ball_w = ball.GetRect().w;
    int ball_h = ball.GetRect().h;
    int ball_x_vel = ball.GetXVal();
    int ball_y_vel = ball.GetYVal();

    if((0 <= ball_x && ball_x <=  GOAL_1_X + goal_surface->w)  && (0 <= ball_y && ball_y + BALL_HEIGHT <= GOAL_1_Y))
    {
        if((ball_y + BALL_HEIGHT >= GOAL_1_Y) && (ball_x + BALL_WIDTH <= GOAL_1_X + goal_surface->w))
        {
            ball.SetMoveYVal(-ball_y_vel);
        }
    }
    else if ((0 < ball_x && ball_x <  GOAL_1_X + goal_surface->w) && (GOAL_1_Y <= ball_y && ball_y < GOAL_1_Y + goal_surface->h)) {
        ResetPosition(ball, main_object, main_object02);
        StopBall(ball);
        // Play goal cheering sound effect
        Mix_PlayChannel(-1, gGoalCheeringSound, 0);
        scorePlayer2++;
        std::string newScore = std::to_string(scorePlayer1) + " : " + std::to_string(scorePlayer2);
        scoreText.SetText(newScore);
        return true;
    }
    else
    {
        if((ball_y <= GOAL_1_Y + goal_surface->h) && (0 <= ball_x && ball_x <=  GOAL_1_X + goal_surface->w))
        {
            ball.SetMoveYVal(-ball_y_vel);
        }
    }
    return false;
}

void KhungThanh::ResetPosition(Ball& ball, MainObject& main_object, MainObject02& main_object02) {
    ball.SetRect(SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT / 2 - 25);
    main_object.SetRect(SCREEN_WIDTH / 2 - 400, SCREEN_HEIGHT / 2 - 100);
    main_object02.SetRect(SCREEN_WIDTH / 2 + 300, SCREEN_HEIGHT / 2 - 100);
}

void KhungThanh::StopBall(Ball& ball) {
    ball.SetMoveXVal(0);
    ball.SetMoveYVal(0);
}
