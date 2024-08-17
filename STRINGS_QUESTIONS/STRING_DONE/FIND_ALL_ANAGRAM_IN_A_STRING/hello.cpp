// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:
// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:

    bool allZeros(vector<int>& freq)
    {
        for(int i=0; i<freq.size(); i++)
        {
            if(freq[i] != 0)
            {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string &s , string &p) 
    {
        int n = s.length();
        int k = p.length();

        vector<int> freq(26,0);
        vector<int> ans;

        for(int i=0; i<k; i++)
        {
            char ch = p[i];
            freq[ch-'a']++;
        }
        int i = 0;
        int j = 0;

        while(j < n)
        {
            freq[s[j]-'a']--;

            if(j-i+1 == k)
            {
                if(allZeros(freq))
                {
                    ans.push_back(i);
                }
                freq[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }

};

int main ()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    string p;
    cout<<"Enter the pattern string : ";
    cin>>p;

    Solution obj;
    vector<int> res = obj.findAnagrams(s,p);
    
    for(int i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}