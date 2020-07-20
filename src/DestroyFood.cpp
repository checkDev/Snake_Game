//
//  DestroyFood.cpp
//  CPP_Snake_Game
//
//  Created by RatulS on 7/19/20.
//  Copyright © 2020 RatulS. All rights reserved.
//

#include "DestroyFood.hpp"

DestroyFood::DestroyFood( int posx, int posy):Food(DESTROY_FOOD,  posx,  posy)
{
}

 int  DestroyFood::foodGetPoints()
{
    return -25;
}


