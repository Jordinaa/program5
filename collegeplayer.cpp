#include "collegeplayer.h"

CollegeBasketballPlayer::CollegeBasketballPlayer()
    : BasketballPlayer(), team("unknown") {}

CollegeBasketballPlayer::CollegeBasketballPlayer(char playerType, string playerName, int games, float efg, int trb, int ast, int stl, int blk, int tov, int pts, string team)
    : BasketballPlayer(playerType, playerName, games, efg, trb, ast, stl, blk, tov, pts), team(team) {}

void CollegeBasketballPlayer::setTeam(string team) {
    this->team = team;
}

void CollegeBasketballPlayer::print() const {
    cout << "NCAA Player Name: " << playerName << "\t";
    cout << "Player Value: " << getValue() << "\t";
    cout << "Eff Rating: " << getEffRating() << "\t";
    cout << "EFG Rating: " << efg << endl;
}

string CollegeBasketballPlayer::getTeam() const {
    return team;
}
