#include<iostream>
#include<string>

using namespace std;

void reverseTheString(string& st)
{
    int n = st.length();
    int left = 0;
    int right = n-1;

    while(left <= right)
    {
        swap(st[left],st[right]);
        left++;
        right--;
    }
    cout<<st<<endl;
}

int main ()
{
    string st;
    cout<<"Enter the string: ";
    cin>>st;

    reverseTheString(st);
    
    return 0;
}