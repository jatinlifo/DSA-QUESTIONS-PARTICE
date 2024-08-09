// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 (**such that each row, column, and both diagonals all have the same sum.**)

// Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?
// Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.
// Example 1:
// Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
// Output: 1
// Explanation: 
// The following subgrid is a 3 x 3 magic square:
// while this one is not:
// In total, there is only one magic square inside the given grid.

#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;


class Solution {
public:

    bool isMagicGrid(vector<vector<int>>& grid, int r, int c)
    {
        unordered_set<int> st;
        
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                int num = grid[r+i][c+j];

                if(num<1 || num>9 || st.count(num)){
                    return false;
                }
                else{
                    st.insert(num);
                }
            }
        }
        int sum = grid[r][c]+grid[r][c+1]+grid[r][c+2];
        for(int i=0; i<3; i++)
        {
            if(grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2] != sum){
                return false;
            }
            if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i] != sum){
                return false;
            }
        }
        //diagonal 
        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2] != sum){
            return false;
        }
        if(grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c] != sum){
            return false;
        }
        return true;
    }
   
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid.size();

        int count = 0;

        for(int i=0; i<rows-2; i++)
        {
            for(int j=0; j<cols-2; j++)
            {
                if(isMagicGrid(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};

int main ()
{
    int n;
    cout<<"Enter the row's size : ";
    cin>>n;
    int m;
    cout<<"Enter the col's size : ";
    cin>>m;

    vector<vector<int> > grid(n,vector<int>(m));
    cout<<"Enter the element's :"<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }

    Solution obj;
    int ans = obj.numMagicSquaresInside(grid);

    cout<<"Magic grid is :"<<ans<<endl;

    return 0;
}