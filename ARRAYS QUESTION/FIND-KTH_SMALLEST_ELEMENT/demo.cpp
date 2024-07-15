// USING SORT FUNCTION EASY WAY

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findKthSmallest(vector<int> &v, int n, int k)
{
    sort(v.begin(),v.end());
    
    int ans = v[k-1];
    
    return ans;
}

int main ()
{
    int n;
    cout<<"Enter the size:";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements:";
    
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    int k;
    cout<<"Enter the k:";
    cin>>k;
    int res = findKthSmallest(v,n,k);
    
    cout<< k<<"th Smallest element: "<<res<<endl;
}