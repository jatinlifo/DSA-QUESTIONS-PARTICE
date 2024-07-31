#include<iostream>
#include<vector>

using namespace std;

int maximumOF2(vector<int> &nums, int n)
{
    int first_maxi = INT8_MIN;
    int second_maxi = INT8_MIN;

    if(n < 2){
        return -1;
    }

    for(int i=0; i<n; i++)
    {
        if(nums[i] > first_maxi){
            second_maxi = first_maxi;
            first_maxi = nums[i];
        }
        else if(nums[i] > second_maxi && nums[i] != first_maxi){
            second_maxi = nums[i];
        }
    }
    return (second_maxi == INT8_MIN) ? -1 : second_maxi;
}

int main ()
{
    int n;
    cout<<"Enter the size :";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++) cin>>nums[i];

    int ans = maximumOF2(nums,n);
    cout<<"Second maximum value is : "<<ans<<endl;
    return 0;
}