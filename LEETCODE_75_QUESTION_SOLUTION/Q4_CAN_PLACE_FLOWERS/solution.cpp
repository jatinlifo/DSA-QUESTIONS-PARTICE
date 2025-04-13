// 605. Can Place Flowers
// Solved
// Easy
// Topics
// Companies
// You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

// Example 1:
// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: true
// Example 2:
// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: false

// Constraints:
// 1 <= flowerbed.length <= 2 * 104
// flowerbed[i] is 0 or 1.
// There are no two adjacent flowers in flowerbed.
// 0 <= n <= flowerbed.length
//T.C = O(n) , S.C = O(1)

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int m = flowerbed.size();
        int i = 0;

        while(i < m && n > 0){
            if(flowerbed[i] == 1){
                i += 2;
            }else if(i == m-1 || flowerbed[i+1] == 0){
                i += 2;
                n--;
            }else{
                i += 3;
            }
        }
        return n == 0;
    }
};

int main() {

    int size;
    cout<<"Enter the size : ";
    cin >> size;
    vector<int> flowerbed(size);
    cout<<"Enter the Element's : ";
    for(int i=0; i<size; i++){
        cin >> flowerbed[i];
    }
    cout<<endl;
    int n;
    cout<<"Enter the n : ";
    cin >> n;
    Solution obj;
    bool ans = obj.canPlaceFlowers(flowerbed,n);
    if(ans){
        cout<<"Yes flower can be place : "<<endl;
    }else{
        cout<<"No flower can't be place "<<endl;
    }
    return 0;
}