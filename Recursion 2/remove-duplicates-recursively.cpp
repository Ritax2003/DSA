/*
Remove Duplicates Recursively

Given a string S, remove consecutive duplicates from it recursively.

Input Format :
String S

Output Format :
Output string

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :
aabccba
Sample Output 1 :
abcba

Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz

*/
#include <iostream>
using namespace std;
#include<cstring>

void removeConsecutiveDuplicates(char *input,int start=0) {
	if(input[start] == '\0'){
        return;
    }
    removeConsecutiveDuplicates(input,start+1);
    if(input[start] == input[start+1]){
        for(int i = start; input[i]!='\0';i++){
            input[i]=input[i+1];
        }
    }


}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}