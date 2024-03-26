#include "Ball.h"
#include "Common_function.h"

Ball::Ball() {
    rect_.x = SCREEN_WIDTH / 2 - 25;
    rect_.y = SCREEN_HEIGHT / 2 - 25;
    rect_.w = 31;
    rect_.h = 32;
    x_val = 0;
    y_val = 0;
    is_attached = true; // Bắt đầu với việc quả bóng được gắn vào người chơi
}

Ball::~Ball() {
    // Destructor của Ball
}

void Ball::HandleMove() {
    if (!is_attached) {
        // Nếu quả bóng không được gắn vào người chơi, di chuyển nó tự do
        rect_.x += x_val;
        rect_.y += y_val;

        // Xử lý khi quả bóng chạm vào biên của cửa sổ
        if (rect_.x < 0) {
            rect_.x = 0;
            x_val = -x_val; // Đổi hướng di chuyển theo chiều ngang
        } else if (rect_.x + rect_.w > SCREEN_WIDTH) {
            rect_.x = SCREEN_WIDTH - rect_.w;
            x_val = -x_val; // Đổi hướng di chuyển theo chiều ngang
        }

        if (rect_.y < 0) {
            rect_.y = 0;
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

void Ball::SetAttached(bool attached) {
    is_attached = attached;
    if (attached) {
        // Nếu quả bóng được gắn vào người chơi, đặt lại vị trí ở giữa màn hình
        rect_.x = SCREEN_WIDTH / 2 - 25;
        rect_.y = SCREEN_HEIGHT / 2 - 25;
    }
}

void Ball::HandleInputAction(SDL_Event events) {
    // Xử lý sự kiện từ bàn phím và chuột (nếu cần)
    if (events.type == SDL_KEYDOWN) {
        // Xử lý khi có phím được nhấn
        switch (events.key.keysym.sym) {
            // Xử lý các phím tương ứng
            case SDLK_UP:
                // Xử lý khi phím mũi tên lên được nhấn
                break;
            case SDLK_DOWN:
                // Xử lý khi phím mũi tên xuống được nhấn
                break;
            // Thêm các trường hợp xử lý cho các phím khác (nếu cần)
        }
    } else if (events.type == SDL_KEYUP) {
        // Xử lý khi có phím được thả ra
        switch (events.key.keysym.sym) {
            // Xử lý các phím tương ứng (nếu cần)
        }
    } else if (events.type == SDL_MOUSEBUTTONDOWN) {
        // Xử lý khi chuột được nhấn (nếu cần)
    } else if (events.type == SDL_MOUSEBUTTONUP) {
        // Xử lý khi chuột được thả ra (nếu cần)
    }
    // Xử lý các sự kiện khác (nếu cần)
}
