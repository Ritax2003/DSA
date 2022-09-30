/*
 Input Format:
The first and only line of input contains a string without any leading and trailing spaces. All the characters in the string would be in lower case.
Output Format:
The only line of output prints the updated string.
Note:
You are not required to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
aabccbaa
Sample Output 1:
abcba
*/
#include <iostream>
#include <cstring>
using namespace std;


void removeConsecutiveDuplicates(char input[]) {
     int nextIndex = 1;
    char lastChar = input[0];
    int i =0;
    while(input[i] != '\0') { 
        if(input[i] == lastChar) { 
            i++;
        
        } 
        else {
            input[nextIndex] = input[i];
            nextIndex++; 
            lastChar = input[i];
            i++;
        }
    }
    input[nextIndex] = '\0';
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}