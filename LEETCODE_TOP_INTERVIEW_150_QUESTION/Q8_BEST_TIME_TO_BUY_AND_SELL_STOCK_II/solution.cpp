// 122. Best Time to Buy and Sell Stock II
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.
// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

// Constraints:

// 1 <= prices.length <= 3 * 104
// 0 <= prices[i] <= 104

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        
        int solve(vector<int>& prices, int i, bool buy, vector<vector<int>>& dp) {
    
            if(i >= prices.size()){
                return 0;
            }
            if(dp[i][buy] != -1){
                return dp[i][buy];
            }
            int profit = 0;
            if(buy){
                int take = -prices[i] + solve(prices,i+1,false,dp);
                int skip = solve(prices,i+1,true,dp);
                profit = max(take,skip);
            }else{
                int take = prices[i] + solve(prices,i+1,true,dp);
                int skip = solve(prices,i+1,false,dp);
                profit = max(take,skip);
            }
            return dp[i][buy] = profit;
        }
        int maxProfit(vector<int>& prices) {
           
           int n = prices.size();
           vector<vector<int>>dp(n,vector<int>(2,-1));
           return solve(prices,0,true,dp); 
        }
    };

int main () {
    

    int n;
    cout<<"Enter the number of elements in array : ";
    cin >> n;
    vector<int> prices(n);
    cout<<"Enter the elements : ";
    for(int i=0; i<n; i++){
        cin >> prices[i];
    }
    cout<<endl;
    Solution obj;
    int profit = obj.maxProfit(prices);

    cout<<"Maximum Profit is : "<<profit<<endl;
    
    return 0;
}