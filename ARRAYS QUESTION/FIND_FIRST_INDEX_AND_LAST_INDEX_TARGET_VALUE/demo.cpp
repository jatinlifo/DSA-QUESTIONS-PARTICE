// using binary search TC = O(logn);

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    vector<int> searchIndex(vector<int> &nums, int target)
    {
        vector<int> ans(2, -1);
        int n = nums.size();
        int left = 0;
        int right = n-1;
        

        //find left subarray ma index
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid]>=target){
                if(nums[mid] == target){
                    ans[0] = mid;
                }
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        left = 0;
        right = n-1;
        //find right subarray ma index;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                if(nums[mid] == target){
                    ans[1] = mid;
                }
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cout<<"Enter the array size:";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cout<<"Enter target element:";
    cin>>target;
    
    Solution obj;
    vector<int> result(2);
    result  = obj.searchIndex(nums,target);
    cout<<"firs idx: "<<result[0]<<" "<<"last idx: "<<result[1]<<" ";
    return 0;
}