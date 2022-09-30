/*
input:
abc def g hi
output: abcdefghi*/
#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char input[]) {
    int count =0;
    int i =0;
    int len = strlen(input);
    for(i=0;i<len;i++){
        if(input[i]!=' '){
            input[count]=input[i];
            count++;
        }
        
    }
    input[count]='\0';
}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}
