/*
input: abc
output: 
a
ab
abc
b
bc
c
*/
#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(char input[]) {
    int start=0,end=0;
    for(start=0;input[start]!='\0';start++){
        for(end = start;input[end]!='\0';end++){
            for(int i=start;i<=end;i++){
                cout<<input[i];
            }
            cout<<endl;
        }
    }
}



int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}