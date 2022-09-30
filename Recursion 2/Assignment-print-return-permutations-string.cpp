/*
Return Permutations - String
Send Feedback
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
Sample Input :
abc
Sample Output :
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
    int index =0;
    string path="";
    helper(input,output,ifvisited,path,index);
    return index;
}


int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
