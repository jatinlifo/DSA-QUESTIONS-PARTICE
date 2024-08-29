// Given two integer arrays nums1 and nums2, return an array of their 
// intersection
// . Each element in the result must be unique and you may return the result in any order.
// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.
 
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
    public:

    vector<int> interSectiionOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> res;
        unordered_map<int,int> map;

        for(int ele:nums1)
        {
            map[ele];
        }
        for(int i=0; i<nums2.size(); i++)
        {
            if(map.find(nums2[i]) != map.end())
            {
                res.push_back(nums2[i]);
                map.erase(nums2[i]);
            }
        }
        return res;
    }
};

int main ()
{
    int n;
    cout<<"Enter the size of first array : ";
    cin>>n;
    vector<int> nums1(n);
    cout<<"Enter the element's of first array : ";
    for(int i=0; i<n; i++) cin>>nums1[i];

    int n2;
    cout<<"Enter the size of second array : ";
    cin>>n2;
    vector<int> nums2(n2);
    cout<<"Enter the element's of second array : ";
    for(int i=0; i<n2; i++) cin>>nums2[i];
    
    Solution obj;
    vector<int> ans = obj.interSectiionOfArrays(nums1,nums2);

    cout<<"Intersection Elements is : "<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// This is try to Set Data structure 