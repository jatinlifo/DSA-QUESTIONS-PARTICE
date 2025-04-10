// 1768 <------ You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

// Return the merged string.

// Example 1:

// Input: word1 = "abc", word2 = "pqr"
// Output: "apbqcr"
// Explanation: The merged string will be merged as so:
// word1:  a   b   c
// word2:    p   q   r
// merged: a p b q c r
// Example 2:

// Input: word1 = "ab", word2 = "pqrs"
// Output: "apbqrs"
// Explanation: Notice that as word2 is longer, "rs" is appended to the end.
// word1:  a   b 
// word2:    p   q   r   s
// merged: a p b q   r   s
// Example 3:

// Input: word1 = "abcd", word2 = "pq"
// Output: "apbqcd"
// Explanation: Notice that as word1 is longer, "cd" is appended to the end.
// word1:  a   b   c   d
// word2:    p   q 
// merged: a p b q c   d
 
// Constraints:
// 1 <= word1.length, word2.length <= 100
// word1 and word2 consist of lowercase English letters

// T.C = O(n) , S.C = O(1) 

#include<iostream>
#include<string>
using namespace std;

string mergeAlternately(string& word1, string& word2) {

    int m = word1.length();
    int n = word2.length();
    int i = 0;
    int j = 0;
    string ans = "";

    while(i < m && j < n){
        if(i == j){
            ans.push_back(word1[i]);
            i++;
        }else{
            ans.push_back(word2[j]);
            j++;
        }
    }
    while(i < m){
        ans.push_back(word1[i]);
        i++;
    }
    while(j < n){
        ans.push_back(word2[i]);
        j++;
    }
    return ans;
}
int main() {
    
    string word1;
    string word2;
    cout<<"Enter the string first : ";
    cin >> word1;
    cout<<endl;
    cout<<"Enter the string second : ";
    cin >> word2;
    cout<<endl;
    string ans = mergeAlternately(word1,word2);
    cout<<"Answer string is -> "<<ans<<endl;

    return 0;
}