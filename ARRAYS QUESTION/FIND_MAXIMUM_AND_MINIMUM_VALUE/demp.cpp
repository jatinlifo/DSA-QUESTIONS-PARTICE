// USING TWO VARIABLES SIMPLE APPROACH

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
    cout<<endl;
    
    int max = INT8_MIN;
    int min = INT8_MAX;
    for(int i = 0; i < n; i++)
    {
        if(v[i] > max){
            max = v[i];
        }
        if(v[i] < min){
            min = v[i];
        }
    }
    cout<<"Maximum is:"<<max<<" "<<"Minimum is:"<<min;
    cout<<endl;

    return 0;
}
