#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include <SDL.h>
#include <string>

class BaseObject {
public:
    BaseObject();
    ~BaseObject();
    void Show(SDL_Surface* des);
    bool LoadIMG(const char* file_name); // Sửa đổi từ const string& thành const char*
    void load_p_object(SDL_Surface* _p_object);
    void load_p_object2(SDL_Surface* _p_object);
    void SetRect(const int& x, const int& y) { rect_.x = x; rect_.y = y;}
    void SetRect2(const int& x2, const int& y2) { rect_2.x = x2; rect_2.y = y2; }
    SDL_Rect GetRect() const { return rect_; }
    SDL_Surface* GetObject() { return p_object_, return p_object; } // Sửa đổi từ SDL_Surface thành SDL_Surface*
public:
    SDL_Rect rect_;
    SDL_Surface* p_object_;
};

#endif // BASE_OBJECT_H_
