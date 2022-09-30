/*
Print Permutations
Send Feedback
Given an input string (STR), print all possible permutations of the input string.
Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.
Input Format:
The only input line contains a string (STR) of alphabets in lower case
Output Format:
Print each permutations in a new line
Constraint:
1<=length of STR<=8
Time Limit: 1sec
Sample Input 1:
cba
Sample Output 1:
abc
acb
bac
bca
cab
cba
*/
#include <iostream>
#include <string>
using namespace std;
void helper(string input,string output[],bool ifvisited[],string path,int &index){
if(path.size()==input.size()){
    output[index]=path;
    index++;
    return;
}
    for(int i=0;i<input.size();i++){
        if(ifvisited[i]!=true){
            ifvisited[i]=true;
            path.push_back(input[i]);
            helper(input,output,ifvisited,path,index);
            ifvisited[i]=false;
            path.pop_back();
        }
    }
}
int returnPermutations(string input, string output[]){
   	int n = input.size();
    bool ifvisited[n];
    for(int i=0;i<n;i++){
        ifvisited[i]=false;
    }
    int index = 0;
    string path="";
    helper(input,output,ifvisited,path,index);
    return index;
}

void printPermutations(string input){
    string output[100000];
int ans = returnPermutations(input,output);
    for(int i=0;i<=ans;i++){
        cout<<output[i]<<endl;
    }
}


int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}