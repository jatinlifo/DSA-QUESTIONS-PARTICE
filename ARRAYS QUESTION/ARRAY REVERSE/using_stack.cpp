// USING STACK DS 

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void reverseArray(vector<int> &v, stack<int> &st, int n)
{
    for(int i = 0; i < n; i++)
    {
        st.push(v[i]);
    }
    
    int i = 0;
    while(st.empty() && i < n)
    {
        int top = st.top();
        v[i] = top;
        st.pop();
        i++;
    }
    return;
}

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
    stack<int> st;
    reverseArray(v,st,n) ;

    cout<<"After Reverse array:"<<endl;
    for(int i = n-1; i >= 0; i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}
