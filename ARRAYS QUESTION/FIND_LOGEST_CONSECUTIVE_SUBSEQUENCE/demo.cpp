// Given an array of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
// Example 1: Input:// N = 7  a[] = {2,6,1,9,4,5,3}
// Output: 6
// Explanation:
// The consecutive numbers here
// are 1, 2, 3, 4, 5, 6. These 6 / numbers form the longest consecutive subsquence

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution{
    public:

    int longestSequence(vector<int> &nums, int n)
    {
        unordered_set<int> set;
        for(int i=0;i<n;i++)
        {
            set.insert(nums[i]);
        }
        int longest = 0;
        for(int i=0;i<n;i++)
        {
            if(set.find(nums[i]-1) == set.end())
            {
                int count = 1;

                while(set.find(nums[i]+1) != set.end())
                {
                    count++;
                }
                longest = max(count,longest);
            }
        }
        return longest;
    }
};

int main ()
{
    int n;
    cout<<"Enter the size:";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    Solution obj;
    int ans = obj.longestSequence(nums,n);
    cout<<"Longest Subsquence: "<< ans<<endl;
    return 0;
}
