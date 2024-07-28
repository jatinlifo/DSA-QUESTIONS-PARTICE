// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
// Example 1:
// Input: nums = [1,2,3,1], k = 3
// Output: true


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
    public:

    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        int n = nums.size();
        unordered_map<int,int> map;
        
        for(int i=0; i<n; i++)
        {
            if(map.find(nums[i]) != map.end()){
                int idx = map[nums[i]];
                int diff = abs(idx-i);
                if(diff <= k){
                    return true;
                }
                else{
                    map[nums[i]] = i;
                }
                
            }
            else{
                map[nums[i]] = i;
            }
        }
        return false;
    }
};

int main ()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++) cin>>nums[i];
    int k;
    cout<<"Enter the k: ";
    cin>>k;

    Solution obj;
    bool ans = obj.containsNearbyDuplicate(nums,k);
    if(ans) cout<<"YES: ";
    else{
        cout<<"NO: ";
    }
    return 0;
}