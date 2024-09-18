// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
// Since the result may be very large, so you need to return a string instead of an integer.
// Example 1:
// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution{
    public:

    static bool myComprator(int &a, int &b)
    {
        string A = to_string(a);
        string B = to_string(b);

        return  A+B > B+A;
    }

    string largestNumber(vector<int>& nums)
    {
        int n = nums.size();
        string ans = "";
        sort(nums.begin(),nums.end(), myComprator);

        for(int i=0; i<n; i++)
        {
            ans += to_string(nums[i]);
        }
        if(ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};

int main () 
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element's of array : ";
    for(int i=0; i<n; i++) cin>>nums[i];

    Solution obj;
    string res = obj.largestNumber(nums);
    cout<<"Answer is : "<<res<<endl;
    return 0;
}