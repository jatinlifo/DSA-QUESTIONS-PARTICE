#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:

    void move(vector<int> &v, int n)
    {
        int j = 0;
        for(int i=0;i<n;i++)
        {
            if(v[i] < 0){
                if(v[i] != v[j]){
                    swap(v[i],v[j]);
                }
                j++;
            } 
        }
        return;
    }
};

int main ()
{
    int n;
    cout<<"Enter the size:";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    Solution obj;
    obj.move(v,n);
    
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}