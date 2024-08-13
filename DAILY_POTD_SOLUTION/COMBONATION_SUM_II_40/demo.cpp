// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
   
    void solve(vector<int>& candidates, int target, vector<int>& curr, int idx , vector<vector<int> >& res)
    {
        if(target < 0){
            return;
        }
        if(target == 0)
        {
            res.push_back(curr);
            return;
        }
        for(int i=idx; i<candidates.size(); i++)
        {
            if(i>idx && candidates[i] == candidates[i-1]){
                continue;
            }
            curr.push_back(candidates[i]);
            solve(candidates,target-candidates[i],curr,i+1,res);
            curr.pop_back();
        }
    }
 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> curr;
        sort(begin(candidates),end(candidates));
        solve(candidates,target,curr,0,res);

        return res;
    }
};

int main ()
{
    int n;
    cout<<"Enter the Candidates size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element's : ";
    for(int i=0;i<n;i++) cin>>nums[i];

    int target;
    cout<<"Enter the target value : ";
    cin>>target;

    Solution obj;
    vector<vector<int> > ans;
    ans = obj.combinationSum2(nums,target);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<"[";
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<","; 
        }
        cout<<"]";
        cout<<","<<endl;
    }

    return 0;
}