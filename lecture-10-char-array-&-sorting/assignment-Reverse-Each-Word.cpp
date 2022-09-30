/*
Input Format:
The first and only line of input contains a string without any leading and trailing spaces. The input string represents the sentence given to Aadil.
Output Format:
The only line of output prints the sentence(string) such that each word in the sentence is reversed. 
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
emocleW ot gnidoC sajniN
*/
#include <iostream>
#include <cstring>
using namespace std;

void reverse(char input[],int start,int end){
    while(start<end){
        char temp = input[start];
        input[start]=input[end];
        input[end]=temp;
        start++;
        end--;
    }
}
void reverseEachWord(char input[]) {
    int end=0,start=0;
    int i =0;
    for(i=0;input[i]!='\0';i++){
        if(input[i]==' '){
           int end = i-1;
            reverse(input,start,end);
            start = i+1;
        }
    }
    end= i-1;
    reverse(input,start,end);
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}