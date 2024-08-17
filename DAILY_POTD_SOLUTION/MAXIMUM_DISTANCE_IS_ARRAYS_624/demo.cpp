// You are given m arrays, where each array is sorted in ascending order.

// You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

// Return the maximum distance.
// Example 1:

// Input: arrays = [[1,2,3],[4,5],[1,2,3]]
// Output: 4
// Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
// Example 2:

// Input: arrays = [[1],[1]]
// Output: 0

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int n = arrays.size();
      
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int minId = -1;
        int maxId = -1;
        for(int i=0; i<n; i++)
        {
            int first = arrays[i][0];
            int last = arrays[i].back();
            
            if(first < min1){
                min2 = min1;
                min1 = first;
                minId = i;
            }
            else if(first < min2){
                min2 = first;
            }
            if(last > max1){
                max2 = max1;
                max1 = last;
                maxId = i;
            }
            else if(last > max2){
                max2 = last;
            }
        }
        if(minId != maxId){
            return max1 - min1;
        }
        return max(max1-min2,max2-min1);
    }
};

int main ()
{ 
    vector<vector<int> > arrays;
    int n;
    cout<<"Enter the row's size : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int numElements;
        cout << "Enter the number of elements in row " << i + 1 << ": ";
        cin >> numElements;

        vector<int> row(numElements);
        cout << "Enter the elements: ";
        for (int j = 0; j < numElements; ++j) {
            cin >> row[j];
        }

        arrays.push_back(row);
    }

    Solution obj;
    int ans = obj. maxDistance(arrays);
    cout<<"Maximum distance in arrays : "<<ans<<endl;
   
    return 0;
}
 