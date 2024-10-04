#include <bits/stdc++.h>
using namespace std;

/*
Problem Link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/?envType=daily-question&envId=2024-10-04

Time Complexity : O(N)
Space Complexity : O(1)

- For this approach the sum is going to be the maximum + minimum element,
  this is because we need to find a compliment per element to be equal to a sum
  and summing any 2 large numbers will ensure smaller numbers can't find a pair.
- First we initialize a map (array for values 1 - 1000) with zeroes and iterate
  through skill array populating frequency and finding minumum and maximum (mini & maxi).
- Now iterate through the map, if an index i is non zero and if it's compliement
  (checki = maxi + mini - i) exists and is larger than than it we can make pairs so multiply
  them and multiply by the count of the current index as we get that many pairs and 
  store this sum in a variable chemistry. If the compliment checki is lesser we can't
  make pairs so we return -1.
- Edge case is if the index is it's pair itself (i == checki) then we check if frequency
  is even for pairs and add only half of the frequency. If it's not even then return -1.
- Subtract checki frequency by i frequency in map, make i frequency 0 and continue till i <= maxi.
- Return the chemistry in the end (all pairs made).
*/
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int mini = INT_MAX, maxi = INT_MIN, checki;
        long long chemistry = 0;
        long long mp[1001] = {0};
        for(auto x : skill) {
            mp[x]++;
            mini = min(x,mini);
            maxi = max(x,maxi);
        }
        for(int i=1;i<=maxi;i++) {
            if(mp[i] != 0) {
                checki = maxi + mini - i;
                if(mp[checki] < mp[i]) {
                    return -1;
                }
                if(i == checki) {
                    if((mp[i] % 2) == 0) {
                        chemistry += ((mp[i] * i * checki) / 2);
                    }
                    else {
                        return -1;
                    }
                }
                else {
                    chemistry += (mp[i] * i * checki);
                }
                mp[checki] -= mp[i];
                mp[i] = 0;
            }
        }
        return chemistry;
    }
};

int main() {
    //Testcases
    vector<int> tc1 = {3,2,5,1,3,4},
    tc2 = {3,4},
    tc3 = {2,1,3,1};
    
    //Object Initialization
    Solution solution;
    cout << solution.dividePlayers(tc1) << "\n";
    cout << solution.dividePlayers(tc2) << "\n";
    cout << solution.dividePlayers(tc3) << "\n";
    return 0;
}