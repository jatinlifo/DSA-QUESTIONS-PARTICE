// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
// If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.
// Example 1:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Example 2:
// Input: s = "abcd", k = 2
// Output: "bacd"

#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:

    string ReverseThe2(string &s, int k)
    {
        int n = s.length();

        for(int i=0; i<n; i+=(2*k))
        {
            int left = i;
            int right = min(i+k-1,n-1);

            while(left < right)
            {
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

int main ()
{
    string s;
    cout<<"Enter the string :";
    cin>>s;
    int k;
    cout<<"Enter the K :";
    cin>>k;
    
    Solution obj;
    string ans = obj.ReverseThe2(s,k);
    cout<<ans<<endl;

    return 0;
}

// TC = O(N):  SC O(1):         