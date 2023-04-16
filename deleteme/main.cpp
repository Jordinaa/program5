#include "player.h"
#include "proplayer.h"
#include "teammanager.h"

int main() {
    // Create NCAA and Pro BasketballPlayer objects
    // ...

    // Create TeamManager object and pass in the lists of players
    TeamManager teamManager(ncaaPlayers, proPlayers);

    // Create dream teams
    teamManager.createAllNcaaTeam();
    teamManager.createMixedTeam();
    teamManager.createAllProTeam();

    return 0;
}
