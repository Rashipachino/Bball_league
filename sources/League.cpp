#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <unistd.h>
#include "Team.hpp"
#include "League.hpp"
using namespace std;

vector<Team*> League::get_teams(){
    return this->teams;
} 