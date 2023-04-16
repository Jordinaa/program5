#include "proplayer.h"

ProBasketballPlayer::ProBasketballPlayer()
    : BasketballPlayer(), years(0), position("unknown"), contractValue(0) {}

ProBasketballPlayer::ProBasketballPlayer(char playerType, string playerName, int games, float efg, int trb, int ast, int stl, int blk, int tov, int pts, int years, string position)
    : BasketballPlayer(playerType, playerName, games, efg, trb, ast, stl, blk, tov, pts) {
    setYears(years);
    setPosition(position);
    setContractValue();
}

void ProBasketballPlayer::setYears(int years) {
    this->years = years < 0 ? 0 : years;
}

void ProBasketballPlayer::setPosition(string position) {
    this->position = position;
}

void ProBasketballPlayer::setContractValue() {
    int value = getValue();
    if (value == 10) {
        contractValue = 12000000;
    } else if (value == 9) {
        contractValue = 10000000;
    } else if (value == 8) {
        contractValue = 7500000;
    } else if (value == 7) {
        contractValue = 6000000;
    } else if (value == 5 || value == 6) {
        contractValue = 5000000;
    } else if (value == 3 || value == 4) {
        contractValue = 2500000;
    } else {
        contractValue = 500000;
    }
}

void ProBasketballPlayer::print() const {
    cout << "Pro Player Name: " << playerName << "\t";
    cout << "Player Value: " << getValue() << "\t";
    cout << "Eff Rating: " << getEffRating() << "\t";
    cout << "EFG Rating: " << efg << endl;
}

int ProBasketballPlayer::getYears() const {
    return years;
}

string ProBasketballPlayer::getPosition() const {
    return position;
}

int ProBasketballPlayer::getContractValue() const {
    return contractValue;
}
