/*
Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include <iostream>
#include <string>
using namespace std;
#include <string>
using namespace std;
int keypad(int num, string output[]){
    if(num==0){
        output[0]="";
        return 1;
    }
    int n = num%10;
    string input;
    switch(n){
            case 2: input = "abc";
                break;
            case 3: input = "def";
                break;
            case 4: input = "ghi";
                break;
            case 5: input = "jkl";
                break;
            case 6: input = "mno";
                break;
            case 7: input = "pqrs";
                break;
            case 8: input = "tuv";
                break;
            case 9: input = "wxyz";
                break;
    }
    int smallans = keypad(num/10,output);
    int ans_size = (input.size())*smallans;
    string temp[ans_size];
    int k =0;
    for(int i=0;i<smallans;i++){
        for(int j=0;j<input.size();j++){
            temp[k]=output[i]+input[j];
            k++;
        }
    }
    for(int i=0;i<ans_size;i++){
        output[i]=temp[i];
    }
    return (input.size())*smallans;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
