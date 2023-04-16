#pragma once

#include "player.h"

class NCAABasketballPlayer : public BasketballPlayer {
public:
    NCAABasketballPlayer();
    NCAABasketballPlayer(char playerType, string playerName, int games, float efg, int trb, int ast, int stl, int blk, int tov, int pts);
    ~NCAABasketballPlayer() {}

    void print() const override;
};

