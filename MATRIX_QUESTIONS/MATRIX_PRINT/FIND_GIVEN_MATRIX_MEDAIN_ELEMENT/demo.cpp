// Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.
// Example 1:
// Input:
// R = 3, C = 3
// M =  [[1, 3, 5], 
//      [2, 6, 9], 
//      [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives 
// us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 

// Constraints:   <--*** 
// 1 <= R, C <= 400
// 1 <= matrix[i][j] <= 2000

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    int CheckBothSideEqual(vector<vector<int>>& matrix, int mid, int row ,int C)
    {
        int left = 0;
        int right = C-1;

        while(left <= right)
        {
            int m = left + (right-left)/2;
            if(matrix[row][m] <= mid){
                left = m+1;
            }
            else{
                right = m-1;
            }
        }
        return left;
    }

    int medainElement(vector<vector<int>>& matrix, int R, int C)
    {
        int n = R*C;
        int left = 0;
        int right = 2000;

        while(left <= right)
        {
            int mid = left + (right-left)/2;
            int equalCount = 0;

            for(int row=0; row<R; row++)
            {
                equalCount += CheckBothSideEqual(matrix,mid,row,C);
            }
            if(equalCount <= n/2){  // odd ka case ma mid always wo hota hai jis ma left part ma chota element and right part ma bda element ho or both part equal ho 
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return left;
    }
};



int main ()
{
    int R;
    cout<<"Enter the row's size: ";
    cin>>R;
    int C;
    cout<<"Enter the col's size: ";
    cin>>C;

    vector<vector<int> > matrix(R,vector<int>(C));
    cout<<"Enter the element's :";
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cin>>matrix[i][j];
        }
    }

    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    Solution obj;
    int ans = obj.medainElement(matrix,R,C);
    cout<<"MEDAIN ELEMENT IS :"<<ans<<endl;
    return 0;
}