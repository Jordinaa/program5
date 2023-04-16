#pragma once

#include <string>
#include <iostream>

using namespace std;

class BasketballPlayer {
protected:
    char playerType;
    string playerName;
    int games;
    float efg;
    int trb;
    int ast;
    int stl;
    int blk;
    int tov;
    int pts;
    float effRating;
    int value;

public:
    BasketballPlayer();
    BasketballPlayer(char playerType, string playerName, int games, float efg, int trb, int ast, int stl, int blk, int tov, int pts);
    virtual ~BasketballPlayer() {}

    void setPlayerType(char playerType);
    void setPlayerName(string playerName);
    void setGames(int games);
    void setEFG(float efg);
    void setTRB(int trb);
    void setAST(int ast);
    void setSTL(int stl);
    void setBLK(int blk);
    void setTOV(int tov);
    void setPoints(int pts);

    char getPlayerType() const { return playerType; }
    string getPlayerName() const { return playerName; }
    int getGames() const { return games; }
    float getEFG() const { return efg; }
    int getTRB() const { return trb; }
    int getAST() const { return ast; }
    int getSTL() const { return stl; }
    int getBLK() const { return blk; }
    int getTOV() const { return tov; }
    int getPoints() const { return pts; }
    float getEffRating() const { return effRating; }
    int getValue() const { return value; }

    void setEffRating();
    void setValue();

    virtual void print() const = 0;
};
