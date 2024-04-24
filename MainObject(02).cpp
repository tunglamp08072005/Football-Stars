#include "MainObject(02).h"
#include "Common_function.h"
#include "khungthanh(02).h"
#include "khungthanh.h"
#include<cmath>

MainObject02::MainObject02() {
    rect_.x = SCREEN_WIDTH / 2 + 300;
    rect_.y = SCREEN_HEIGHT / 2 - 100;
    rect_.w = WIDTH_MAIN_OBJECT_2;
    rect_.h = HEIGHT_MAIN_OBJECT_2;
    x_val2 = MAX_SPEED;
    y_val2 = MAX_SPEED;
    isMovingUp = false;
    isMovingDown = false;
    isMovingLeft = false;
    isMovingRight = false;
}

MainObject02::~MainObject02() {

}

void MainObject02::load_p_object2(SDL_Surface* _p_object2) {
    p_object_ = _p_object2;
}

void MainObject02::HandleInputAction(SDL_Event events) {
    if (events.type == SDL_KEYDOWN) {
        switch (events.key.keysym.sym) {
            case SDLK_UP:
                isMovingUp = true;
                break;
            case SDLK_DOWN:
                isMovingDown = true;
                break;
            case SDLK_LEFT:
                isMovingLeft = true;
                break;
            case SDLK_RIGHT:
                isMovingRight = true;
                break;
        }
    } else if (events.type == SDL_KEYUP) {
        switch (events.key.keysym.sym) {
            case SDLK_UP:
                isMovingUp = false;
                break;
            case SDLK_DOWN:
                isMovingDown = false;
                break;
            case SDLK_LEFT:
                isMovingLeft = false;
                break;
            case SDLK_RIGHT:
                isMovingRight = false;
                break;
        }
    }
}

void MainObject02::HandleMove() {
    if (isMovingUp) {
        rect_.y -= MAX_SPEED;
    }
    if (isMovingDown) {
        rect_.y += MAX_SPEED;
    }
    if (isMovingLeft) {
        rect_.x -= MAX_SPEED;
    }
    if (isMovingRight) {
        rect_.x += MAX_SPEED;
    }

    if (rect_.x < 0) {
        rect_.x = 0;
    } else if (rect_.x + rect_.w > SCREEN_WIDTH) {
        rect_.x = SCREEN_WIDTH - rect_.w;
    }

    if (rect_.y < 0) {
        rect_.y = 0;
    } else if (rect_.y + rect_.h > SCREEN_HEIGHT) {
        rect_.y = SCREEN_HEIGHT - rect_.h;
    }
}

void MainObject02::HandleMoveWithGoalLimit()
{
    if (rect_.x < GOAL_1_X + goal_surface->w) {
        rect_.x = GOAL_1_X + goal_surface->w;
    } else if (rect_.x >= 0 && rect_.x <= GOAL_1_X + goal_surface->w &&
               rect_.y < GOAL_1_Y) {
        if (rect_.x + rect_.w <= GOAL_1_X + goal_surface->w) {
            rect_.y = GOAL_1_Y - rect_.h;
        }
    } else if (rect_.x >= 0 && rect_.x <= GOAL_1_X + goal_surface->w &&
               rect_.y + rect_.h > GOAL_1_Y + goal_surface->h) {
        if (rect_.x + rect_.w <= GOAL_1_X + goal_surface->w) {
            rect_.y = GOAL_1_Y + goal_surface->h;
        }
    }
}

void MainObject02::Show(SDL_Surface* des) {
    if (p_object_ != NULL) {
        SDL_Rect rect2 = {rect_.x, rect_.y, rect_.w, rect_.h};
        SDL_BlitSurface(p_object_, NULL, des, &rect2);
    }
}

bool MainObject02::CheckCollision(SDL_Rect a, SDL_Rect b)
{
    int left_a = a.x;
    int right_a = a.x + a.w;
    int top_a = a.y;
    int bottom_a = a.y + a.h;

    int left_b = b.x;
    int right_b = b.x + b.w;
    int top_b = b.y;
    int bottom_b = b.y + b.h;

    if (left_a >= right_b || right_a <= left_b || top_a >= bottom_b || bottom_a <= top_b)
        return false;

    return true;
}

void MainObject02::HandleBallCollision(Ball& ball) {
    SDL_Rect ball_rect2 = ball.GetRect();

    if (CheckCollision(rect_, ball_rect2)) {
        int x1 = rect_.x + rect_.w / 2;
        int y1 = rect_.y + rect_.h / 2;
        int x2 = ball_rect2.x + ball_rect2.w / 2;
        int y2 = ball_rect2.y + ball_rect2.h / 2;

        int dx = x2 - x1;
        int dy = y2 - y1;

        float distance = sqrt(dx * dx + dy * dy);

        if (distance > 0) {
            float character_speed_x2 = MAX_SPEED;
            float charact_speed_y2 = MAX_SPEED;
            float ball_new_speed_x2 = character_speed_x2 * abs(dx) / dx;
            float ball_new_speed_y2 = charact_speed_y2 * abs(dy) / (dy);

            ball.SetMoveXVal(ball_new_speed_x2);
            ball.SetMoveYVal(ball_new_speed_y2);

            ball.HandleMove();

            Mix_PlayChannel(-1, gSoccerKickSound, 0);
        }
    }
}

void MainObject02::HandleMoveWithGoalLimit02()
{
    if (rect_.x + rect_.w >= GOAL_2_X) {
        rect_.x = GOAL_2_X - rect_.w;
    } else if (rect_.x + rect_.w<= SCREEN_WIDTH && rect_.x + rect_.w > GOAL_2_X && rect_.y + rect_.h < GOAL_2_Y && rect_.x + rect_.w >= GOAL_2_X + goal02_surface->w) {
        if (rect_.x + rect_.w >= GOAL_2_X) {
            rect_.y = GOAL_2_Y - rect_.h;
        }
    } else if (rect_.x + rect_.w <= SCREEN_WIDTH && rect_.x + rect_.w > GOAL_2_X && rect_.y + rect_.h > GOAL_2_Y + goal02_surface->h) {
        if (rect_.y > GOAL_2_Y + goal02_surface->h) {
            rect_.y = GOAL_2_Y + goal02_surface->h;
        }
    }
}
