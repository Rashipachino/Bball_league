#include <iostream>
#include "Team.hpp"

using namespace std;

bool Team::operator==(const Team other) const{
    return this->name == other.name;
}
bool Team::operator!=(const Team other) const{
    return this->name != other.name;
}