// 151. Reverse Words in a String
// Solved
// Medium
// Topics
// Companies
// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 
// Constraints:
// 1 <= s.length <= 104
// s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// There is at least one word in s.
// T.C --> O(n) ---- S.c O(n) <---

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            
            vector<string> temp;
            int n = s.length();
    
            string t = "";
            int i = 0;
    
            while(i < n){
                if(s[i] != ' '){
                    t += s[i];
                }else{
                    if(t != ""){
                        temp.push_back(t);
                    }
                    t = "";
                }
                i++;
            }
            if(t != ""){
                temp.push_back(t);
            }
            string ans;
            for(int i=temp.size()-1; i>=0; i--){
                ans += temp[i];
                if(i != 0) ans += ' ';
            }
            return ans;
        }
    };

    int main () {

        string s;
        cout<<"Enter the string : ";
        getline(cin,s);
        cout<<endl;
        Solution obj;
        string ans = obj.reverseWords(s);
        cout<<"Reverse String is--> "<<ans<<endl;
        return 0;
    }