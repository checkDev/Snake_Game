//
//  GrowFood.hpp
//  CPP_Snake_Game
//
//  Created by RatulS on 7/19/20.
//  Copyright © 2020 RatulS. All rights reserved.
//

#ifndef GrowFood_hpp
#define GrowFood_hpp
#include "Food.hpp"


class GrowFood:public Food{
    
public:
    GrowFood( int posx, int posy);
    int  foodGetPoints() override;
  
    
};


#endif /* GrowFood_hpp */
