#include "teammanager.h"

TeamManager::TeamManager() {}

void TeamManager::addPlayer(BasketballPlayer* player) {
    players.push_back(player);
}

bool comparePlayersByValueAndEffRating(BasketballPlayer* a, BasketballPlayer* b) {
    if (a->getValue() == b->getValue()) {
        return a->getEffRating() > b->getEffRating();
    }
    return a->getValue() > b->getValue();
}

void TeamManager::createAllNCAATeam() {
    std::vector<BasketballPlayer*> ncaaPlayers;
    for (BasketballPlayer* player : players) {
        if (player->getPlayerType() == 'N') {
            ncaaPlayers.push_back(player);
        }
    }

    std::sort(ncaaPlayers.begin(), ncaaPlayers.end(), comparePlayersByValueAndEffRating);

    std::cout << "All NCAA Team Roster:" << std::endl;
    for (int i = 0; i < 12 && i < ncaaPlayers.size(); ++i) {
        ncaaPlayers[i]->print();
    }
}

void TeamManager::createMixedTeam() {
    std::vector<BasketballPlayer*> proPlayers, ncaaPlayers, mixedTeam;
    for (BasketballPlayer* player : players) {
        if (player->getPlayerType() == 'P') {
            proPlayers.push_back(player);
        } else if (player->getPlayerType() == 'N') {
            ncaaPlayers.push_back(player);
        }
    }

    std::sort(proPlayers.begin(), proPlayers.end(), comparePlayersByValueAndEffRating);
    std::sort(ncaaPlayers.begin(), ncaaPlayers.end(), comparePlayersByValueAndEffRating);

    std::map<char, int> proPositions = {{'C', 0}, {'F', 0}, {'G', 0}};

    for (BasketballPlayer* player : proPlayers) {
        if (proPositions[player->getPosition()] < 2) {
            mixedTeam.push_back(player);
            proPositions[player->getPosition()]++;
        }

        if (proPositions['C'] == 2 && proPositions['F'] == 2 && proPositions['G'] == 2) {
            break;
        }
    }

    for (int i = 0; i < 6 && i < ncaaPlayers.size(); ++i) {
        mixedTeam.push_back(ncaaPlayers[i]);
    }

    std::cout << "Mixed Team Roster:" << std::endl;
    for (BasketballPlayer* player : mixedTeam) {
        player->print();
    }
}


void TeamManager::createAllProTeam() {
    std::vector<BasketballPlayer*> proPlayers, allProTeam;
    for (BasketballPlayer* player : players) {
        if (player->getPlayerType() == 'P') {
            proPlayers.push_back(player);
        }
    }

    std::sort(proPlayers.begin(), proPlayers.end(), comparePlayersByValueAndEffRating);

    std::map<char, int> proPositions = {{'C', 0}, {'F', 0}, {'G', 0}};
    std::map<int, std::vector<BasketballPlayer*>> roundRestrictions = {
        {1, {}},
        {2, {}},
        {3, {}},
        {4, {}},
        {5, {}},
    };

    for (BasketballPlayer* player : proPlayers) {
        if (proPositions[player->getPosition()] < 2) {
            allProTeam.push_back(player);
            proPositions[player->getPosition()]++;
        } else {
            int round = 0;

            if (player->getValue() <= 8) {
                round = 1;
            } else if (player->getValue() <= 6) {
                round = 3;
            } else if (player->getValue() <= 5) {
                round = 4;
            }

            if (round > 0) {
                roundRestrictions[round].push_back(player);
            }
        }
    }

    std::vector<int> roundOrder = {1, 2, 3, 4, 5};
    for (int round : roundOrder) {
        for (BasketballPlayer* player : roundRestrictions[round]) {
            if (proPositions[player->getPosition()] < 5) {
                allProTeam.push_back(player);
                proPositions[player->getPosition()]++;
            }
        }
    }

    std::cout << "All Pro Team Roster:" << std::endl;
    int totalCost = 0;
    for (BasketballPlayer* player : allProTeam) {
        player->print();
        totalCost += dynamic_cast<ProBasketballPlayer*>(player)->getContractValue();
    }

    std::cout << "Total cost for funding this team: $" << totalCost << std::endl;
}
