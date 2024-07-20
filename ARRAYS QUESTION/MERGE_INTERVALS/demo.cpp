// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution{
    public:

    vector<vector<int> > mergeIntervals(vector<vector<int> > &intervals)
    {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();

        vector<vector<int> > ans;
        
        for(int i=0;i<n;i++)
        {
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            else{
                vector<int> &v = ans.back();  // to track the last vector
                int y = v[1];   // assigen last vector ke second value
                
                //overlapping
                if(intervals[i][0] <= y){
                    v[1] = max(y,intervals[i][1]);
                }
                //not overlaping
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};

int main ()
{
    int n;
    cout<<"Enter the number of Intervals: ";
    cin>>n;

    vector<vector<int> > intervals(n,vector<int> (2));
    cout<<"Enter the intervals: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Interval "<<i+1<<":";
        cin>>intervals[i][0] >> intervals[i][1];
    }
    
    Solution obj;
    vector<vector<int> > merg_interval = obj.mergeIntervals(intervals);
    
    cout<<"Merge Intervals and non overlaping: "<<endl;
    for(int i=0; i<merg_interval.size(); i++)
    {
        cout << "[" <<merg_interval[i][0]<<","<<merg_interval[i][1] << "] ";
    }
    cout<<endl;

    return 0;
}