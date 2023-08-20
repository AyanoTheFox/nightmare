#include "nightmare.hpp"

TTF_Font* nightmare::loadFont(const char* path, const int size)
{
    if (TTF_Init() == -1)
    {
        fprintf(stderr, "TTF_Init Error: %s\n", TTF_GetError());
        return NULL;
    }
    TTF_Font* font = TTF_OpenFont(path, size);
    if (font == NULL)
    {
        fprintf(stderr, "TTF_OpenFont Error: %s\n", TTF_GetError());
        return NULL;
    }
    return font;
}

void nightmare::drawText(TTF_Font* font, char* text, int x, int y, int w, int h, int ox, int oy, SDL_Color color)
{
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

SDL_Texture* nightmare::loadImage(const char* path)
{
    SDL_Surface *img = IMG_Load(path);
    if (img == NULL)
    {
        fprintf(stderr, "Img load Error: %s\n", SDL_GetError());
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, img);
    SDL_FreeSurface(img);
    if (texture == NULL)
    {
        fprintf(stderr, "Texture load Error: %s\n", SDL_GetError());
        return NULL;
    }
    return texture;
}

void nightmare::drawImage(SDL_Texture* texture, int x, int y, int w, int h, int ox, int oy)
{
    if (texture == NULL)
    {
        fprintf(stderr, "Couldn't load image\n");
    }
    SDL_Rect dest;
    dest.x = x - ox;
    dest.y = y - oy;
    dest.w = w;
    dest.h = h;
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void nightmare::init(const char* title, int x, int y, int w, int h, bool fullscreen)
{
    int flags = 0;
    if (fullscreen) 
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL2 started..." << std::endl;
        window = SDL_CreateWindow(title, x, y, w, h, flags);
        if (window)
        {
            std::cout << "Window started..." << std::endl;
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer)
            {
                std::cout << "Renderer started..." << std::endl;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            } else {
                fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
            }
        } else {
            fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        }
    } else {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
    }
}

char* nightmare::getEvents()
{
    frameStart = SDL_GetTicks();
    char* result;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            result = "quit";
            break;
        default:
            result = "none";
            break;
    }
    return result;
}

void nightmare::render()
{
    SDL_RenderClear(renderer);
}

int nightmare::update(const int fps)
{
    SDL_RenderPresent(renderer);
    const int delay = 1000 / fps;
    dt = SDL_GetTicks() - frameStart;
    if (delay > dt)
    {
        SDL_Delay(delay - dt);
    }
    return dt;
}

void nightmare::destroy()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "nightmare end..." << std::endl;
}
