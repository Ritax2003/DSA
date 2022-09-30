/*
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:
*/#include <iostream>
using namespace std;
#include<cstring>
int removeX(char input[],int start=0) {
    if(input[start]=='\0'){
        return 0;
    }
    removeX(input,start+1);
    if(input[start]=='x'){
        int len = strlen(input);
        for(int i = start;i<=len;i++){
            input[i]=input[i+1];
        }
    }

}


int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
