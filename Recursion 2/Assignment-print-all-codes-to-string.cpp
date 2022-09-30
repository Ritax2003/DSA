/*
Print all Codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/
#include <iostream>
#include <string.h>
using namespace std;
void helper(string input,string output){
     if(input[0]=='\0'){
        cout<<output<<endl;
         return;
    }
    int num = (int)input[0]-48;
    char curr = (num-1)+'a';
    helper(input.substr(1),output+curr);
    if(input[1]!='\0'){
        num = (num*10)+(int)(input[1]- 48);
        curr = (num -1)+'a';
        if(num>=10 && num<=26){
            helper(input.substr(2),output+curr);
        }
    }
}
void printAllPossibleCodes(string input) {
    string output="";
    helper(input,output);
   
    
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
