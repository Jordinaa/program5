#include "dreamteam.h"
#include "readfile.h"

int main() {
    vector<shared_ptr<BasketballPlayer>> players;
    vector<string> errors;

    string ncaaFile = "data/playerStatsNCAA.csv";
    string proFile = "data/playerStatsPRO.csv";

    readNCAAPlayers(ncaaFile, players, errors);
    readProPlayers(proFile, players, errors);    
    
    // Print the errors to a file
    ofstream outFile("data/output.txt");
    if (!outFile) {
        cerr << "Unable to open output file" << endl;
        exit(1);
    }
    for (const auto& error : errors) {
        outFile << error << endl;
    }

    outFile.close();

    auto NCAADreamTeam = createAllNCAADreamTeam(players);
    printNCAADreamTeam("NCAA Dream Team", NCAADreamTeam);

    auto mixedDreamTeam = createMixedDreamTeam(players);
    printMixedDreamTeam("NCAA/Pro Dream Team", mixedDreamTeam);

    auto allProDreamTeam = createAllProDreamTeam(players);
    printAllProTeam("Pro Dream Team", allProDreamTeam);
 
    return 0;
}
