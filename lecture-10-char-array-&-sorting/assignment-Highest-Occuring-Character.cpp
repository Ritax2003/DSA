/*
Consider:
Assume all the characters in the given string to be in lowercase always.
Input Format:
The first and only line of input contains a string without any leading and trailing spaces.
Output Format:
The only line of output prints the updated string. 
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
abdefgbabfba
Sample Output 1:
b
*/#include <iostream>
#include <cstring>
using namespace std;

char highestOccurringChar(char input[]) {
    // Write your code here
       int freq[256] = {0}; 
    int indices[256];
    for(int i = 0; i < 256; i++) { 
        indices[i] = -1; 
    } 
    for(int i = 0; input[i] != '\0'; i++) { 
        int index = input[i];
        freq[index]++;
        if(indices[index] == -1) {
            indices[index] = i;
        }
    } 
    int maxIndex = 0;
    for(int i = 0; i < 256; i++) { 
        if(freq[i] > freq[maxIndex]) {
            maxIndex = i; 
        } 
        else if(freq[i] == freq[maxIndex]) {
            if(indices[i] < indices[maxIndex]) {
                maxIndex = i;
            }
        }
    }
    return (char)maxIndex;
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);
}