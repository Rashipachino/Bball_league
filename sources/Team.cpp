#include <iostream>
#include "Team.hpp"

using namespace std;

void Team::streak_update(int res){ //1 means team won, 0 means lost
    if(res == 1){ //team won
        this->wins++;
        this->win_streak++;
        if(win_streak > longest_win_streak){
            longest_win_streak = win_streak; //updates longest streak
        }
    lose_streak = 0;
    }
    else{
        this->loses++;
        this->lose_streak++;
        if(lose_streak > longest_lose_streak){
            longest_lose_streak = lose_streak;
        }
        win_streak = 0;
    }
}
void Team::points_update(int won, int lost){
    this->points_scored += won;
    this->points_lost += lost;
}
string Team::get_name(){
    return this->name;
}
double Team::get_skill_level() const{
    return this->skill_level;
}
int Team::get_points_scored() const{
    return this->points_scored;
}        
int Team::get_points_lost() const{
    return this->points_lost;
}
int Team::get_longest_win_streak() const{
    return longest_win_streak;
}
int Team::get_longest_lose_streak() const{
    return this->longest_lose_streak;
}
int Team::get_wins() const{
    return this->wins;
}
int Team::get_loses() const{
    return this->loses;
}

