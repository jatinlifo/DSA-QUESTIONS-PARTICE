// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
 
 #include<iostream>
 #include<vector>
 using namespace std;

 class Solution{
    public:

    int maxProfit(vector<int> &nums, int n)
    {
        int minCost = INT8_MAX;
        int maxProfit = 0;

        for(int i=0;i<n;i++)
        {
            if(nums[i] < minCost)
            {
                minCost = nums[i];
            }
            else
            {
                maxProfit = max(maxProfit,nums[i] - minCost);
            }
        }
        return maxProfit;
    }
 };

 int main ()
 {
    int n;
    cout<<"Enter the size:";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the element:";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    Solution obj;
    int ans = obj.maxProfit(nums,n);
    cout<<"Maximum Profit: "<<ans<<endl;

    return 0;
 }