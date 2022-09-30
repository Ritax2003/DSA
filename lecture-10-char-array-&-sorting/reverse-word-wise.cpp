/*
input: Welcome to Coding Ninjas
output: Ninjas Coding to Welcome*/
#include <iostream>
using namespace std;
#include<string.h>
void reverse(char input[], int start, int end) {
    int i = start, j = end;
    while(i < j) {
        char temp = input[i];
        input[i] = input[j]; 
        input[j] = temp;
        i++;
        j--;
    }
}
void reverseStringWordWise(char input[]) {
    int j = strlen(input)-1;
    int i =0;
    while(i<j){
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;
        j--;
    }
    int start=0,end=0;
   for(i=0;input[i]!='\0';i++){
       if(input[i]==' '){
           end=i-1;
           reverse(input,start,end);
           start = i +1;
           
       }
   }
    end = i -1;
    reverse(input,start,end);
    
}
int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
