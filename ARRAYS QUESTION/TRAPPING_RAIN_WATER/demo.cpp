// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getLeftMax(vector<int> &heights, int n)
    {
        vector<int> leftMax(n);
        leftMax[0] = heights[0];
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], heights[i]);
        }
        return leftMax;
    }
    vector<int> getRightMax(vector<int> &heights, int n)
    {
        vector<int> rightMax(n);
        rightMax[n - 1] = heights[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], heights[i]);
        }
        return rightMax;
    }

    int trapping(vector<int> &heights, int n)
    {
        vector<int> leftMax = getLeftMax(heights, n);
        vector<int> rightMax = getRightMax(heights, n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int h = min(leftMax[i], rightMax[i]) - heights[i];
            sum += h;
        }
        return sum;
    }
};

int main()
{
    int n;
    cout << "Enter the heights size: ";
    cin >> n;
    vector<int> heights(n);
    cout << "Enter the heights : ";
    for (int i = 0; i < n; i++){
        cin >> heights[i];
    }
    Solution obj;
    int ans = obj.trapping(heights, n);
    cout << ans << endl;
    return 0;
}