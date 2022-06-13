#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include  <ctime>
#include <unistd.h>
#include "Team.hpp"

constexpr int THIRTY = 30;
constexpr int SLEEP = 900000;
constexpr int TEAM_S = 20;




using namespace std;
class League{
        vector<Team*> teams;
    public:
        League(vector<Team*> t){
            if(t.size() > (unsigned long)TEAM_S){
                throw invalid_argument("League is at most 20 teams!");
            }
            if(t.size() == (unsigned long)TEAM_S){
                this->teams = t;
            }
            else{
                for(unsigned long i = 0; i < t.size(); i++){
                   this->teams.push_back(t[i]);
                }
                rand_constructor((unsigned long)TEAM_S - t.size());
            }
        }
        League(){
            rand_constructor(TEAM_S);
        }
        void rand_constructor(int n){
            if(n == 0){
                return;
            }
            vector<int> indexes = {0};
            vector<string> b_ball;
            b_ball.push_back("Maccabi Tel Aviv");
            b_ball.push_back("Hapoel Jerusalem");
            b_ball.push_back("Hapoel Holon");
            b_ball.push_back("Hapoel Gilboa Galil");
            b_ball.push_back("Hapoel Fattal Eilat");
            b_ball.push_back("Hapoel Tel Aviv");
            b_ball.push_back("Hapoel Be'er Sheva");
            b_ball.push_back("Hapoel Galil Elyon");
            b_ball.push_back("Maccabi Haifa");
            b_ball.push_back("Hapoel Haifa");
            b_ball.push_back("Ironi Ness Ziona");
            b_ball.push_back("Ironi Nahariya");
            b_ball.push_back("Maccabi Rishon Lezion");
            b_ball.push_back("Maccabi Ironi Ramat Gan");
            b_ball.push_back("Elitzur Ironi Netanya");
            b_ball.push_back("Maccabi Ashdod");
            b_ball.push_back("Ironi Kiryat Ata");
            b_ball.push_back("Hapoel Afula");
            b_ball.push_back("Maccabi Hod haSharon");
            b_ball.push_back("Maccabi Ma'ale Adumim");
            b_ball.push_back("Hapoel Hevel Modi'n");
            b_ball.push_back("Ironi Ashkelon");
            b_ball.push_back("Hapoel Gvat/Yagur");
            b_ball.push_back("Maccabi Raanana");
            b_ball.push_back("Hapoel Ramat Gan");
            b_ball.push_back("Elizur Ashkelon");
            b_ball.push_back("Orlando Magic");
            b_ball.push_back("Los Angeles Clippers");
            b_ball.push_back("Denver Nuggets");
            b_ball.push_back("Portland Trail Blazers");
            for(int i = 0; i < n; i++){
                unsigned long index = (unsigned long)rand() % THIRTY; //random number between 0-30
                while (find(indexes.begin(), indexes.end(), index) != indexes.end()){ //team name is already taken
                    usleep(SLEEP);
                    index = (unsigned long)rand() % THIRTY; //random number between 0-30
                }
                Team* p_team = new Team(b_ball[index]);
                this->teams.push_back(p_team);
                indexes.emplace_back(index);
            }
        }
        vector<Team*> get_teams();
};

