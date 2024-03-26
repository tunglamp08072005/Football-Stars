#include "MainObject(02).h"

MainObject02::MainObject02() {
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 77; // Width của nv2.png
    rect_.h = 92; // Height của nv2.png
    p_object_ = NULL;
}

MainObject02::~MainObject02() {
    if (p_object_ != NULL) {
        SDL_FreeSurface(p_object_);
        p_object_ = NULL;
    }
}

void MainObject02::load_p_object(SDL_Surface* _p_object) {
    p_object_ = _p_object;
}

void MainObject02::Show(SDL_Surface* des) {
    if (p_object_ != NULL) {
        SDL_Rect rect = {rect_.x, rect_.y, rect_.w, rect_.h};
        SDL_BlitSurface(p_object_, NULL, des, &rect);
    }
}
