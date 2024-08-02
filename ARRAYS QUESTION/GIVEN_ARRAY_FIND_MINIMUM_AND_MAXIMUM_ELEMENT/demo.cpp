#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int>& arr) {
        
        pair<long long, long long > ans;
        ans.first = INT8_MAX;
        ans.second = INT8_MIN;
        
        for(int i=0; i<arr.size(); i++)
        {
            ans.first = min(ans.first,arr[i]);
        }
        for(int i=0; i<arr.size(); i++)
        {
            ans.second = max(ans.second,arr[i]);
        }
        return ans;
    }
};

int main ()
{
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<long long int > nums(n);
    cout<<"Enter the elment's : ";
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution obj;
    pair<long long , long long > ans = obj.getMinMax(nums);

    cout<<"Minimum is : "<<ans.first<<" "<<"Maximum is : "<<ans.second<<" "<<endl;
    return 0;
}