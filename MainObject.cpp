#include "MainObject.h"
#include "Common_function.h"
#include <iostream>
#include<cmath>

const int MAX_SPEED = 1; // Tốc độ di chuyển tối đa
const int ACCELERATION = 1; // Gia tốc
int x_speed = 0; // Tốc độ di chuyển theo trục x
int y_speed = 0; // Tốc độ di chuyển theo trục y
int jump_timer;
bool is_jumping = false; // Biến để theo dõi trạng thái nhảy của nhân vật



MainObject::MainObject()
{
    rect_.x = SCREEN_WIDTH / 2 - 400;
    rect_.y = SCREEN_HEIGHT / 2 - 100;
    rect_.w = WIDTH_MAIN_OBJECT;
    rect_.h = HEIGHT_MAIN_OBJECT;
    x_val = 0;
    y_val = 0;
    is_kicking = false;
}

MainObject::~MainObject()
{
    // Destructor của MainObject
}

void MainObject::HandleInputAction(SDL_Event events) {
    if (events.type == SDL_KEYDOWN) {
        switch (events.key.keysym.sym) {
            case SDLK_w:
                isMovingUp = true;
                break;
            case SDLK_s:
                isMovingDown = true;
                break;
            case SDLK_a:
                isMovingLeft = true;
                break;
            case SDLK_d:
                isMovingRight = true;
                break;
        }
    } else if (events.type == SDL_KEYUP) {
        switch (events.key.keysym.sym) {
            case SDLK_w:
                isMovingUp = false;
                break;
            case SDLK_s:
                isMovingDown = false;
                break;
            case SDLK_a:
                isMovingLeft = false;
                break;
            case SDLK_d:
                isMovingRight = false;
                break;
        }
    }
}


void MainObject::HandleMove() {
    // Di chuyển nhân vật dựa trên trạng thái của các phím được nhấn
    if (isMovingUp) {
        rect_.y -= MAX_SPEED; // Di chuyển lên
    }
    if (isMovingDown) {
        rect_.y += MAX_SPEED; // Di chuyển xuống
    }
    if (isMovingLeft) {
        rect_.x -= MAX_SPEED; // Di chuyển sang trái
    }
    if (isMovingRight) {
        rect_.x += MAX_SPEED; // Di chuyển sang phải
    }

    // Giới hạn di chuyển của nhân vật trong màn hình
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









void MainObject::Show(SDL_Surface* des)
{
    // Hiển thị nhân vật trên màn hình
    if (p_object_ != NULL) {
        SDL_Rect rect = {rect_.x, rect_.y, rect_.w, rect_.h};
        SDL_BlitSurface(p_object_, NULL, des, &rect);
    }
}

bool MainObject::CheckCollision(SDL_Rect a, SDL_Rect b)
{
    // Kiểm tra xem hai hình chữ nhật có giao nhau hay không
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

void MainObject::HandleBallCollision(Ball& ball) {
    SDL_Rect ball_rect = ball.GetRect(); // Lấy ra hình chữ nhật bao quanh quả bóng

    // Kiểm tra va chạm giữa nhân vật và quả bóng
    if (CheckCollision(rect_, ball_rect)) {
            std::cout << "Va cham" << std::endl;
        // Xác định hướng và khoảng cách giữa trung tâm nhân vật và trung tâm quả bóng
        int dx = (rect_.x + rect_.w / 2) - (ball_rect.x + ball_rect.w / 2);
        int dy = (rect_.y + rect_.h / 2) - (ball_rect.y + ball_rect.h / 2);
        int length = sqrt(dx * dx + dy * dy);

        // Nếu nhân vật va chạm với quả bóng, di chuyển quả bóng đi một đoạn
        if (length < (rect_.w + ball_rect.w) / 2) {
            // Xác định hướng di chuyển của quả bóng dựa trên hướng và tốc độ hiện tại
            int velX = 10; // Giả sử giá trị của velX là 10
            int velY = 20; // Giả sử giá trị của velY là 20
            ball.SetMoveXVal(velX);
            ball.SetMoveYVal(velY);

            // Thiết lập tốc độ mới cho quả bóng
            ball.SetMoveXVal(velX * BALL_SPEED);
            ball.SetMoveYVal(velY * BALL_SPEED);

            // Di chuyển quả bóng một đoạn
            ball.HandleMove();
        }
    }
}










void MainObject::KickBall(Ball& ball)
{
    // Xử lý sút bóng
    if (is_kicking) {
        ball.SetAttached(false);
        is_kicking = false;
    }
}
