// You are given a 0-indexed array of strings details. Each element of details provides information about a given passenger compressed into a string of length 15. The system is such that:
// The first ten characters consist of the phone number of passengers.
// The next character denotes the gender of the person.
// The following two characters are used to indicate the age of the person.
// The last two characters determine the seat allotted to that person.
// Return the number of passengers who are strictly more than 60 years old.

// Input: details = ["7868190130M7522","5303914400F9211","9273338290F4010"]
// Output: 2
// Explanation: The passengers at indices 0, 1, and 2 have ages 75, 92, and 40. Thus, there are 2 people who are over 60 years old.


#include<iostream>
#include<string>
#include<vector>

using namespace std;

int countSeniors(vector<string> &details , int n)
{
    int count = 0;
    
    for(int i=0; i<n; i++)
    {
        string temp = details[i];
        int f = temp[11]-'0';
        int s = temp[12]-'0';
        int res = (f*10+s);
        if(res > 60){
            count++;
        }
    }
    return count;

}

int main ()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    cout<<"Enter the elements: ";
    vector<string> details(n);
    for(int i=0; i<n; i++)
    {
        cin>>details[i];
    }
    int ans =  countSeniors(details,n);

    cout<<ans<<endl;

    return 0;
}