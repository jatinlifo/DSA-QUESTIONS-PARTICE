// You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.
// Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 10^9 + 7.
// Example 1:
// Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
// Output: 13 
// Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    public:

    int rangeSum(vector<int> &nums, int left , int right)
    {
        vector<long long> temp;

        for(int i=0; i<nums.size(); i++)
        {
            long long sum = 0;
            for(int j=i; j<nums.size(); j++)
            {
                sum += nums[j];
                temp.push_back(sum);
            }
        }
        
       
        sort(temp.begin(),temp.end()); 

        //print the element's just understanding 
        for(int i=0; i<temp.size(); i++)
        {
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        int ans = 0;
        int mod = 1000000007;  // not overflow integer range given question
        for(int i=left-1; i<right; i++)
        {
            ans += temp[i];
        }
        return ans % mod;
    }
};

int main ()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element's :";
    for(int i=0;i<n;i++) cin>>nums[i];
    int left,right;
    cout<<"Enter the left and right index: ";
    cin>>left >> right;

    Solution obj;
    int res = obj.rangeSum(nums,left,right);
    cout<<"SUM IS : "<<res<<endl;
    return 0;
}