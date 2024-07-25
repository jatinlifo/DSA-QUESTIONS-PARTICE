#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    vector<int> CountSort(vector<int> &nums, int n)
    {
        int max_ele = INT8_MIN;
        int min_ele = INT8_MAX;
        for(int i=0;i<n;i++) max_ele = max(max_ele,nums[i]);
        for(int i=0;i<n;i++) min_ele = min(min_ele,nums[i]);

        int range = max_ele - min_ele + 1;
        //create freq array
        vector<int> freq(range,0);
        //count frequencies
        for(int i=0;i<n;i++)
        {
            freq[nums[i] - min_ele]++;
        }
        //calculate the commultaive frequencies
        for(int i=1;i<range;i++)
        {
            freq[i] += freq[i-1];
        }
        vector<int> ans(n);
        //place the elements int sorted order
        for(int i=n-1;i>=0;i--)
        {
            ans[--freq[nums[i] - min_ele]]= nums[i];
        }
        return ans;
    }
};

int main ()
{
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution obj;
    vector<int> ans = obj.CountSort(nums,n);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// TC = O(n+range):
// SC = O(n+range):