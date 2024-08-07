// Given an array arr of size n−1 that contains distinct integers in the range of 1 to n (inclusive), find the missing element. The array is a permutation of size n with one element missing. Return the missing element.
// Examples:
// Input: n = 5, arr[] = [1,2,3,5]
// Output: 4
// Explanation : All the numbers from 1 to 5 are present except 4

#include<iostream>
#include<vector>

using namespace std;

int missingNumber(vector<int> &nums, int n)
{
    int sum = 0;
    for(int i=0; i<nums.size(); i++)
    {
        sum += nums[i];
    }
    //using formula n natural number 
    int s = n*(n+1)/2;
    return s-sum;
}

int main ()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element's: ";
    for(int i=0; i<n-1; i++) cin>>nums[i];

    int ans = missingNumber(nums,n);
    cout<<"Missing number is :"<<ans<<endl;
    return 0;
}