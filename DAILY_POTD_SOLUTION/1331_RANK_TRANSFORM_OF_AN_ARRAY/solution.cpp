// Given an array of integers arr, replace each element with its rank.
// The rank represents how large the element is. The rank has the following rules:
// Rank is an integer starting from 1.
// The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
// Rank should be as small as possible.
// Example 1:

// Input: arr = [40,10,20,30]
// Output: [4,1,2,3]
// Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
// Example 2:

// Input: arr = [100,100,100]
// Output: [1,1,1]
// Explanation: Same elements share the same rank.

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:

    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> map;
        int rank = 1;
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            
            if(map.find(temp[i]) != map.end()){
                continue;
            }
            else{
                map[temp[i]] = rank;
            }
            rank++;
        }

        for(int i=0; i<n; i++){
            
            if(map.find(arr[i]) != map.end()){
                ans.push_back(map[arr[i]]);
            }
        }
        return ans;
    }
};



int main () {

    int n;
    cout<<"Enter the size : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element's : ";
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Solution obj;
    vector<int> ans;
    ans = obj.arrayRankTransform(arr);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}