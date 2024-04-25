#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include <SDL.h>
#include <string>

class BaseObject {
public:
    BaseObject();
    ~BaseObject();
    void Show(SDL_Surface* des);
    bool LoadIMG(const char* file_name);
    void load_p_object(SDL_Surface* _p_object);

    void SetRect(const int& x, const int& y) { rect_.x = x; rect_.y = y;}
    void SetWH(const int& w, const int& h) { rect_.w = w; rect_.h = h;}
    SDL_Rect GetRect() const { return rect_; }
    SDL_Surface* GetObject() { return p_object_; }
public:
    SDL_Rect rect_;
    SDL_Surface* p_object_;
};

#endif // BASE_OBJECT_H_
