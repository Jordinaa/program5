#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
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
    void setEffRating();
    void setValue();
    virtual void print() const = 0;
    char getPlayerType() const;
    string getPlayerName() const;
    int getGames() const;
    float getEFG() const;
    int getTRB() const;
    int getAST() const;
    int getSTL() const;
    int getBLK() const;
    int getTOV() const;
    int getPoints() const;
    float getEffRating() const;
    int getValue() const;
};
