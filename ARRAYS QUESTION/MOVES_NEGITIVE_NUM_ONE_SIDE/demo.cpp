// INPUT = -1 9 4 5 -6 -2 3
// OUTPUT = -6 -2 -1 9 4 5 3  (-ve element one side sift after not matter next element order)
// using sorting function TC = O(N*logN);

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class solution{
public:

    void shiftNegitive(vector<int> &v , int n)
    {
        sort(v.begin(),v.end());
        return;
    }
};



int main ()
{
    int n;
    cout<<"Enter array size:";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter element :";

    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    solution ob;
    ob.shiftNegitive(v,n);

    for(int i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}