/*
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
Constraints:-
1<=|S|<=50
*/#include <iostream>
using namespace std;
#include<string.h>
int replacePi(char input[],int start=0) {
    if(input[start]=='\0'|| input[start+1]=='\0'){
        return 0;
    }
    replacePi(input,start+1);
    if(input[start]=='p' && input[start+1]=='i'){
        for(int i = strlen(input);i>=start+2;i--){
            input[i+2]=input[i];
        }
        input[start]='3';
        input[start+1]='.';
        input[start+2]='1';
        input[start+3]='4';
    }
	
}



int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}