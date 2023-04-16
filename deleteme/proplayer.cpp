#include "proplayer.h"

ProBasketballPlayer::ProBasketballPlayer()
    : BasketballPlayer(), contractValue(0) {}

ProBasketballPlayer::ProBasketballPlayer(char playerType, string playerName, int games, float efg, int trb, int ast, int stl, int blk, int tov, int pts)
    : BasketballPlayer(playerType, playerName, games, efg, trb, ast, stl, blk, tov, pts), contractValue(0) {
    setContractValue();
}

void ProBasketballPlayer::print() const {
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
    std::cout << "Contract Value: " << contractValue << std::endl;
}


void ProBasketballPlayer::setContractValue() {
    // Calculate the contract value based on the player value and efficiency rating
    switch (value) {
        case 10:
            contractValue = 12000000;
            break;
        case 9:
            contractValue = 10000000;
            break;
        case 8:
            contractValue = 7500000;
            break;
        case 7:
            contractValue = 6000000;
            break;
        case 6:
        case 5:
            contractValue = 5000000;
            break;
        case 4:
        case 3:
            contractValue = 2500000;
            break;
        default:
            contractValue = 500000;
            break;
    }
}
