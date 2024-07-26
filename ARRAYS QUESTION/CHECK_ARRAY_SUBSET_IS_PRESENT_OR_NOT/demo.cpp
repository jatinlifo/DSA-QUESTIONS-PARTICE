#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool checkArraySubset(vector<int> &nums1, int n, vector<int> &nums2, int m)
{
    unordered_map<int,int> map;
    for(int i=0; i<n; i++)
    {
        map[nums1[i]]++;
    }
    for(int i=0; i<m; i++)
    {
        if(map.find(nums2[i]) != map.end()){
            map[nums2[i]]--;
            if(map[nums2[i]] == 0){
                map.erase(nums2[i]);
            }
        }
        else{
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout<<"Enter the array1 size: ";
    cin>>n;
    vector<int> nums1(n);
    cout<<"Enter the array 1 elements: ";
    for(int i=0; i<n; i++) cin>>nums1[i];
    int m;
    cout<<"Enter the array2 size: ";
    cin>>m;
    vector<int> nums2(m);
    cout<<"Enter the array 2 elements: ";
    for(int i=0; i<m; i++) cin>>nums2[i];

    bool ans = checkArraySubset(nums1,n,nums2,m);

    if(ans){
        cout<<"YES: ";
    }
    else{
        cout<<"NO: ";
    }
}