#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int> &nums, int n, int target)
{
    int left = 0;
    int right = n-1;

    while(left<=right)
    {
        int mid = left + (right-left)/2;

        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] > target)
        {
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return -1;
}

int main ()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++) cin>>nums[i];
    
    int target;
    cout<<"Enter the target value: ";
    cin>>target;
    int ans = binarySearch(nums,n,target);

    cout<<"Idx is :"<<ans;
}

//TIME COMPLEXITY = O(N)
//SPACE COMPLEXITY = O(1)