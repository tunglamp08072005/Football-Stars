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
        BLACK_TEXT = 2, // Đổi tên của RED_TEXT thành BLACK_TEXT để tránh lỗi trùng lặp
    };
    TextObject();
    ~TextObject();

    void SetText(const std::string& text) { str_val_ = text; }
    void SetColor(const int& type);
    void CreateGameText(SDL_Surface* des);

    // Thêm các biến thành viên để lưu trữ font và vị trí
    void SetFont(TTF_Font* font) { font_ = font; }
    void SetPosition(int x, int y);

private:
    std::string str_val_;
    SDL_Color text_color_;

    // Thêm các biến thành viên để lưu trữ font và vị trí
    TTF_Font* font_; // Con trỏ tới font
    int x_;           // Vị trí X
    int y_;           // Vị trí Y
    int w_;
    int h_;
};

#endif // TEXT_OBJECT_H_

