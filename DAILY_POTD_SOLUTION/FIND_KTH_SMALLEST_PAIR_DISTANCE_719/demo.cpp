// The distance of a pair of integers a and b is defined as the absolute difference between a and b.
// Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

// Example 1:
// Input: nums = [1,3,1], k = 1
// Output: 0
// Explanation: Here are all the pairs:
// (1,3) -> 2
// (1,1) -> 0
// (3,1) -> 2
// Then the 1st smallest distance pair is (1,1), and its distance is 0.

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    int kthSmallestPairDistance(vector<int>& nums, int k)
    {
        int n =  nums.size();
        //find given array sa maximum element;
        int maxi = INT8_MIN;
        for(int i=0;i<n;i++) maxi = max(nums[i],maxi);

        //create the array to store the every pair distance or frequency 
        vector<int> distP(maxi+1,0);
        //find all pair 
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int val = abs(nums[i]-nums[j]);
                distP[val]++;
            }
        }
        for(int i=0; i<distP.size(); i++)
        {
            k -= distP[i];
            if(k <= 0){
                return i;
            }
        }
        return -1;
    }
};

int main ()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element's : ";
    for(int i=0; i<n; i++) cin>>nums[i];
    int k;
    cout<<"Enter the K : ";
    cin>>k;
    Solution obj;
    int ans = obj.kthSmallestPairDistance(nums,k);

    cout<<k<<"th Smallest pair distance is : "<<ans<<endl;

    return 0;
}

// TC = (O(N^N)+(N)) = O(N^N):
// SC = O(M)  where m is given array max element