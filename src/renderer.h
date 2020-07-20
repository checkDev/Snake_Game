#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "Food.hpp"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point  &food,  std::vector<Food*>* pfood);
  void UpdateWindowTitle(int level,int score, int fps);
  inline void setGameLevel(int level){
      gameLevel = level;
    }

 private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    SDL_Surface *sdl_Good_Food_surface;
    SDL_Surface *sdl_Destroy_Food_surface;
    SDL_Texture *sdl_Good_Food_texture;
    SDL_Texture *sdl_Destroy_Food_texture;

  int gameLevel;
  bool odd = true;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif
