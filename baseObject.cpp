#include "baseObject.h"

BaseObject::BaseObject() {
    rect_.x = 0;
    rect_.y = 0;
    p_object_ = NULL;
}

BaseObject::~BaseObject() {
    if (p_object_ != NULL) {
        // Lưu ý: không thể sử dụng delete cho SDL_Surface, chỉ cần giải phóng bộ nhớ
        SDL_FreeSurface(p_object_);
        p_object_ = NULL;
    }
}

bool BaseObject::LoadIMG(const char* file_name) {
    // Hãy chắc chắn rằng SDL đã được khởi tạo trước khi gọi hàm này
    p_object_ = SDL_LoadBMP(file_name);
    if (p_object_ == NULL) return false;
    return true;
}

void BaseObject::Show(SDL_Surface* des) {
    // Kiểm tra xem hình ảnh đã được tải lên chưa
    if (p_object_ != NULL) {
        SDL_Rect rect = {rect_.x, rect_.y, rect_.w, rect_.h};
        SDL_BlitSurface(p_object_, NULL, des, &rect);
    }
}

void BaseObject::load_p_object(SDL_Surface* _p_object){
    p_object_ = _p_object;
}
