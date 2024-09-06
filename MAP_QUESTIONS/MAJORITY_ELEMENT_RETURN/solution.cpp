// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Return majority element otherwise -1  
// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]  
// Output: 2

// Constraints:
// n == nums.length
// 1 <= n <= 5 * 104
// -109 <= nums[i] <= 109   
 // PORBLEM 169 

#include<iostream>
#include<vector>


using namespace std;

class Solution{
    public:

    int majorityElementI(vector<int>& nums, int n)
    {
        int maj = NULL;
        int count = 0;

        for(int i=0; i<n; i++)
        {
            if(count == 0){
                maj = nums[i];
                count = 1;
            }
            else if(nums[i] == maj){
                count++;
            }
            else{
                count--;
            }
        }
        //verifiy
        count = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == maj){
                count++;
            }
        }
        return (count > n/2 ? maj : -1) ;
    }
};

int main ()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element's of array : ";
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }
    Solution obj;
    int ans = obj.majorityElementI(nums,n);
    cout<<"Majority Element is : "<<ans<<endl;
    return 0;
}
// ya map sa bhi ho sakta hai but O(n) space aa jayega

//wasa ek maja ke batt ya hai majority element n/2 ma only 1 he element hoga 
// **      genral formula = n/k ma only (k-1) element possible hai 
