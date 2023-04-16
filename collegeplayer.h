#pragma once
#include "player.h"
#include <string>
using namespace std;

class CollegeBasketballPlayer : public BasketballPlayer {
protected:
    string team;

public:
    CollegeBasketballPlayer();
    CollegeBasketballPlayer(char playerType, string playerName, int games, float efg, int trb, int ast, int stl, int blk, int tov, int pts, string team);
    void setTeam(string team);
    void print() const override;
    string getTeam() const;
};
