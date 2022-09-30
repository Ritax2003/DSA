/*
input: abcdcba
output: true*/
#include <iostream>
#include <cstring>
using namespace std;

#include<string.h>
bool checkPalindrome(char str[]) {
    int i=0;
    int j = strlen(str) - 1;
    while(j > i){
        if(str[i] != str[j]){
            return false;
            break;
        }   
        i++;
        j--;
    }    
    return true;
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
}