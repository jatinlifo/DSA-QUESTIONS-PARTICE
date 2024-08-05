// A distinct string is a string that is present only once in an array.
// Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".

// Note that the strings are considered in the order in which they appear in the array.
// Example 1:

// Input: arr = ["d","b","c","b","c","a"], k = 2
// Output: "a"
// Explanation:
// The only distinct strings in arr are "d" and "a".
// "d" appears 1st, so it is the 1st distinct string.
// "a" appears 2nd, so it is the 2nd distinct string.
// Since k == 2, "a" is returned. 


#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
    public:

    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string,int> map;
        for(auto i=0; i<arr.size(); i++)
        {
            map[arr[i]]++;
        }

        for(auto i=0; i<arr.size(); i++)
        {
            if(map[arr[i]] == 1){
                k--;
                if(k == 0){
                    return arr[i];
                }
            }
        }
        return "";
    }
};

int main ()
{
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<string> arr(n);
    cout<<"Enter the element's: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    int k;
    cout<<"Enter the k: ";
    cin>>k;

    Solution obj;
    string ans = obj.kthDistinct(arr,k);
    cout<<k<<" Distinct Elements is : "<<ans<<endl;
    return 0;
}