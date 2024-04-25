#ifndef TEXT_OBJECT_H_
#define TEXT_OBJECT_H_

#include "baseObject.h"
#include <string>
#include <SDL_ttf.h>

class TextObject : public BaseObject
{
public:
    enum TextColor
    {
        RED_TEXT = 0,
        WHITE_TEXT = 1,
        BLACK_TEXT = 2,
    };
    TextObject();
    ~TextObject();

    void SetText(const std::string& text) { str_val_ = text; }
    void SetColor(const int& type);
    void CreateGameText(SDL_Surface* des);

    void SetFont(TTF_Font* font) { font_ = font; }
    void SetPosition(int x, int y);

private:
    std::string str_val_;
    SDL_Color text_color_;

    TTF_Font* font_;
    int x_;
    int y_;
    int w_;
    int h_;
};

#endif // TEXT_OBJECT_H_

