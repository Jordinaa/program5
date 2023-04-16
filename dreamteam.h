#pragma once
#include "player.h"
#include "collegeplayer.h"
#include "proplayer.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>
using namespace std;

bool comparePlayers(const shared_ptr<BasketballPlayer>& a, const shared_ptr<BasketballPlayer>& b);

void printNCAADreamTeam(const string& title, const vector<shared_ptr<BasketballPlayer>>& dreamTeam);
void printMixedDreamTeam(const string& title, const vector<shared_ptr<BasketballPlayer>>& dreamTeam);
void printAllProTeam(const string& title, const vector<shared_ptr<BasketballPlayer>>& team);

vector<shared_ptr<BasketballPlayer>> createAllNCAADreamTeam(vector<shared_ptr<BasketballPlayer>>& players);
vector<shared_ptr<BasketballPlayer>> createMixedDreamTeam(vector<shared_ptr<BasketballPlayer>>& players);
vector<shared_ptr<BasketballPlayer>> createAllProDreamTeam(vector<shared_ptr<BasketballPlayer>>& players);
