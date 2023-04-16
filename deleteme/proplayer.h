#pragma once

#include "player.h"

class ProBasketballPlayer : public BasketballPlayer {
private:
    int contractValue;

public:
    ProBasketballPlayer();
    ProBasketballPlayer(char playerType, string playerName, int games, float efg, int trb, int ast, int stl, int blk, int tov, int pts);
    ~ProBasketballPlayer() {}

    void setContractValue();
    int getContractValue() const { return contractValue; }

    void print() const override;
};
