#include "ball.h"
#include "Common_function.h"

Ball::Ball() {
    rect_.x = SCREEN_WIDTH / 2 - 25;
    rect_.y = SCREEN_HEIGHT / 2 - 25;
    rect_.w = BALL_WIDTH;
    rect_.h = BALL_HEIGHT;
    x_val = 0;
    y_val = 0;
}

Ball::~Ball() {
    // Destructor của Ball
}

void Ball::HandleMove() {
    if (!is_attached) {

        rect_.x += x_val * BALL_SPEED;
        rect_.y += y_val * BALL_SPEED;

        // Xử lý khi quả bóng chạm vào biên của cửa sổ
        if (rect_.x <= 0) {
            //rect_.x = 0;
            x_val = -x_val; // Đổi hướng di chuyển theo chiều ngang
        } else if (rect_.x + rect_.w > SCREEN_WIDTH) {
            rect_.x = SCREEN_WIDTH - rect_.w;
            x_val = -x_val; // Đổi hướng di chuyển theo chiều ngang
        }

        if (rect_.y <= 0) {
            //rect_.y = 0;
            y_val = -y_val; // Đổi hướng di chuyển theo chiều dọc
        } else if (rect_.y + rect_.h > SCREEN_HEIGHT) {
            rect_.y = SCREEN_HEIGHT - rect_.h;
            y_val = -y_val; // Đổi hướng di chuyển theo chiều dọc
        }
    }
}


void Ball::Show(SDL_Surface* des) {
    if (p_object_ != NULL) {
        SDL_Rect rect = {rect_.x, rect_.y, rect_.w, rect_.h};
        SDL_BlitSurface(p_object_, NULL, des, &rect);
    }
}

void Ball::ResetPosition(SDL_Surface* p_object, SDL_Surface* p_object2) {
    // Đặt lại vị trí ban đầu của quả bóng
    rect_.x = SCREEN_WIDTH / 2 - 25;
    rect_.y = SCREEN_HEIGHT / 2 - 25;
}



// Phương thức để dừng quả bóng
void Ball::Stop() {
    // Dừng quả bóng bằng cách đặt tốc độ di chuyển về 0
    x_val = 0;
    y_val = 0;
}
