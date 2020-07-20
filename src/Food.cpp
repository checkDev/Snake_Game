//
//  Food.cpp
//  CPP_Snake_Game
//
//  Created by RatulS on 7/17/20.
//  Copyright © 2020 RatulS. All rights reserved.
//

#include "Food.hpp"
#include "game.h"

Food:: Food(FoodType type , int startx, int starty , int totalWidth , int totalHeight): food_type(type),engine(dev()),
random_w(startx, totalWidth), random_h(starty, totalHeight)
{
   
  
   points=0;
}

Food::Food(FoodType type , int posx, int posy) : food_type(type) , posX(posx) , posY(posy)
{
   
  
    points=0;
}

void Food::placeFood(int posX, int posY )
{
    
}
void Food::changeFoodType(FoodType type)
{
    
}
void Food::changeFoodPosition(int posX, int posY)
{
    
}
Food::~Food(){}
/*
int  Food::foodGetPoints()
{
    return 0;
}*/
