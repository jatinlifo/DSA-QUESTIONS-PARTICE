// You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
// Return names sorted in descending order by the people's heights.
// Example 1:
// Input: names = ["Mary","John","Emma"], heights = [180,165,170]
// Output: ["Mary","Emma","John"]
// Explanation: Mary is the tallest, followed by Emma and John.

#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution{
    public:

    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        set<pair<int,string>,greater<pair<int,string> > > st;

        for(int i=0; i<heights.size(); i++)
        {
            st.insert({heights[i],names[i]});
        }
        vector<string> ans;
        for(auto pair: st)
        {
            ans.push_back(pair.second);
        }
        return ans;
    }
};

int main ()
{
    int n;
    cout<<"Enter the names size:";
    cin>>n;
    vector<string> names(n);
    cout<<"Enter the names: ";
    for(int i=0;i<n;i++)
    {
        cin>>names[i];
    }
    vector<int> heights(n);
    cout<<"Enter the heights:";
    for(int i=0;i<n;i++)
    {
        cin>>heights[i];
    }

    Solution obj;
    vector<string> result = obj.sortPeople(names,heights);

    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}