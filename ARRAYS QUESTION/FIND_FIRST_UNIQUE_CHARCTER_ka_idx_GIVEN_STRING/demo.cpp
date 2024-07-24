#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution{
    public:

    int findUniqueCharIDX(string str)
    {
        unordered_map<char,int> map;
        for(int i=0; i<str.length(); i++)
        {
            map[str[i]]++;
        }
        
        for(int i=0; i<str.length(); i++)
        {
            if(map[str[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};

int main ()
{
    string str;
    cout<<"Enter the string: ";
    cin>>str;

    Solution obj;
    int ans = obj.findUniqueCharIDX(str);
    cout<<"Unique char IDX : "<<ans<<endl;

    return 0;
}