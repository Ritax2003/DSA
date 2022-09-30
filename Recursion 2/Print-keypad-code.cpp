/*
Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
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

void printKeypad(int num){
    string output[100000];
    int ans = keypad(num,output);
    for(int i=0;i<ans;i++){
        cout<<output[i]<<endl;
    }
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
