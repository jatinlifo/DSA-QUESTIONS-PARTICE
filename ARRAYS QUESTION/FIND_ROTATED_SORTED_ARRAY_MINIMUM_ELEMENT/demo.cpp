// Example 1:
// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
// Time complexity = O(log(n)) , SC = O(1)


#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    int minNumber(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int ans = nums[0];

        if(nums[left] < nums[right])
        {
            return left;
        }

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(mid < n-1 && nums[mid] > nums[mid+1]) // minimum element right side ma he hoga
            {
                return nums[mid+1];
            }
            if(mid > 0 && nums[mid] < nums[mid-1]) //minimum element always right side
            {
                return nums[mid]; 
            }
            if(nums[mid] > nums[left])
            {
                left = mid + 1; //discard the left part left part ma maximum element hai
            }
            else{
                right = mid - 1; //discard the right  part why becuase right part ma maximu element hai

            }
        }
        return ans;
    }
};

int main ()
{
    int n;
    cout<<"Enter the array size:";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the element: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    Solution obj;
    int ans = obj.minNumber(v);
    cout<<"Minimum element: "<<ans<<endl;
    return 0;
}
