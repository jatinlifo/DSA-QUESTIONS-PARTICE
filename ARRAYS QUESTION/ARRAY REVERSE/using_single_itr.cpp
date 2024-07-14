// WITHOUT USING EXTRA FUNCTION SO DIRECTED PRINT THE ARRAY 

#include<iostream>
#include<vector>

using namespace std;

int main ()
{
    int n;
    cout<<"Enter the size:";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter array element:";
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    cout<<"After Reverse array:"<<endl;
    for(int i = n-1; i >= 0; i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}
