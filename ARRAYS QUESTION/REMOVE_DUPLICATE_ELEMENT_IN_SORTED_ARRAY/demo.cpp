// Input: arr = [2, 2, 2, 2, 2]
// Output: [2]



#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int remove_duplicate(vector<int> &arr) {
        
        int n = arr.size();
        int j = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[j] != arr[i])
            {
                j++;
                arr[j] = arr[i];
            }
        }
        return j+1;
    }
    
};

int main ()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    Solution obj;
    int idx = obj.remove_duplicate(arr);
    for(int i=0; i<idx; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}