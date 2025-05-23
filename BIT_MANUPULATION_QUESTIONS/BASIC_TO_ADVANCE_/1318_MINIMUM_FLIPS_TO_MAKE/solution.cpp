// Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
// Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

// Example 1:

// Input: a = 2, b = 6, c = 5
// Output: 3
// Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
// Example 2:

// Input: a = 4, b = 2, c = 7
// Output: 1
// Example 3:

// Input: a = 1, b = 2, c = 3
// Output: 0
 

// Constraints:

// 1 <= a <= 10^9
// 1 <= b <= 10^9
// 1 <= c <= 10^9

#include<iostream>

using namespace std;

class Solution{
    public:

    int minFlips(int a, int b, int c){

        int flips = 0;

        while(a != 0 || b != 0 || c != 0){

            if((c&1) == 1){ // Right most bit (MSB) calculate 
                if((a&1) == 0 && (b&1) == 0){
                    flips++;
                }
            }
            else{   // Rihgt most bit == 0
                if((a&1) == 1) flips++;

                if((b&1) == 1) flips++;
            }
            a >>= 1;   //Right shift 
            b >>= 1;   //Right shift
            c >>= 1;   //Right shift
        }
        return flips;
    }
};

int main () {
    
    int a,b,c;
    cout<<"Enter a and b or c : ";
    cin>> a >> b >> c;

    Solution obj;

    int ans = obj.minFlips(a,b,c);

    cout<<"Minimum flips is : "<<ans<<endl;

    return 0;
}