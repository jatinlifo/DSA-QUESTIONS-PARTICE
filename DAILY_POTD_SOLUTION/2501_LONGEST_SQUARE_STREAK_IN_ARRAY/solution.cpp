// You are given an integer array nums. A subsequence of nums is called a square streak if:
// The length of the subsequence is at least 2, and
// after sorting the subsequence, each element (except the first element) is the square of the previous number.
// Return the length of the longest square streak in nums, or return -1 if there is no square streak.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: nums = [4,3,6,16,8,2]
// Output: 3
// Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
// - 4 = 2 * 2.
// - 16 = 4 * 4.
// Therefore, [4,16,2] is a square streak.
// It can be shown that every subsequence of length 4 is not a square streak.
// Example 2:

// Input: nums = [2,3,5,6,7]
// Output: -1
// Explanation: There is no square streak in nums so return -1.

// Constraints:
// 2 <= nums.length <= 105
// 2 <= nums[i] <= 105

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution{
    public:

    int maxStreakSquare(vector<int>& nums){

        int n = nums.size();
        int ans = 0;
        unordered_set<int> st(nums.begin(),nums.end());

        for(int i=0; i<n; i++){
            
            int count = 0;
            long long ele = nums[i];

            while(st.find(ele) != st.end()){
                count++;
                if(ele*ele > 1e5){
                    break;
                }
                ele = ele*ele;
            }
            ans = max(count,ans);
        }
        return ans;
    }
};

int main () {

    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element's in array : ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    Solution obj;
    int ans = obj.maxStreakSquare(nums);

    cout<<"Maximum streak is "<<ans<<endl;
    return 0;
}