#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    void merge(vector<int> &nums, int left, int mid, int right, vector<int> &ans)
    { 
    
        int i = left;
        int j = mid + 1;
        int k = left;
        
        while(i<=mid && j<=right){
            if(nums[i] <= nums[j]){
                ans[k++] = nums[i++];
            }
            else{
                ans[k++] = nums[j++];
            }
        }
        while(i<=mid){
            ans[k++] = nums[i++];
        }
        while(j<=right){
            ans[k++] = nums[j++];
        }
        for(int i=left; i<=right; i++)
        {
            nums[i] = ans[i];
        }
    }
 
    void mergSort(vector<int> &nums, int left , int right, vector<int> &ans)
    {
        if(left >= right)
        {
            return;
        }
        int mid = (left + right)/2;
        mergSort(nums,left,mid,ans);
        mergSort(nums,mid+1,right,ans);
        merge(nums,left,mid,right,ans);
    }

    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1){
            return nums;
        }
        vector<int> ans(n) ;
        mergSort(nums,0,n-1,ans);

        return ans;
    }
};

int main ()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution obj;
    vector<int> ans = obj.sortArray(nums);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}