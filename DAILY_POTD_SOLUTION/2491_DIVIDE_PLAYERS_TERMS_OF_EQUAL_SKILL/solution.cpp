// You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.
// The chemistry of a team is equal to the product of the skills of the players on that team.
// Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.
// Example 1:
// Input: skill = [3,2,5,1,3,4]
// Output: 22
// Explanation: 
// Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
// The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
// Example 2:

// Input: skill = [3,4]
// Output: 12
// Explanation: 
// The two players form a team with a total skill of 7.
// The chemistry of the team is 3 * 4 = 12.
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        long long ans = 0;
        int n = skill.size();
        int N = n/2;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += skill[i];
        }
        
        if(sum%N != 0){
            return -1;
        }
        int target =  sum/N;
        unordered_map<int,int> map;
        for(int i=0; i<n; i++){
            map[skill[i]]++;
        }
        for(int i=0; i<n; i++){
            int ele = target - skill[i];
            if(map.find(ele) != map.end() && map[ele] > 0 && map[skill[i]] > 0){
                ans += skill[i]*ele;
                map[ele]--;
                map[skill[i]]--;
            }
        }
        for(auto it: map){
            if(it.second > 0){
                return -1;
            }
        }
        return (ans == 0 ? -1 : ans);
    }
};

int main() {

    int n;
    cout<<"Enter the size : ";
    cin>>n;

    vector<int> skill(n);
    cout<<"Enter the element's : ";
    for(int i=0; i<n; i++){
        cin>>skill[i];
    }

    Solution obj;
    long long ans = obj.dividePlayers(skill);

    cout<<"Answer is : "<<ans<<endl;
    
    return 0;
}