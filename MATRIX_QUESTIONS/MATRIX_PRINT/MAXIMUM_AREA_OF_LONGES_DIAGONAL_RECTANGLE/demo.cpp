// You are given a 2D 0-indexed integer array dimensions.
// For all indices i, 0 <= i < dimensions.length, dimensions[i][0] represents the length and dimensions[i][1] represents the width of the rectangle i.
// Return the area of the rectangle having the longest diagonal. If there are multiple rectangles with the longest diagonal, return the area of the rectangle having the maximum area.
// Example 1:
// Input: dimensions = [[9,3],[8,6]]
// Output: 48
// Explanation: 
// For index = 0, length = 9 and width = 3. Diagonal length = sqrt(9 * 9 + 3 * 3) = sqrt(90) ≈ 9.487.
// For index = 1, length = 8 and width = 6. Diagonal length = sqrt(8 * 8 + 6 * 6) = sqrt(100) = 10.
// So, the rectangle at index 1 has a greater diagonal length therefore we return area = 8 * 6 = 48.

#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution{
    public:

    double calculateMaxD(int height, int width)
    {
        return sqrt(width*width + height*height);
        
    }

    int maxAreaOf(vector<vector<int> > &dimensions)
    {
        int n = dimensions.size();
        int maxArea = 0;
        double diagonal = 0;

        for(int i=0; i<n; i++)
        {
            int height = dimensions[i][0];
            int width = dimensions[i][1];
            int area = height * width;
            double maxDiagonal = calculateMaxD(height,width);

            if(maxDiagonal > diagonal){
                diagonal = maxDiagonal;
                maxArea = area;
            }
            else if(maxDiagonal == diagonal){
                maxArea = max(maxArea,area);
            }
        }
        return maxArea;
    }
};

int main ()
{
    int n;
    cout<<"Enter the dimensions height size: ";
    cin>>n;
    vector<vector<int> > dimensions(n,vector<int>(2));
    cout<<"Enter the height and width: "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin>>dimensions[i][j];
        }
    }
    cout<<endl;

    Solution obj;
    int area = obj.maxAreaOf(dimensions);

    cout<<"Maximum Area is : "<<area<<endl;
    return 0;
}