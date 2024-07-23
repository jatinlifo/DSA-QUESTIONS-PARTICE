#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    public:

void multiply(vector<int> &number, int x)
    {
        int carray  = 0;
        for(auto &digit : number){
            int prod = digit * x + carray;
            digit = prod % 10;
            carray = prod /10;
        }
        while(carray){
            number.push_back(carray%10);
            carray /= 10;
        }
    }
    
    vector<int> factorial(int n){
        
        vector<int> result = {1};
        for(int i=2; i<=n; i++){
            multiply(result,i);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main ()
{
    int n;
    cout<<"Enter the number:";
    cin>>n;

    Solution obj;
    vector<int> ans = obj.factorial(n);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
    }
    return 0;
}