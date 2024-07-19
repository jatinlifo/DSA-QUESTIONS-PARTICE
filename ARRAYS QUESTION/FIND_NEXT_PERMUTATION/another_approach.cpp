// For example,  arr = [1,2,3]
//  all permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// return only next permutation
// Input: nums = [1,2,3]
// Output: [1,3,2]

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void nextPermutation(vector<int> &nums , int n)
{
    //find first big element swap1
    int swap1_idx = -1;
    for(int i=n-1; i>0; i--)
    {
        if(nums[i] > nums[i-1])
        {
            swap1_idx = i-1;
            break;
        }
    }
    if(swap1_idx != -1)
    {
        int swap2_idx = swap1_idx;
        for(int j=n-1; j>=0; j--){
            if(nums[j] > nums[swap1_idx]){
                swap2_idx = j;
                break;
            }
        }
        swap(nums[swap1_idx],nums[swap2_idx]);
    }
    reverse(nums.begin()+swap1_idx+1,nums.end());
    return;

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

    nextPermutation(nums,n);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}