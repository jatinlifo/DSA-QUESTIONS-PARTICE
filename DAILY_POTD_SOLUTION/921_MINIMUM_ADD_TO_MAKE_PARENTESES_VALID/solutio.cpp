// A parentheses string is valid if and only if:
// It is the empty string,
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
// For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
// Return the minimum number of moves required to make s valid.

// Example 1:
// Input: s = "())"
// Output: 1

// Example 2:
// Input: s = "((("
// Output: 3

// Constraints:
// 1 <= s.length <= 1000
// s[i] is either '(' or ')'.

#include<iostream>
#include<stack>
#include<string>

using namespace std;

class Solution{
    public:

    int minAddToMakeValid(string s){

        int count = 0;
        stack<char> st;
        
        for(int i=0; i<s.length(); i++){
            
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')' && !st.empty() && st.top() == ')'){
                st.pop();
            }
            else{
                count++;
            }
        }
        return st.size()+count;
    }
};

int main () {

    string s;
    cout<<"Enter the string : ";
    cin>>s;

    Solution obj;          
    int add = obj.minAddToMakeValid(s);
    cout<<"Minimum adding is : "<<add<<endl;

    return 0;
}