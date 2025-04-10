// 1071. Greatest Common Divisor of Strings
// For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
// Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
// Example 1:

// Input: str1 = "ABCABC", str2 = "ABC"
// Output: "ABC"
// Example 2:

// Input: str1 = "ABABAB", str2 = "ABAB"
// Output: "AB"
// Example 3:

// Input: str1 = "LEET", str2 = "CODE"
// Output: ""

// Constraints:
// 1 <= str1.length, str2.length <= 1000
// str1 and str2 consist of English uppercase letters.

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int my_GCD(int a, int b){

    if(b == 0){
        return a;
    }
    return my_GCD(b,a % b);
}
string gcdOfStrings(string& s1, string& s2) {

    int m = s1.length();
    int n = s2.length();

    if(s1 + s2 != s2 + s1){
        return "";
    }
    int gcd = my_GCD(m,n);

    return s1.substr(0,gcd);
}

int main () {

    string s1;
    string s2;
    cout<<"Enter string first only capital letter : ";
    cin >> s1;
    cout<<"Enter string second only capital letter : ";
    cin >> s2;
    cout<<endl;
    string ans = gcdOfStrings(s1,s2);
    cout<<"Answer String is --> "<<ans<<endl;
    return 0;
}