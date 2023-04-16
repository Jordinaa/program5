#include "player.h"

BasketballPlayer::BasketballPlayer()
    : playerType('N'), playerName(""), games(0), efg(0), trb(0), ast(0), stl(0), blk(0), tov(0), pts(0), effRating(0), value(0) {}

BasketballPlayer::BasketballPlayer(char playerType, string playerName, int games, float efg, int trb, int ast, int stl, int blk, int tov, int pts)
    : playerType(playerType), playerName(playerName), games(games), efg(efg), trb(trb), ast(ast), stl(stl), blk(blk), tov(tov), pts(pts), effRating(0), value(0) {
    setEffRating();
    setValue();
}

void BasketballPlayer::setPlayerType(char playerType) { this->playerType = playerType; }
void BasketballPlayer::setPlayerName(string playerName) { this->playerName = playerName; }
void BasketballPlayer::setGames(int games) { this->games = games; }
void BasketballPlayer::setEFG(float efg) { this->efg = efg; }
void BasketballPlayer::setTRB(int trb) { this->trb = trb; }
void BasketballPlayer::setAST(int ast) { this->ast = ast; }
void BasketballPlayer::setSTL(int stl) { this->stl = stl; }
void BasketballPlayer::setBLK(int blk) { this->blk = blk; }
void BasketballPlayer::setTOV(int tov) { this->tov = tov; }
void BasketballPlayer::setPoints(int pts) { this->pts = pts; }

void BasketballPlayer::setEffRating() {
    if (games <= 5) {
        effRating = -1;
    } else {
        effRating = (pts + trb + ast + stl + blk - ((games * 2) - (tov))) / static_cast<float>(games);
    }
}

void BasketballPlayer::setValue() {
    // Calculate the player value based on the given attributes
    float efgPerc = efg / 100.0;
    float ptsPerGame = float(pts) / games;
    float trbPerGame = float(trb) / games;
    float tovPerGame = float(tov) / games;
    float blkPerGame = float(blk) / games;
    float stlPerGame = float(stl) / games;

    if (efgPerc > 0.7 || effRating > 20) {
        value = 10;
    } else if (efgPerc > 0.65 || effRating > 15) {
        value = 9;
    } else if (efgPerc > 0.65 && stlPerGame > 2 && ptsPerGame > 20 && trbPerGame > 5 && tovPerGame <= 1) {
        value = 9;
    } else if (efgPerc > 0.6 || effRating > 13) {
        value = 8;
    } else if (efgPerc > 0.6 && blkPerGame > 3 && ptsPerGame > 15 && trbPerGame > 5) {
        value = 8;
    } else if (efgPerc > 0.6 && ptsPerGame > 15 && trbPerGame > 5 && tovPerGame < 2) {
        value = 8;
    } else if (efgPerc > 0.55 || effRating > 10) {
        value = 7;
    } else if (efgPerc > 0.55 && ptsPerGame > 15 && trbPerGame > 5) {
        value = 7;
    } else if (efgPerc > 0.55 && blkPerGame > 3 && ptsPerGame > 10 && trbPerGame > 4) {
        value = 6;
    } else if (efgPerc > 0.45 && ptsPerGame > 10 && trbPerGame > 4) {
        value = 5;
    } else if (efgPerc > 0.4 && ptsPerGame > 5 && trbPerGame > 3) {
        value = 3;
    } else if (efgPerc > 0.35 && ptsPerGame > 5 && trbPerGame > 3) {
        value = 2;
    } else {
        value = 0;
    }
}

