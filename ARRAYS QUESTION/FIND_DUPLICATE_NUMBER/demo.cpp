// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// Example:Input: nums = [1,3,4,2,2]   Output: 2

//USING TWO POINTER APPROACH SLOW || FAST

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:

    int duplicateNumber(vector<int> &nums)
    {
        int ans = 0;
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = nums[0];

        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main ()
{
    int n;
    cout<<"Enter the array size:";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the element:";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    Solution obj;
    int ans = obj.duplicateNumber(v);
    cout<<"Dublicate Number: "<<ans<<endl;

    return 0;
}