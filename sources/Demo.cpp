#include <iostream>
#include "League.hpp"
#include "Game.hpp"
#include "Team.hpp"
#include "Schedule.hpp"
#include <random>
#include <algorithm>

using namespace std;
 
int main() {
    Team Rashi = Team("Rashi");
    Team Noah = Team("Noah");
    Team Michal = Team("Michal");
    vector<Team*> teams;
    teams.push_back(&Rashi);
    teams.push_back(&Noah);
    teams.push_back(&Michal);
    League nba = League(teams);

    vector<Team*> res = nba.get_teams();
    cout << "teams:" << endl;
    for(unsigned long i = 0; i < res.size(); i++){
        cout << i+1 << ": " << res[i]->get_name() << " " <<  "skill level: " << res[i]->get_skill_level() << endl;
    }

    Schedule s = Schedule(nba);
    for (unsigned long i = 0; i < s.get_schedule().size(); i++)
    {
        cout << "ROUND " << i+1 << endl;
        cout << "+++++++++++++++++++++++++++++" << endl;
        vector<Game*> round = s.get_round(i);
        for (unsigned long j = 0; j < round.size(); j++)
        {
            cout << j+1 << ": " << round[j]->get_home_team()->get_name() <<  " vs " << round[j]->get_away_team()->get_name() << endl;
        }
    }
        

    



// vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
// cout << "Before rotate:" << endl;
// for (unsigned long i = 0; i < nums.size(); i++)
// {
//     cout << nums[i] << " ";
// }
// cout << endl;
// cout << "After rotate:" << endl;
// int rotR = 2;               
// rotate(nums.begin()+1, nums.begin()+rotR, nums.end());
// for (unsigned long i = 0; i < nums.size(); i++)
// {
//     cout << nums[i] << " ";
// }
// cout << endl;
// rotate(nums.begin()+1, nums.begin()+rotR, nums.end());
// for (unsigned long i = 0; i < nums.size(); i++)
// {
//     cout << nums[i] << " ";
// }
// cout << endl;

    return 0;
}