#include "collegeplayer.h"

NCAABasketballPlayer::NCAABasketballPlayer()
    : BasketballPlayer() {}

NCAABasketballPlayer::NCAABasketballPlayer(char playerType, string playerName, int games, float efg, int trb, int ast, int stl, int blk, int tov, int pts)
    : BasketballPlayer(playerType, playerName, games, efg, trb, ast, stl, blk, tov, pts) {}

void NCAABasketballPlayer::print() const {
    std::cout << "Player Type: " << playerType << std::endl;
    std::cout << "Player Name: " << playerName << std::endl;
    std::cout << "Games: " << games << std::endl;
    std::cout << "EFG: " << efg << std::endl;
    std::cout << "TRB: " << trb << std::endl;
    std::cout << "AST: " << ast << std::endl;
    std::cout << "STL: " << stl << std::endl;
    std::cout << "BLK: " << blk << std::endl;
    std::cout << "TOV: " << tov << std::endl;
    std::cout << "Points: " << pts << std::endl;
    std::cout << "Efficiency Rating: " << effRating << std::endl;
    std::cout << "Player Value: " << value << std::endl;
}
