#include "dreamteam.h"

bool comparePlayers(const shared_ptr<BasketballPlayer>& a, const shared_ptr<BasketballPlayer>& b) {
    if (a->getValue() == b->getValue()) {
        return a->getEffRating() > b->getEffRating();
    }
    return a->getValue() > b->getValue();
}


void printNCAADreamTeam(const string& title, const vector<shared_ptr<BasketballPlayer>>& dreamTeam) {
    cout << title << endl;
    cout << setw(25) << left << "Player Name";
    cout << setw(20) << left << "Player Value";
    cout << setw(20) << left << "Eff Rating";
    cout << setw(20) << left << "EFG Rating";
    cout << endl;

    for (const auto& player : dreamTeam) {
        cout << setw(25) << left << player->getPlayerName();
        cout << setw(20) << left << player->getValue();
        cout << fixed << setprecision(2) << setw(20) << left << player->getEffRating();
        cout << fixed << setprecision(2) << setw(20) << left << player->getEFG();
        cout << endl;
    }
    cout << "\n" << endl;
}

vector<shared_ptr<BasketballPlayer>> createAllNCAADreamTeam(vector<shared_ptr<BasketballPlayer>>& players) {
    vector<shared_ptr<BasketballPlayer>> ncaaPlayers;

    for (const auto& player : players) {
        if (player->getPlayerType() == 'C') {
            ncaaPlayers.push_back(player);
        }
    }

    sort(ncaaPlayers.begin(), ncaaPlayers.end(), comparePlayers);

    vector<shared_ptr<BasketballPlayer>> dreamTeam;
    for (size_t i = 0; i < 12 && i < ncaaPlayers.size(); ++i) {
        dreamTeam.push_back(ncaaPlayers[i]);
    }

    return dreamTeam;
}



void printMixedDreamTeam(const string& title, const vector<shared_ptr<BasketballPlayer>>& dreamTeam) {
    cout << title << endl;
    cout << setw(20) << left << "Player Name";
    cout << setw(20) << left << "Player Type";
    cout << setw(20) << left << "Position";
    cout << setw(20) << left << "Player Value";
    cout << setw(20) << left << "Eff Rating";
    cout << setw(20) << left << "EFG Rating" << endl;

    for (const auto& player : dreamTeam) {
        cout << setw(20) << left << player->getPlayerName();
        // cout << setw(20) << left << player->getPlayerType();
        // cout << setw(20) << left << player->getPosition();
        // cout << fixed << setprecision(2) << setw(20) << left << player->getValue();
        // cout << fixed << setprecision(2) << setw(20) << left << player->getEffRating();
        // cout << fixed << setprecision(2) << setw(20) << left << player->getEFG() << endl;
        cout << "player type: " << player->getPlayerType() << endl;
        cout << "player value: " << player->getValue() << endl;
    }

    cout << endl;
}

vector<shared_ptr<BasketballPlayer>> createMixedDreamTeam(vector<shared_ptr<BasketballPlayer>>& players) {
    vector<shared_ptr<BasketballPlayer>> ncaaPlayers, proPlayers;

    for (const auto& player : players) {
        if (player->getPlayerType() == 'C') {
            ncaaPlayers.push_back(player);
        } else if (player->getPlayerType() == 'P') {
            proPlayers.push_back(player);
        }
    }

    sort(proPlayers.begin(), proPlayers.end(), comparePlayers);

    vector<shared_ptr<BasketballPlayer>> selectedPlayers;

    // Choose the top 2 centers, 2 forward positions, and 2 guard positions from the Pro list based on their playerValue and effRating.
    int centers = 0, forwards = 0, guards = 0;
    for (const auto& player : proPlayers) {
        ProBasketballPlayer* proPlayer = dynamic_cast<ProBasketballPlayer*>(player.get());
        if (proPlayer) {
            string pos = proPlayer->getPosition();
            pos.erase(remove_if(pos.begin(), pos.end(), ::isspace), pos.end());
            if (pos == "C" && centers < 2) {
                selectedPlayers.push_back(player);
                centers++;
            } else if ((pos == "F" || pos == "PF" || pos == "SF") && forwards < 2) {
                selectedPlayers.push_back(player);
                forwards++;
            } else if ((pos == "G" || pos == "PG" || pos == "SG") && guards < 2) {
                selectedPlayers.push_back(player);
                guards++;
            }

        }

        if (centers >= 2 && forwards >= 2 && guards >= 2) {
            break;
        }
    }

    // Pick the top 6 players from the NCAA list based on their playerValue and effRating.
    sort(ncaaPlayers.begin(), ncaaPlayers.end(), comparePlayers);

    for (size_t i = 0; i < 6 && i < ncaaPlayers.size(); ++i) {
        selectedPlayers.push_back(ncaaPlayers[i]);
    }

    // Add the selected players to the dreamTeam vector
    vector<shared_ptr<BasketballPlayer>> dreamTeam(selectedPlayers.begin(), selectedPlayers.end());
    cout << "size of team: " << dreamTeam.size() << endl;
    return dreamTeam;
}



