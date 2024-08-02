#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        int n = matrix.size(); //row size:
        int m = matrix[0].size(); //col's size:

        int row = 0;
        int col = m-1;

        while(row < n && col >= 0)
        {
            if(matrix[row][col] == target)
            {
                return true;
            }
            else if(matrix[row][col] > target)  //move left side
            {
                col--;
            }
            else{
                row++;        //move to the down 
            }
        }
        return false;
    }
};

int main ()
{
    int n;
    cout<<"Enter the row's size: ";
    cin>>n;
    int m;
    cout<<"Enter the col's size: ";
    cin>>m;
    
    cout<<"You are very smart ";
    cout<<endl;
    cout<<"Enter the element's :";
    vector<vector<int> > matrix(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    //just check print
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    int target;
    cout<<"Enter the target value: ";
    cin>>target;

    Solution obj;
    bool ans = obj.searchMatrix(matrix,target);
    if(ans) cout<<"Yes :";
    else{
        cout<<"NO : ";
    }
    return 0;
}