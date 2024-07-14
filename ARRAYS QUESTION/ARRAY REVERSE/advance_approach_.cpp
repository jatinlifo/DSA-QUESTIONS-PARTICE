// USING VECTOR INBUILD REVERSE FUNCTION

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main ()
{
    int n; 
    cout<<"Enter array size:";
    cin>>n;
    
    vector<int> v(n);
    cout<<"enter element:";
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    cout<<endl;
    // used reverse funtion
    reverse(v.begin(),v.end());
    for(int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}