#include "TextObject.h"
#include "Common_function.h"

TextObject::TextObject()
{

}

TextObject::~TextObject()
{

}

void TextObject::SetColor(const int& type)
{
    if(type == RED_TEXT)
    {
        SDL_Color color = {255, 0, 0};
        text_color_ = color;
    }
    else if(type == WHITE_TEXT)
    {
        SDL_Color color = {255, 255, 255};
        text_color_ = color;
    }
    else
    {
        SDL_Color color = {0, 0, 0};
        text_color_ = color;
    }
}

void TextObject::CreateGameText(SDL_Surface* des) {
    SDL_Surface *_p_object_ = TTF_RenderText_Solid(font_, str_val_.c_str(), text_color_);
    this->SetWH(_p_object_->w, _p_object_->h);
    if (_p_object_ == nullptr) {
        printf("Failed to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    } else {
        SDLCommonFunc::ApplySurface(_p_object_, des, x_, y_);
        SDL_FreeSurface(_p_object_);
    }
}

void TextObject::SetPosition(int x, int y){
    x_ = x;
    y_ = y;
    this->SetRect(x_, y_);
}


