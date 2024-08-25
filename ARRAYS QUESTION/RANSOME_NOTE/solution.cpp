// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
// Each letter in magazine can only be used once in ransomNote.
// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true

// MA ISMA FREQ TO - KAR RAHA THA BUT CHAR DELETE NE KAR RAHA THA JIS SA YA BHUT DER 
// MA HUVA BUT HO GAYA 

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution{
    public:

    bool canConstruct(string ransomNote, string magazine)
    {

        unordered_map<char,int> map;

        for(char ch:ransomNote)
        {
            map[ch]++;
        }
        
        for(char ch:magazine)
        {
            if(map.find(ch) != map.end())
            {
                map[ch]--;

                if(map[ch] == 0)
                {
                    map.erase(ch);
                }
            }
            if(map.empty())
            {
                return true;
            }
        }
        return false;
    }
};

int main ()
{
    string ransomNote;
    cout<<"Enter the ransomNote string : ";
    cin>>ransomNote;

    string magazine;
    cout<<"Enter the magazine string : ";
    cin>>magazine;

    Solution obj;
    bool ans = obj.canConstruct(ransomNote,magazine);

    if(ans) cout<<"True";
    else{
        cout<<"False";
    }
    return 0;
}