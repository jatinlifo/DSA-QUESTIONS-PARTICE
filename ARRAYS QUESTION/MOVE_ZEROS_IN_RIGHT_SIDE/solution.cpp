// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.

// Example 1:
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    void moveZerosRightSide(vector<int>& nums)
    {
        int n = nums.size();

        int j = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] != 0){
                swap(nums[j],nums[i]);
                j++;
            }
        }
    }
};

int main ()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element's in array : ";
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }
    Solution obj;
    obj.moveZerosRightSide(nums);

    for(int i=0; i<n; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}