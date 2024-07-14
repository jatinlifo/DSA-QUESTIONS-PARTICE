// USING TWO POINTER AND SWAP THE ELEMENT

#include<iostream>
#include<vector>

using namespace std;

void reverseArray(vector<int> &v, int n)
{
   int left = 0;
   int right = n-1;

   while( left <= right )
   {
        swap(v[left],v[right]);
        left++;
        right--;
   }
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

    reverseArray(v,n);
    cout<<"After Reverse array:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}
