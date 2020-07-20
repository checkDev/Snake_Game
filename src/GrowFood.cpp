//
//  GrowFood.cpp
//  CPP_Snake_Game
//
//  Created by RatulS on 7/19/20.
//  Copyright © 2020 RatulS. All rights reserved.
//

#include "GrowFood.hpp"


GrowFood::GrowFood( int posx, int posy):Food(GROW_FOOD,  posx,  posy)
{
 
}

 int  GrowFood::foodGetPoints()
{
    return 10;
}
