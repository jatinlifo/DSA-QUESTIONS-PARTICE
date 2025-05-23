// 45. Jump Game II
// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

// Example 1
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:
// Input: nums = [2,3,0,1,4]
// Output: 2

// Constraints:
// 1 <= nums.length <= 104
// 0 <= nums[i] <= 1000
// It's guaranteed that you can reach nums[n - 1].


#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            
            int jump = 0;
            int pos = 0;
            int des = 0;
    
            for(int i=0; i<nums.size()-1; i++)
            {
                des = max(des , nums[i] + i);
                if(pos == i){
                    pos = des;
                    jump++;
                }
            }
            return jump;
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
    int ans = obj.jump(nums);
    cout<<"Minimum jump is : "<<ans<<endl;
    return 0;
}