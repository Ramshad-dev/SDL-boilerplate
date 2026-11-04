#include <SDL2/SDL.h>
#include <iostream>

class sdl{
    public:
    sdl();
    ~sdl();
    void sdlInit();
    void sdlQuit();
    bool sdlinput(bool* running);
    private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Event event;
    const char* TITLE="SDL Boilerplate";
    int screenPosX=200;
    int screenPosY=200;
    int windowWidth=800;
    int windowHeight=600;
    int ResolutionWidth=800;
    int ResolutionHeight=600;
};