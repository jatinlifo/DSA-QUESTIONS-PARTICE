// For example,  arr = [1,2,3]
//  all permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// return only next permutation
// Input: nums = [1,2,3]
// Output: [1,3,2]

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(),nums.end());
    return ;
}

int main ()
{
    int n;
    cout<<"Enter the array size:";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    nextPermutation(nums);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}