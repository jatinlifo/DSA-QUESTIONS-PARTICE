// INPUT = 0 2 1 2 0
//OUTPUT = 0 0 1 2 2
// USING COUNT SORT APPROACH


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort012(vector<int> &a, int n)
    {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        for(int i=0; i<n; i++)
        {
            if(a[i] == 0){
                count0++;
            }
            else if(a[i] == 1){
                count1++;
            }
            else{
                count2++;
            }
        } 
        for(int i=0; i<n; i++)
        {
            if(count0 != 0){
                a[i] = 0;
                count0--;
            }
            else if(count1 != 0){
                a[i] = 1;
                count1--;
            }
            else{
                a[i] = 2;
                count2--;
            }
        }
    }
    
};


int main() {

        int n;
        cout<<"Enter size:";
        cin>>n;
        vector<int> v(n);
        cout<<"Enter elements:";
        
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
        }

        Solution ob;
        ob.sort012(v, n);

        for(int i=0;i<n;i++){
            cout << v[i]  << " ";
        }

        cout << endl;
       
    return 0;
}

