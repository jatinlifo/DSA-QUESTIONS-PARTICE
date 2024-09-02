// There are n students in a class numbered from 0 to n - 1. The teacher will give each student a problem starting with the student number 0, then the student number 1, and so on until the teacher reaches the student number n - 1. After that, the teacher will restart the process, starting with the student number 0 again.

// You are given a 0-indexed integer array chalk and an integer k. There are initially k pieces of chalk. When the student number i is given a problem to solve, they will use chalk[i] pieces of chalk to solve that problem. However, if the current number of chalk pieces is strictly less than chalk[i], then the student number i will be asked to replace the chalk.

// Return the index of the student that will replace the chalk pieces.

// Example 1:
// Input: chalk = [5,1,5], k = 22
// Output: 0
// Explanation: The students go in turns as follows:
// - Student number 0 uses 5 chalk, so k = 17.
// - Student number 1 uses 1 chalk, so k = 16.
// - Student number 2 uses 5 chalk, so k = 11.
// - Student number 0 uses 5 chalk, so k = 6.
// - Student number 1 uses 1 chalk, so k = 5.
// - Student number 2 uses 5 chalk, so k = 0.
// Student number 0 does not have enough chalk, so they will have to replace it.


/*
ALGO:: 1.find total chalk 
(k/toatlchalk = to find kiti iterate karna hai)
2.Find only remaning chalk  using modul(%)OP (k%totalchalk)
isa jo remaning bacha ga bss usa he distribut karna hai given student ko
3. Traverse the array and chek arr[i] > k return i
*/ 
#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:

    int chalkReplacer(vector<int>& chalk, int k)
    {
        int n = chalk.size();
        long long totalChalk = 0;

        for(int i=0; i<n; i++) totalChalk+= chalk[i];

        k = k % totalChalk;

        if(k == 0){
            return 0;  // replace student at point the 0 idx
        }
        for(int i=0; i<n; i++)
        {
            if(chalk[i] > k)
            {
                return i; 
            }
            k = k - chalk[i];
        }
        return -1;  // This condition never be excecute
    }
};

int main ()
{
    int n;
    cout<<"Enter the number of student's : ";
    cin>>n;
    vector<int> chalk(n);
    cout<<"Every  student distribut chalk : ";

    for(int i=0; i<n; i++)
    {
        cin>>chalk[i];
    }
    int k;
    cout<<"Enter the k : ";
    cin>>k;
    
    Solution obj;
    int ans = obj.chalkReplacer(chalk,k);
    cout<<"Student index is "<<ans<<endl; 
    return 0;
}