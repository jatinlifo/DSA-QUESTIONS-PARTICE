// 238. Product of Array Except Self
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.
// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
// Constraints:
// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
// T.c O(n) , S.c O(n)

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            
            int n = nums.size();
            vector<int> prefix(n),suffix(n),ans(n);
            prefix[0] = nums[0];
            suffix[n-1] = nums[n-1];
            
            for(int i=1; i<n; i++){
                prefix[i] = prefix[i-1] * nums[i];
            }
            for(int i=n-2; i>=0; i--){
                suffix[i] = suffix[i+1] * nums[i];
            }
            ans[0] = suffix[1];
            ans[n-1] = prefix[n-2];
            for(int i=1; i<n-1; i++){
                ans[i] = suffix[i+1] * prefix[i-1];
            }
            return ans;
        }
    };

int main () {

    int n;
    cout<<"Enter the size :";
    cin >> n;
    vector<int> nums(n);
    cout<<"Enter the Elements : ";
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    cout<<endl;
    Solution obj;
    vector<int> ans = obj.productExceptSelf(nums);
    cout<<"Answer is:"<<endl;
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

