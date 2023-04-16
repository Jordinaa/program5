#pragma once

#include "player.h"
#include "proplayer.h"
#include "collegeplayer.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

class TeamManager {
public:
    TeamManager();

    void addPlayer(BasketballPlayer* player);
    void createAllNCAATeam();
    void createMixedTeam();
    void createAllProTeam();

private:
    std::vector<BasketballPlayer*> players;
};
