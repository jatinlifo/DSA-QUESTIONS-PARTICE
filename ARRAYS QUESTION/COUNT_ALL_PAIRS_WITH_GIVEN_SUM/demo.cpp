// Given an array arr, and an integer k, find the number of pairs of elements in the array whose sum is k.
// Examples:
// Input: k = 6, arr[] = [1, 5, 7, 1]
// Output: 2
// Explanation: 
// arr[0] + arr[1] = 1 + 5 = 6 
// and arr[1] + arr[3] = 5 + 1 = 6  pair  = 2

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
    public:

    int countPair(vector<int> &nums, int n, int k)
    {
        unordered_map<int,int> map;
        int pair = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(map.find(k-nums[i]) != map.end()){
                
                pair += map[k-nums[i]];
            }
            map[nums[i]]++;
        }
        return pair;   
    }
};

int main ()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the element: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int k;
    cout<<"Enter the target sum: ";
    cin>>k;

    Solution obj;
    int res = obj.countPair(nums,n,k);
    cout<<"Total pair: "<<res<<endl;

    return 0;
}


