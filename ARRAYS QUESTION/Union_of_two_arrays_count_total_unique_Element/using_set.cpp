// Input: arr1[] [1, 2, 3, 4, 5], arr2[] = [1, 2, 3]
// Output: 5
// Explanation: 1, 2, 3, 4 and 5 are the elements which comes in the union setof both arrays. So count is 5.
//USING SET DATA STRUCTURE

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
  public:
    
    int doUnion(vector<int> arr1, vector<int> arr2) {
        
        unordered_set<int> st;
        for(int i=0; i<arr1.size(); i++)
        {
            st.insert(arr1[i]);
        }
        for(int i=0; i<arr2.size(); i++)
        {
            st.insert(arr2[i]);
        }
        
        int count = 0;
        for(auto value:st){
            count++;
        }
        
        // ANOTHER WAY USING SET find() FUNCTION   
        unordered_set<int> st;
        
        for(auto ele: arr1){
            st.insert(ele);
        }
        int count = st.size();
        
        for(auto ele: arr2){
            if(st.find(ele) == st.end()){
                st.insert(ele);
                count ++;
            }
        }
        return count;
    }
};

int main()
{
    int n1,n2;
    cout<<"Enter size arr1 :";
    cin>>n1;

    vector<int>arr1(n1);
    cout<<"Enter arr1 element:";
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the arr2 size:";
    cin>>n2;
    vector<int>arr2(n2);
    cout<<"Enter arr2 element:";
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    
    Solution obj;
     int ans = obj.doUnion(arr1,arr2);
     cout<<"Total count: "<<ans<<endl;

     return 0;
}
