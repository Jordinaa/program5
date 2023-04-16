#include "player.h"

BasketballPlayer::BasketballPlayer()
    : playerType('U'), playerName("unknown"), games(0), efg(0.0), trb(0), ast(0), stl(0), blk(0), tov(0), pts(0), effRating(0.0), value(0) {}

BasketballPlayer::BasketballPlayer(char playerType, string playerName, int games, float efg, int trb, int ast, int stl, int blk, int tov, int pts)
    : playerType(playerType), playerName(playerName), games(games), efg(efg), trb(trb), ast(ast), stl(stl), blk(blk), tov(tov), pts(pts) {
    setEffRating();
    setValue();
}

// Setters
void BasketballPlayer::setPlayerType(char playerType) {
    this->playerType = playerType;
}

void BasketballPlayer::setPlayerName(string playerName) {
    this->playerName = playerName;
}

void BasketballPlayer::setGames(int games) {
    this->games = games;
}

void BasketballPlayer::setEFG(float efg) {
    this->efg = efg;
}

void BasketballPlayer::setTRB(int trb) {
    this->trb = trb;
}

void BasketballPlayer::setAST(int ast) {
    this->ast = ast;
}

void BasketballPlayer::setSTL(int stl) {
    this->stl = stl;
}

void BasketballPlayer::setBLK(int blk) {
    this->blk = blk;
}

void BasketballPlayer::setTOV(int tov) {
    this->tov = tov;
}

void BasketballPlayer::setPoints(int pts) {
    this->pts = pts;
}

// Calculation methods
void BasketballPlayer::setEffRating() {
    effRating = (pts + trb + ast + stl + blk - (pts / efg - pts + tov)) / games;
}


void BasketballPlayer::setValue() {
    if (efg > 0.70 || effRating > 20) {
        value = 10;
    } else if (efg > 0.65 || effRating > 15) {
        value = 9;
    } else if (efg > 0.60 || effRating > 13) {
        value = 8;
    } else if (efg > 0.60 && blk / static_cast<float>(games) > 3 && pts / static_cast<float>(games) > 15 && trb / static_cast<float>(games) > 5) {
        value = 8;
    } else if (efg > 0.55 || effRating > 10) {
        value = 7;
    } else if (efg > 0.55 && pts / static_cast<float>(games) > 15 && trb / static_cast<float>(games) > 5) {
        value = 7;
    } else if (efg > 0.45 && pts / static_cast<float>(games) > 10 && trb / static_cast<float>(games) > 4) {
        value = 5;
    } else if (efg > 0.40 && pts / static_cast<float>(games) > 5 && trb / static_cast<float>(games) > 3) {
        value = 3;
    } else if (efg > 0.35 && pts / static_cast<float>(games) > 5 && trb / static_cast<float>(games) > 3) {
        value = 2;
    }
}

// Getters
char BasketballPlayer::getPlayerType() const {
    return playerType;
}

string BasketballPlayer::getPlayerName() const {
    return playerName;
}

int BasketballPlayer::getGames() const {
    return games;
}

float BasketballPlayer::getEFG() const {
    return efg;
}

int BasketballPlayer::getTRB() const {
    return trb;
}

int BasketballPlayer::getAST() const {
    return ast;
}

int BasketballPlayer::getSTL() const {
    return stl;
}

int BasketballPlayer::getBLK() const {
    return blk;
}

int BasketballPlayer::getTOV() const {
    return tov;
}

int BasketballPlayer::getPoints() const {
    return pts;
}

float BasketballPlayer::getEffRating() const {
    return effRating;
}

int BasketballPlayer::getValue() const {
    return value;
}
