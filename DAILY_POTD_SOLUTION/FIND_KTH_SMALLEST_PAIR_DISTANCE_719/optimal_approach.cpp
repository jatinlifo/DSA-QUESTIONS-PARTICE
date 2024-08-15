//THIS IS VERY VERY OPTIMAL APPROACH -> USING CONCEPT OF BINARY SEARCH AND SLIDING WINDOW
// THIS IS BEST APPROACH i.e T.C O(N*LONG(N))  || S.C O(1)

//ALGO = 1.SORTING 2. SLIDING WINDOW 3. BINARY SEARCH 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    public:

    //step 2:

    int slidingWindowCount(vector<int>& nums, int D)
    {
        int i = 0;
        int j = 1;
        int n = nums.size();
        int pairCount = 0;

        while(j < n)
        {
            while(nums[j] - nums[i] > D)
            {
                i++;
            }
            pairCount += (j-i);
            j++;
        }
        return pairCount;
    }

    int kthSmallestPair(vector<int>& nums, int k)
    {
        //step 1:
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low = 0;
        int high = nums[n-1] - nums[0];
        int result = 0;
        
        //stepf 3: binary search
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int countPair = slidingWindowCount(nums,mid);
            if(countPair < k){
                low = mid+1;
            }
            else{
                result = mid;
                high = mid-1;
            }
        }
        return result;
    }
};

int main ()
{
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the element's : ";
    for(int i=0; i<n; i++) cin>>nums[i];
    int k;
    cout<<"Enter the K : ";
    cin>>k;
    Solution obj;
    int ans = obj.kthSmallestPair(nums,k);
    
    cout<<k<<"th Smallest pair distance  is : "<<ans<<endl;
    
    return 0;
}