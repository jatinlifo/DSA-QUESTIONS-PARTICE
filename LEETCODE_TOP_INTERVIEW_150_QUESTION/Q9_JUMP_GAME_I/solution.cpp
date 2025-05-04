// 55. Jump Game
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index
// Constraints:
// 1 <= nums.length <= 104
// 0 <= nums[i] <= 105

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        
    // Approach 1 Top Down 
    bool solve(vector<int>& nums, int i,vector<int>& dp) {
        
        if(i >= nums.size()-1){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int jump = nums[i];
        for(int j=1; j<=jump; j++){
            if(solve(nums,i+j,dp)){
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

        bool canJump(vector<int>& nums) {
            
            // vector<int> dp(nums.size(),-1);
            // return solve(nums,0,dp);
            //Approach 2 bottom up 
            int n = nums.size();
            int maxJump = 0;
    
            for(int i=0; i<n; i++){
                if(i > maxJump){
                    return false;
                }
                maxJump = max(maxJump,nums[i] + i);
            }
            return true;
        }
    };

int main () {

    int n;
    cout<<"Enter the number of elements in array : ";
    cin >> n;
    vector<int> nums(n);
    cout<<"Enter the elements : ";
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    Solution obj;
    bool ans = obj.canJump(nums);

    if(ans){
        cout<<"Yes you reach last index : "<<endl;
    }else{
        cout<<"NO";
    }
    return 0;
}