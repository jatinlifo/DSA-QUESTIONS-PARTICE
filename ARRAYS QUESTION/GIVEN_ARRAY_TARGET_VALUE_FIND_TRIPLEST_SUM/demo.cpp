// PROBLEM THREE SUM RETURN TRUE AND FALSE

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    public:

    bool checkTriplestSum(vector<int> &nums, int n, int target)
    {
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++)
        {
            int left = i+1;
            int right = n-1;

            while(left < right)
            {
                int sum = nums[i]+nums[left]+nums[right];
                if(target == sum){
                    return true;
                }
                else if(target < sum){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return false;
    }
};

int main()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++) cin>>nums[i];
    int target; cout<<"Enter the target value: "; cin>>target;
    Solution obj;
    if(obj.checkTriplestSum(nums,n,target))
    {
        cout<<"Yes three sum is present: ";
    }
    else{
        cout<<"No three sum present: ";
    }
    return 0;
}