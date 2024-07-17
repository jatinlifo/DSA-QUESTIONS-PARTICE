// Given an integer array arr[]. Find the contiguous sub-array(containing at least one number) that has the maximum sum and return its sum.

// Examples:
// Input: arr[] = [1, 2, 3, -2, 5]
// Output: 9
// Explanation: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:

     long long maxSubarrayofSum(vector<int> &arr) {
       
       int resFirst = arr[0];
       int maxSum  = arr[0];
       
       for(int i=1;i<arr.size();i++)
       {
           resFirst = max(resFirst + arr[i] , arr[i]);
           if(resFirst > maxSum){
               maxSum = resFirst;
           }
       }
       return maxSum;
    }
};

int main ()
{
    int n;
    cout<<"Enter the array size:";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elemets:";
    
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    Solution obj;

    long long  int ans = obj.maxSubarrayofSum(v);
    
    cout<<"Maximum Subarray sum: "<<ans<<endl;
    return 0;
}