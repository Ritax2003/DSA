/*
Note:
Consecutive count of every character in the input string is less than or equal to 9.
Input Format:
The first and only line of input contains a string without any leading and trailing spaces.
Output Format:
The output contains the string after compression printed in single line.
Note:
You are not required to print anything. It has already been taken care of. Just implement the given function.
Constraints:
0 <= N <= 10^6

Where 'N' is the length of the input string.

Time Limit: 1 sec
Sample Input 1:
aaabbccdsa
Sample Output 1:
a3b2c2dsa
Explanation for Sample Output 1:
In the given string 'a' is repeated 3 times, 'b' is repeated 2 times, 
'c' is repeated 2 times and 'd', 's' and 'a' and occuring 1 time hence no compression for last 3 characters.
*/
#include <iostream>
#include <cstring>
#include<string>
using namespace std;

#include<bits/stdc++.h>
string getCompressedString(string &input) {
    string ans="";
    int i =0;
    int j;
    int count;
    int size=input.length();
    while(i<size){
        count =0;
        char ch=input[i];
        int j =i;
        while(input[j]==ch){
            count++;
            j++;
        }
        i=j;
        if(count>1){
            ans =ans+ch+to_string(count);
        }
        else{
            ans=ans+ch;
        }
    }
    return ans;
}

int main() {
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}