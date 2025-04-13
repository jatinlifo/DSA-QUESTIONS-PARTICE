// 345. Reverse Vowels of a String
// Solved
// Easy
// Topics
// Companies
// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

// Example 1:
// Input: s = "IceCreAm"
// Output: "AceCreIm"
// Explanation:
// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".
// Example 2:
// Input: s = "leetcode"
// Output: "leotcede"

// Constraints:
// 1 <= s.length <= 3 * 10^5
// s consist of printable ASCII characters.
// T.C = O(n) , S.C = O(8)

#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

class Solution{
    public:

    string reverseVowels(string s) {
        
        unordered_set<char> set{'a','i','o','u','e','A','I','O','U','E'};
        int n = s.length();
        int i = 0;
        int j = n-1;

        while(i < j){
            if(set.find(s[i]) != set.end()){
                while(set.find(s[j]) == set.end()){
                    j--;
                }
                swap(s[i],s[j]);
                j--;
            }
            i++;
        }
        return s;
    }
};
int main () {

    string s;
    cout<<"Enter the String : ";
    cin >> s;
    Solution obj;
    cout<<endl;
    string ans = obj.reverseVowels(s);
    cout<<"Update String is "<< ans <<endl;
    return 0;
}