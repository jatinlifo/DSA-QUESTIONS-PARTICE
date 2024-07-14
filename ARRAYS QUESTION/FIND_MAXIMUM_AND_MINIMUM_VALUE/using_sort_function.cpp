// USING SORTING FUNCTION


#include<iostream>
#include<vector>
#include<algorithm>

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
    sort(v.begin(),v.end());
    
    int max = v[n-1];
    int min = v[0];

    cout<<"Maximum is : "<<max<<"  "<<"Minimum is : "<<min;
    cout<<endl;

    return 0;
}
