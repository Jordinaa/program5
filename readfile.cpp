#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include "collegeplayer.h"
#include "proplayer.h"
using namespace std;

void readNCAAPlayers(string fileName, vector<shared_ptr<BasketballPlayer>>& players, vector<string>& errors) {
    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Unable to open file: " << fileName << endl;
        exit(1);
    }

    ofstream outFile("output.txt");
    if (!outFile) {
        cerr << "Unable to open file: output.txt" << endl;
        exit(1);
    }

    string line;
    getline(inFile, line);  // Skip the header line

    while (getline(inFile, line)) {
        stringstream ss(line);
        string playerName;
        int games, trb, ast, stl, blk, tov, pts;
        float efg;
        string team;

        try {
            getline(ss, playerName, ',');
            if (playerName.front() == '\"' && playerName.back() != '\"') {
                string temp;
                while (getline(ss, temp, ',')) {
                    playerName += ',' + temp;
                    if (playerName.back() == '\"') {
                        break;
                    }
                }
            }

            string value;
            getline(ss, value, ',');
            games = stoi(value);

            getline(ss, value, ',');
            efg = stof(value);

            getline(ss, value, ',');
            trb = stoi(value);

            getline(ss, value, ',');
            ast = stoi(value);

            getline(ss, value, ',');
            stl = stoi(value);

            getline(ss, value, ',');
            blk = stoi(value);

            getline(ss, value, ',');
            tov = stoi(value);

            getline(ss, value, ',');
            pts = stoi(value);

            getline(ss, team, ',');
            if (games > 5) {
                players.push_back(make_shared<CollegeBasketballPlayer>('C', playerName, games, efg, trb, ast, stl, blk, tov, pts, team));
            } else {
                string errorMessage = playerName + " CollegeBasketballPlayer: Insufficient games played (" + to_string(games) + ")";
                errors.push_back(errorMessage);
                outFile << errorMessage << endl;
            }
        } catch (const invalid_argument& e) {
            string errorMessage = playerName + " CollegeBasketballPlayer: Invalid argument (" + string(e.what()) + ")";
            errors.push_back(errorMessage);
            outFile << errorMessage << endl;
        } catch (const exception& e) {
            string errorMessage = playerName + " CollegeBasketballPlayer: Error parsing data (" + string(e.what()) + ")";
            errors.push_back(errorMessage);
            outFile << errorMessage << endl;
        }
    }

    inFile.close();
    outFile.close();
}

void readProPlayers(string fileName, vector<shared_ptr<BasketballPlayer>>& players, vector<string>& errors) {
    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Unable to open file: " << fileName << endl;
        exit(1);
    }

    string line;
    getline(inFile, line);  // Skip the header line

    while (getline(inFile, line)) {
        stringstream ss(line);
        string playerName;
        int games, trb, ast, stl, blk, tov, pts, age, years;
        float efg;
        string position;

        try {
            getline(ss, playerName, ',');
            if (playerName.front() == '\"' && playerName.back() != '\"') {
                string temp;
                while (getline(ss, temp, ',')) {
                    playerName += ',' + temp;
                    if (playerName.back() == '\"') {
                        break;
                    }
                }
            }

            string value;
            getline(ss, value, ',');
            games = stoi(value);
            if (games < 6) {
                throw invalid_argument("Insufficient games played");
            }

            getline(ss, value, ',');
            efg = stof(value);

            getline(ss, value, ',');
            trb = stoi(value);

            getline(ss, value, ',');
            ast = stoi(value);

            getline(ss, value, ',');
            stl = stoi(value);

            getline(ss, value, ',');
            blk = stoi(value);

            getline(ss, value, ',');
            tov = stoi(value);

            getline(ss, value, ',');
            pts = stoi(value);

            getline(ss, value, ',');
            age = stoi(value);

            getline(ss, value, ',');
            years = stoi(value);

            getline(ss, position, ',');
            if (position.empty()) {
                throw invalid_argument("Position field is empty");
            }

            players.push_back(make_shared<ProBasketballPlayer>('P', playerName, games, efg, trb, ast, stl, blk, tov, pts, years, position));
        } catch (const exception& e) {
            errors.push_back(playerName + " ProBasketballPlayer: " + e.what());
        }
    }
    inFile.close();
}










