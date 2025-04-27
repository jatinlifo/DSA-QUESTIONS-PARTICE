// 169. Majority Element
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:
// Input: nums = [3,2,3]
// Output: 3
// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
 
// Constraints:
// n == nums.length
// 1 <= n <= 5 * 104
// -109 <= nums[i] <= 109
// Follow-up: Could you solve the problem in linear time and in O(1) space?

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            

            //Approach 1 using hashmap T.c O(n), S.c O(n)
            // int n = nums.size();
            // unordered_map<int,int> map;

            // for(int& num : nums){
            //     map[num]++;
            // }

            // for(auto& pair : map){
            //     if(pair.second > n/2){
            //         return pair.first;
            //     }
            // }
            // return 0;
            
            //Approach 2 using Boger-Moore Voting Algorithm  T.C = O(n) , S.C= O(n)

            int n = nums.size();
            int maj;
            int count = 0;
    
            for(int i=0; i<n; i++){
                if(count == 0){
                    maj = nums[i];
                    count = 1;
                }else if(maj == nums[i]){
                    count++;
                }else{
                    count--;
                }
            }
            return maj;
        }
    };

int main() {

    int n;
    cout<<"Enter the number of elements in array :";
    cin >> n;
    vector<int> nums(n);
    cout<<"Enter the elements an array : ";
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    Solution obj;

    int ans = obj.majorityElement(nums);

    cout<<"Majority Element is : "<<ans<<endl;
    return 0;
}