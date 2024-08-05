// Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.
// Example 1:
// Input:
// N = 4
// mat[][] =      {{16, 28, 60, 64},
//                {22, 41, 63, 91},
//                {27, 50, 87, 93},
//               {36, 78, 87, 94 }}
// K = 3
// Output: 27
// Explanation: 27 is the 3rd smallest element.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
    public:

    int KthSmallestElemetn(vector<vector<int> > &matrix, int n ,int k)
    {
        priority_queue<int> pq; //create max heap

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                pq.push(matrix[i][j]);

                if(pq.size() > k)
                {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};

int main ()
{
    int n;
    cout<<"Enter the matrix size of nxn: ";
    cin>>n;
    vector<vector<int> > matrix(n,vector<int>(n));
    cout<<"Enter the element's: ";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>matrix[i][j];
        }
    }
    //just check print
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    int k;
    cout<<"Enter the k: "; 
    cin>>k;
    cout<<endl;

    Solution obj;
    int ans = obj.KthSmallestElemetn(matrix,n,k);
    cout<<k<<"th smallest element is :"<<ans<<endl;

    return 0;
}