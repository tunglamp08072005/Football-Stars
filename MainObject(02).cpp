#include "MainObject(02).h"
#include "Common_function.h"
#include "khungthanh(02).h"
#include "khungthanh.h"
#include<cmath>

MainObject02::MainObject02() {
    rect_.x = SCREEN_WIDTH / 2 + 300;
    rect_.y = SCREEN_HEIGHT / 2 - 100;
    rect_.w = WIDTH_MAIN_OBJECT_2; // Chiều rộng của hình ảnh nhân vật 2
    rect_.h = HEIGHT_MAIN_OBJECT_2; // Chiều cao của hình ảnh nhân vật 2
    x_val2 = MAX_SPEED; // Tốc độ di chuyển theo chiề ngang của nhân vật 2
    y_val2 = MAX_SPEED; // Tốc độ di chuyển theo chiều dọc của nhân vật 2
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

void MainObject02::HandleMoveWithGoalLimit()
{
     // Xác định các giới hạn của khung thành
    if (rect_.x < GOAL_1_X + goal_surface->w) {
        // Nhân vật đi vào trong khung thành
        rect_.x = GOAL_1_X + goal_surface->w;
    } else if (rect_.x >= 0 && rect_.x <= GOAL_1_X + goal_surface->w &&
               rect_.y < GOAL_1_Y) {
        // Nhân vật ở bên ngoài lưới ở trên
        if (rect_.x + rect_.w <= GOAL_1_X + goal_surface->w) {
            rect_.y = GOAL_1_Y - rect_.h;
        }
    } else if (rect_.x >= 0 && rect_.x <= GOAL_1_X + goal_surface->w &&
               rect_.y + rect_.h > GOAL_1_Y + goal_surface->h) {
        // Nhân vật ở bên ngoài lưới ở dưới
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

void MainObject02::HandleBallCollision(Ball& ball) {
    SDL_Rect ball_rect2 = ball.GetRect(); // Lấy ra hình chữ nhật bao quanh quả bóng

    // Kiểm tra va chạm giữa nhân vật và quả bóng
    if (CheckCollision(rect_, ball_rect2)) {
        // Xác định tâm của hình chữ nhật bao quanh nhân vật và quả bóng
        int x1 = rect_.x + rect_.w / 2;
        int y1 = rect_.y + rect_.h / 2;
        int x2 = ball_rect2.x + ball_rect2.w / 2;
        int y2 = ball_rect2.y + ball_rect2.h / 2;

        // Tính toán hướng di chuyển của quả bóng dựa trên vị trí va chạm
        int dx = x2 - x1;
        int dy = y2 - y1;

        // Tính toán độ dài của vectơ va chạm
        float distance = sqrt(dx * dx + dy * dy);

        // Xác định hướng và tốc độ mới của quả bóng sau va chạm
        if (distance > 0) {
            float character_speed_x2 = MAX_SPEED; // Tốc độ của nhân vật
            float charact_speed_y2 = MAX_SPEED;
            float ball_new_speed_x2 = character_speed_x2 * abs(dx) / dx;
            float ball_new_speed_y2 = charact_speed_y2 * abs(dy) / (dy);

            // Áp dụng hướng và tốc độ mới cho quả bóng
            ball.SetMoveXVal(ball_new_speed_x2);
            ball.SetMoveYVal(ball_new_speed_y2);

            // Di chuyển quả bóng theo hướng và tốc độ mới tính toán được
            ball.HandleMove();

            // Phát âm thanh soccer-kick.mp3
            Mix_PlayChannel(-1, gSoccerKickSound, 0); // -1 để sử dụng kênh âm thanh đầu tiên có sẵn
        }
    }
}

void MainObject02::HandleMoveWithGoalLimit02()
{
     // Xác định các giới hạn của khung thành
    if (rect_.x + rect_.w >= GOAL_2_X) {
        // Đặt lại vị trí nhân vật 2 nếu va chạm với khung thành 2
        rect_.x = GOAL_2_X - rect_.w;
    } else if (rect_.x + rect_.w<= SCREEN_WIDTH && rect_.x + rect_.w > GOAL_2_X && rect_.y + rect_.h < GOAL_2_Y && rect_.x + rect_.w >= GOAL_2_X + goal02_surface->w) {
        // Nhân vật ở bên ngoài lưới ở trên
        if (rect_.x + rect_.w >= GOAL_2_X) {
            rect_.y = GOAL_2_Y - rect_.h;
        }
    } else if (rect_.x + rect_.w <= SCREEN_WIDTH && rect_.x + rect_.w > GOAL_2_X && rect_.y + rect_.h > GOAL_2_Y + goal02_surface->h) {
        // Nhân vật ở bên ngoài lưới ở dưới
        if (rect_.y > GOAL_2_Y + goal02_surface->h) {
            rect_.y = GOAL_2_Y + goal02_surface->h;
        }
    }
}
