//
//  DestroyFood.hpp
//  CPP_Snake_Game
//
//  Created by RatulS on 7/19/20.
//  Copyright © 2020 RatulS. All rights reserved.
//

#ifndef DestroyFood_hpp
#define DestroyFood_hpp

#include "Food.hpp"

class DestroyFood:public Food{
    
public:
    DestroyFood( int posx, int posy);
    int  foodGetPoints() override;
    int points = -10;
    
};

#endif /* DestroyFood_hpp */
