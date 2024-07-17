// // Given an array arr[] denoting heights of N towers and a positive integer K.
// // For each tower, you must perform exactly one of the following operations exactly once.
// // Increase the height of the tower by K
// // Decrease the height of the tower by K
// // Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

// Input:
// K = 2, N = 4 Arr[] = {1, 5, 8, 10}
// Output: 5 // Explanation: {1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}. 
// The difference smallest is 8-3 = 5.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MinDiffIs(vector<int> &arr, int n, int k) {

        sort(arr.begin(),arr.end());
        int mini = arr[0];
        int maxi = arr[n-1];
        int res = maxi - mini;
        
        for(int i=1; i<n; i++)
        {
            maxi = max(arr[i-1] +k, arr[n-1] - k); //if kya last or minimize ho sakta hai
            mini = min(arr[i] -k, arr[0] + k);  // if start sa or bada kar sakta hai 
            if(mini < 0) continue;
            res = min(res, maxi - mini);   // check kon minimum hai
        }
        return res;
    }

int main ()
{
    int n;
    cout<<"Enter the tower size:";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter element:";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int k;
    cout<<"Enter k:";
    cin>>k;

    int ans = MinDiffIs(v,n,k) ;
    cout<<"Minimum is : "<<ans;

    return 0;
}
