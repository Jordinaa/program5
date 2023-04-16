#pragma once
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

class ProBasketballPlayer : public BasketballPlayer {
protected:
    int years;
    string position;
    int contractValue;

public:
    ProBasketballPlayer();
    ProBasketballPlayer(char playerType, string playerName, int games, float efg, int trb, int ast, int stl, int blk, int tov, int pts, int years, string position);    
    void setYears(int years);
    void setPosition(string position);
    void setContractValue();
    void print() const override;
    int getYears() const;
    string getPosition() const;
    int getContractValue() const;
};
