//
//  Food.hpp
//  CPP_Snake_Game
//
//  Created by RatulS on 7/17/20.
//  Copyright © 2020 RatulS. All rights reserved.
//

#ifndef Food_hpp
#define Food_hpp
#include <random>

enum FoodType
{
    GROW_FOOD =1,
    DESTROY_FOOD
    
};

class Food
{
public:
     Food(FoodType type , int startx, int starty , int totalWidth , int totalHeight);
     Food(FoodType type , int posx, int posy);
     void placeFood(int posX, int posY);
     void changeFoodType(FoodType type);
     void changeFoodPosition(int posX, int posY);
     virtual int  foodGetPoints()=0;
    inline int getPosX(){ return posX;}
    inline int getPosY(){ return posY;}
    inline void setPosX(int x){  posX = x;}
    inline void setPosY(int y){  posY= y;}
    inline FoodType getFoodType(){return food_type;}
    //inline int getPoints(){return points;}
    virtual~Food();
private:
    int posX, posY;
    FoodType food_type;
    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;
    int points = 0;
};

#endif /* Food_hpp */
