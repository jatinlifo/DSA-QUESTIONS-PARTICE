//  Given an array arr[] of positive integers. Return true if all the array elements are palindrome otherwise, return false.
// Examples:
// Input: arr[] = [111, 222, 333, 444, 555]
// Output: true
// Explanation:
// arr[0] = 111, which is a palindrome number.
// arr[1] = 222, which is a palindrome number.
// arr[2] = 333, which is a palindrome number.
// arr[3] = 444, which is a palindrome number.
// arr[4] = 555, which is a palindrome number.
// As all numbers are palindrome so This will return true.

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    bool helper(int &num)
    {
        int rev = 0;
        int temp = num;
        while(num){
            int lastDigit = num % 10;
            rev = (rev*10+lastDigit);
            num /= 10;
        }
        if(temp == rev){
            return true;
        }
        return false;
    }

    bool checkLongesPalindrome(vector<int> &nums, int n)
    {
        for(int i=0;i<n;i++)
        {
            int num = nums[i];
            bool ans = helper(num);
            if(ans != true){
                return false;
            }
        }
        return true;
    }
};

int main ()
{
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution obj;
    bool ans = obj.checkLongesPalindrome(nums,n);
    if(ans){
        cout<<"Yes array all elements palindrome: ";
    }
    else{
        cout<<"Not present palindrome: ";
    }
    return 0;
}