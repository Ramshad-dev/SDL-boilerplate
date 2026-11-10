#include <SDL2/SDL.h>
#include <iostream> 
#include <cstdint>
#include <vector>

class Sdl{
    public:
    Sdl();
    ~Sdl();
    void sdlInit();
    void sdlUpdate(const std::vector<uint32_t> &pixels);
    bool sdlinput(bool* running);
    void sdlQuit();
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