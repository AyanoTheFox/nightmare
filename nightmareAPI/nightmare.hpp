#ifndef NIGHTMARE_HPP
#define NIGHTMARE_HPP
//&libaries&//
//%dependeces%//
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
//%system libaries%//
#include <stdio.h>
#include <iostream>
//&class&//
class nightmare
{
public:
    //%main functions%//
    void init(const char* title, int x, int y, int w, int h, bool fullscreen);
    char* getEvents();
    void render();
    int update(const int fps = 60);
    void destroy();
    //%render functions%//
    SDL_Texture* loadImage(const char* path);
    void drawImage(SDL_Texture* texture, int x, int y, int w, int h, int ox = 0, int oy = 0);
    TTF_Font* loadFont(const char* path, const int size);
    void drawText(TTF_Font* font, char* text, int x, int y, int w, int h, int ox = 0, int oy = 0, SDL_Color color = {255, 255, 255});
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    Uint32 frameStart;
    int dt;
};
#endif