void printAllProTeam(const string& title, const vector<shared_ptr<BasketballPlayer>>& team) {
    cout << title << endl;
    cout << setw(20) << left << "Player Name";
    cout << setw(20) << left << "Player Type";
    cout << setw(20) << left << "Position";
    cout << setw(20) << left << "Player Value";
    cout << setw(20) << left << "Eff Rating";
    cout << setw(20) << left << "Contract Value" << endl;

    for (const auto& player : team) {
        // auto proPlayer = dynamic_cast<ProBasketballPlayer*>(player.get());
        cout << setw(20) << left << player->getPlayerName();
        cout << setw(20) << left << player->getPlayerType();
        // cout << setw(20) << left << player->getPosition();
        cout << fixed << setprecision(2) << setw(20) << left << player->getValue(); // Set precision for floating-point numbers
        cout << setw(20) << left << player->getEffRating();
        // cout << setw(20) << left << player->getContractValue(); 
        cout << endl;
    }
}



vector<shared_ptr<BasketballPlayer>> createAllProDreamTeam(vector<shared_ptr<BasketballPlayer>>& players) {
    vector<shared_ptr<BasketballPlayer>> proPlayers;

    for (const auto& player : players) {
        if (player->getPlayerType() == 'P') {
            proPlayers.push_back(player);
        }
    }

    sort(proPlayers.begin(), proPlayers.end(), comparePlayers);

    vector<shared_ptr<BasketballPlayer>> dreamTeam;

    // Pick the best center and the best 2 forward and 2 guard positions from the Pro list based on their playerValue and effRating.
    int centers = 0, forwards = 0, guards = 0;
    for (const auto& player : proPlayers) {
        ProBasketballPlayer* proPlayer = dynamic_cast<ProBasketballPlayer*>(player.get());
        if (proPlayer) {
            string pos = proPlayer->getPosition();
            pos.erase(remove_if(pos.begin(), pos.end(), ::isspace), pos.end());
            if (pos == "C" && centers < 1) {
                dreamTeam.push_back(player);
                centers++;
            } else if ((pos == "F" || pos == "PF" || pos == "SF") && forwards < 2) {
                dreamTeam.push_back(player);
                forwards++;
            } else if ((pos == "G" || pos == "PG" || pos == "SG") && guards < 2) {
                dreamTeam.push_back(player);
                guards++;
            }
        }

        if (centers >= 1 && forwards >= 2 && guards >= 2) {
            break;
        }
    }

    // Add the next 7 players in order by importance of position, but also with a maximum playerValue for each 'round'.
    int maxPlayerValues[] = {8, 8, 6, 5};
    int rounds[] = {1, 2, 2, 2};
    string positions[] = {"C", "F", "G"};

    int roundIndex = 0;
    double totalCost = 0.0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < rounds[i]; ++j) {
            for (const auto& player : proPlayers) {
                if (find(dreamTeam.begin(), dreamTeam.end(), player) != dreamTeam.end()) {
                    continue;
                }

                ProBasketballPlayer* proPlayer = dynamic_cast<ProBasketballPlayer*>(player.get());
                if (proPlayer) {
                    string pos = proPlayer->getPosition();
                    pos.erase(remove_if(pos.begin(), pos.end(), ::isspace), pos.end());
                    if (pos == positions[roundIndex % 3] && proPlayer->getValue() <= maxPlayerValues[i]) {
                        double newTotalCost = totalCost + proPlayer->getContractValue();
                        if (newTotalCost <= 98000000.0) {
                            cout << "Adding player: " << proPlayer->getPlayerName() << " with value: " << proPlayer->getValue() << " and cost: " << proPlayer->getContractValue() << endl;
                            dreamTeam.push_back(player);
                            totalCost = newTotalCost;
                            break;
                        }
                    }
                }
            }
            roundIndex++;
        }
    }

    cout << "Total Cost: $" << totalCost << endl;
    cout << "dreamteam size: " << dreamTeam.size() << endl;
    return dreamTeam;
}

