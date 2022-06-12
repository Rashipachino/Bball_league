#include <iostream>
#include "League.hpp"
#include "Game.hpp"
#include "Team.hpp"
#include "Schedule.hpp"
#include <random>
#include <algorithm>
#include <functional>

using namespace std;
 
int main() {
    srand(time(0));
    Team Rashi = Team("Rashi");
    Team Noah = Team("Noah");
    Team Michal = Team("Michal");
    vector<Team*> teams;
    teams.push_back(&Rashi);
    teams.push_back(&Noah);
    teams.push_back(&Michal);
    League nba = League(teams);

    vector<Team*> res = nba.get_teams();
    cout << "******************************" << endl;
    cout << "TEAMS" << endl;
    cout << "******************************" << endl;
    for(unsigned long i = 0; i < res.size(); i++){
        cout << i+1 << ": " << res[i]->get_name() << " " <<  "skill level: " << res[i]->get_skill_level() << endl;
    }

    Schedule s = Schedule(nba);
    for (unsigned long i = 0; i < s.get_schedule().size(); i++)
    {
        cout << "+++++++++++++++++++++++++++++" << endl;
        cout << "ROUND " << i+1 << endl;
        cout << "+++++++++++++++++++++++++++++" << endl;
        vector<Game*> round = s.get_round(i);
        for (unsigned long j = 0; j < round.size(); j++)
        {
            cout << j+1 << ": " << round[j]->get_home_team()->get_name() <<  " vs " << round[j]->get_away_team()->get_name() << endl;
        }
    }
    cout << "----------------------------" << endl;
    cout << "STATS" << endl;
    cout << "----------------------------" << endl;
    vector<Team*> ranking = s.get_stats();
    for(unsigned long i = 0; i < ranking.size(); i++){
        cout << i+1 << ": " << ranking.at(i)->get_name() << " #wins: " << ranking.at(i)->get_wins() << " score: " << ranking.at(i)->get_points_scored() << endl;
    }   
    cout << ">>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "TOP 3" << endl;
    vector<Team*> top_3 = s.top_picks(3);
    for(auto i : top_3){
        cout << i->get_name() << endl;
    } 
    cout << ">>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "Longest win streak: " << s.longest_w_streak() << endl;
    cout << "Longest lose streak: " << s.longest_l_streak() << endl;
    cout << "Number of teams who scored more points overall than what they lost: " << s.scored_over_lost() << endl;
    cout << "Number of teams who scored less points overall than what they lost: " << s.lost_over_scored() << endl;
    cout << "Number of teams who won more games than they lost: " << s.wins_over_losses() << endl;
    cout << "Number of teams who lost more games than they won: " << s.loses_over_wins() << endl;
    cout << "Number of teams who lost the same amount of games than they won: " << s.tie_wins_losses() << endl;



    return 0;
}