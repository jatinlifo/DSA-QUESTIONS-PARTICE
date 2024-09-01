// ou are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using all the elements from original.

// The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.

// Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.

// Example 1:
// Input: original = [1,2,3,4], m = 2, n = 2
// Output: [[1,2],[3,4]]
// Explanation: The constructed 2D array should contain 2 rows and 2 columns.
// The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
// The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.
// Example 2:

// Input: original = [1,2,3], m = 1, n = 3
// Output: [[1,2,3]]
// Explanation: The constructed 2D array should contain 1 row and 3 columns.
// Put all three elements in original into the first row of the constructed 2D array.
// Example 3:

// Input: original = [1,2], m = 1, n = 1
// Output: []


// LEETCODE NO.. = 2022

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    vector<vector<int>> convert1Dto2D(vector<int>& original, int m, int n)
    {
        int size = original.size();

        if(size != m*n){
            return {};
        }

        vector<vector<int> > ans(m,vector<int>(n));

        for(int i=0; i<size; i++)
        {
            ans[i/n][i%n] = original[i];
        }
        // ith row and ith col tracking the index usin i/n and i%n 
        return ans;
    }
};


int main ()
{
    int size;
    cout<<"Enter the original array size : ";
    cin>>size;
    vector<int> original(size);
    cout<<"Enter the element's : ";
    for(int i=0; i<size; i++)
    {
        cin>>original[i];
    }
    int m,n;
    cout<<"Enter the row's and column's :";
    cin >> m >> n;
    Solution obj;

    vector<vector<int> > res = obj.convert1Dto2D(original,m,n);

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}