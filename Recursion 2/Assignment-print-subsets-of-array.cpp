/*
Print Subsets of Array
Send Feedback
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
*/
#include <iostream>
using namespace std;
int subset(int input[],int n,int start,int output[35000][30]){
    if(start == n){
        output[0][0]=0;
        return 1;
    }
    int smallans = subset(input,n,start+1,output);
    for(int i = 0;i<smallans;i++){
        output[i+smallans][0]=output[i][0]+1;
        output[i+smallans][1]=input[start];
        for(int j=1;j<=output[i][0];j++){
            output[i+smallans][j+1]=output[i][j];
        }
    }
    return 2*smallans;
}
void printSubsetsOfArray(int input[], int size) {
	int output[35000][30];
    int ans = subset(input,size,0,output);
    for(int i = 0;i<ans;i++){
        for(int j =1;j<=output[i][0];j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
