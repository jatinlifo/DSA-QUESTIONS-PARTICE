// Given an array of positive integers nums and a positive integer target, return the minimal length of a 
// subarray
//  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
// Example 1:
// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:
// Input: target = 4, nums = [1,4,4]
// Output: 1    leetcode - 209  


#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    int minimumSubarraylength(vector<int>& nums, int target)
    {
        int n = nums.size();
        int sum = 0;
        int minLeng = INT8_MAX;
        int i = 0;
        int j = 0;

        while(j < n)
        {
            sum += nums[j];

            while(sum >= target)
            {
                minLeng = min(minLeng,j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return (minLeng == INT8_MAX ? 0 : minLeng);
    }
};

int main ()
{
    int n;
    cout<<"Enter the array size : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element's : ";
    for(int i=0; i<n; i++) cin>>nums[i];
    int target;
    cout<<"Enter the target value : ";
    cin>>target;

    Solution obj;
    int size = obj.minimumSubarraylength(nums,target);
    cout<<"Minimum Subarray length is : "<<size<<endl;

    return 0;
}