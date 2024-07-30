#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int top = 0;
    int right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1;
    int left = 0;
    int dir = 0;
    vector<int> ans;

    while (top <= bottom && left <= right)
    {
        if (dir == 0)
        {
            for (int col = left; col <= right; col++)
            {
                ans.push_back(matrix[top][col]);
            }
            top++;
        }
        else if (dir == 1)
        {
            for (int row = top; row <= bottom; row++)
            {
                ans.push_back(matrix[row][right]);
            }
            right--;
        }
        else if (dir == 2)
        {
            for (int col = right; col >= left; col--)
            {
                ans.push_back(matrix[bottom][col]);
            }
            bottom--;
        }
        else
        {
            for (int row = bottom; row >= top; row--)
            {
                ans.push_back(matrix[row][left]);
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the row's size :";
    cin >> n;
    int m;
    cout << "Enter the col's size :";
    cin >> m;
    cout << "Enter the element's :";
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "After spiral order: " << endl;
    vector<int> ans = spiralOrder(matrix);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}