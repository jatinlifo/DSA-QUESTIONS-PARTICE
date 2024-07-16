// Input: arr = [1, 2, 3, 4, 5]
// Output: [5, 1, 2, 3, 4]
// Explanation: If we rotate arr by one position in clockwise 5 come to the front and remaining those are shifted to the end.

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    void rotate(vector<int> &v, int n)
    {
        int j = n-1;
        for(int i=0;i<n;i++)
        {
            swap(v[i],v[j]);
        }

        return;
    }
};

int main()
{
    int n;
    cout<<"Enter the array size:";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the element:";

    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    Solution obj;
    obj.rotate(v,n);
    for(int i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}