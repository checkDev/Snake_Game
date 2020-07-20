#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  //sdl_Good_Food_surface = SDL_LoadBMP("../resource-images/canned-fish.bmp");
   sdl_Good_Food_surface = SDL_LoadBMP("../resource-images/carrot.bmp");
  if (sdl_Good_Food_surface == NULL)
       {
         std::cerr << "surface could not be created.\n";
         std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
          
       
       }
  sdl_Destroy_Food_surface = SDL_LoadBMP("../resource-images/coronavirus.bmp");
  if (sdl_Destroy_Food_surface == NULL)
       {
         std::cerr << "surface could not be created.\n";
         std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
          
       
       }
         
  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
          
  sdl_Good_Food_texture= SDL_CreateTextureFromSurface(sdl_renderer, sdl_Good_Food_surface);
  if (!sdl_Good_Food_texture) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
      
  }
  sdl_Destroy_Food_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_Destroy_Food_surface);
   if (!sdl_Destroy_Food_texture) {
       SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
       
   }
 // SDL_FreeSurface(sdl_surface);
     // Update window
  SDL_UpdateWindowSurface( sdl_window );
  
          
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}
// gw / gh = 32
//sw and sh = 640 each
//no of blocks = 20 , 20
void Renderer::Render(Snake const snake, SDL_Point  &food , std::vector<Food*>* pfood) {
  SDL_Rect block;
  block.w = screen_width / grid_width;   // ->20
  block.h = screen_height / grid_height; // ->20

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);
 
  // Render food
  if(pfood->size() > 0)
  {
      //new Logic to render the food by food Types //SDL Libs etc
      //Eg.
      //SDL_RenderCopy(sdl_renderer, sdl_mask_texture, NULL, &block);
      std::vector<Food*> &foods = *pfood;
      for(auto eachFood : foods)
      {
      
          block.x = (eachFood->getPosX() * block.w) %screen_width; //food.x = 32 //22,30 //20,26
          eachFood->setPosX(block.x /block.w);
          block.y = (eachFood->getPosY() * block.h)%screen_width; //food.y = 17
          eachFood->setPosY(block.y/ block.h);
          eachFood->getFoodType() == GROW_FOOD ? SDL_RenderCopy(sdl_renderer, sdl_Good_Food_texture, NULL, &block)
                :   SDL_RenderCopy(sdl_renderer, sdl_Destroy_Food_texture, NULL, &block) ;
      }
  }
  else
  {
      SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
      block.x = (food.x * block.w) %screen_width; //food.x = 32 //22,30 //20,26
      food.x = block.x /block.w;
      block.y = (food.y * block.h)%screen_width; //food.y = 17
      food.y = block.y/ block.h;
      SDL_RenderFillRect(sdl_renderer, &block);
  }
    
    //test rectangle code
//    SDL_SetRenderDrawColor(sdl_renderer, 102, 51, 0, 255);
//    SDL_Rect rectangle;
//
//    rectangle.x = 200;
//    rectangle.y = 200;
//    rectangle.w = 50;
//    rectangle.h = 50;
//    SDL_RenderFillRect(sdl_renderer, &rectangle);
    //

  // Render snake's body
    std::cout << " game level " << gameLevel << std::endl;
 if(gameLevel > 1)
 {
      for (SDL_Point const &point : snake.body) {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        odd ? SDL_SetRenderDrawColor(sdl_renderer, 0xAD, 0xFF, 0x2F, 0xFF) :SDL_SetRenderDrawColor(sdl_renderer, 0x9A, 0xCD, 0x32, 0xFF);
        SDL_RenderFillRect(sdl_renderer, &block);
        odd = !odd;
      }
 }
else
{
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }
}

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int level, int score, int fps ) {
  std::string title{"Snake Score: " + std::to_string(score) + " Level: " + std::to_string(level) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
