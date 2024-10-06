// You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.

// Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.
// For example,
// s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
// s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
// Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.
// Example 1:

// Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
// Output: true

// Explanation:
// sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".
// Example 2:
//Input: sentence1 = "of", sentence2 = "A lot of words"
// Output: false
// Explanation:
// No single sentence can be inserted inside one of the sentences to make it equal to the other.

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>

using namespace std;

class Solution{
    public:

    bool sentenceSimilarityIII(string s1, string s2){

        int n = s1.length();
        int m = s2.length();

        if(m > n){
            swap(s1,s2);
        }
        vector<string> vec1,vec2;
        stringstream ss1(s1);
        string token;
        while(ss1 >> token){
            vec1.push_back(token);
        }
        stringstream ss2(s2);
        while(ss2 >> token){
            vec2.push_back(token);
        }
        int i = 0;
        int j = vec1.size()-1;
        int l = 0;
        int r = vec2.size()-1;

        while(i<vec1.size() && l<vec2.size() && vec1[i] == vec2[l])
        {
            i++;
            l++;
        }
        while(r >= l && vec1[j] == vec2[r]){
            r--;
            j--;         
        }
        return l > r;
    }
};

int main () {
    
    string s1, s2;
    cout<<"Enter the string first : ";
    getline(cin,s1);
    cout<<"Enter the string second : ";
    getline(cin,s2);
    Solution obj;
    bool ans = obj.sentenceSimilarityIII(s1,s2);

    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}