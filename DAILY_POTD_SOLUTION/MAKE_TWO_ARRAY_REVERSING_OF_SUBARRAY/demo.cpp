// You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.
// Return true if you can make arr equal to target or false otherwise.
// Example 1:
// Input: target = [1,2,3,4], arr = [2,4,1,3]
// Output: true
// Explanation: You can follow the next steps to convert arr to target:
// 1- Reverse subarray [2,4,1], arr becomes [1,4,2,3]
// 2- Reverse subarray [4,2], arr becomes [1,2,4,3]
// 3- Reverse subarray [4,3], arr becomes [1,2,3,4]
// There are multiple ways to convert arr to target, this is not the only way to do so.

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution{
    public:

    bool canBeEqual(vector<int> &nums, vector<int> &target)
    {

        if(nums.size() != target.size()){
            return false;
        }
        unordered_map<int,int> map;

        for(int i=0; i<nums.size(); i++)
        {
            map[nums[i]]++;
        }
        for(int i=0; i<target.size(); i++)
        {
            if(map.find(target[i]) == map.end())
            {
                return false;
            }
            else{
                map[target[i]]--;
                if(map[target[i]] == 0)
                {
                    map.erase(target[i]);
                }
            }
        }
        return true;
    }
};

int main ()
{
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element's : ";
    for(int i=0;i<n;i++) cin>>nums[i];

    int m;
    cout<<"Enter the target array size: ";
    cin>>m;
    vector<int> target(m);
    cout<<"Enter the element's : ";
    for(int i=0;i<m;i++) cin>>target[i];

    Solution obj;
    bool ans = obj.canBeEqual(nums,target);
    if(ans)
    cout<<"YES ARRAY'S IS  EQUAL :";
    else
    cout<<"ARRAY'S NOT EQUAL";
    return 0;
}

// ANOTHER APPROACH USING SORTING FUNCTION 