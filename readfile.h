#pragma once
#include "proplayer.h"
#include "collegeplayer.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// vector<ProBasketballPlayer> readProPlayers(const string& filename);
// vector<CollegeBasketballPlayer> readNCAAPlayers(const string& filename);
void readProPlayers(string fileName, vector<shared_ptr<BasketballPlayer>>& players, vector<string>& errors);
void readNCAAPlayers(string fileName, vector<shared_ptr<BasketballPlayer>>& players, vector<string>& errors);