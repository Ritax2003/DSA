/*
Print Subset Sum to K
Send Feedback
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1
*/
#include <iostream>
using namespace std;
int subsetToK(int input[], int n, int output[][50], int k) {
  if(n==0){
      if(k==0){
          return 1;
      }
      else{ return 0;
  }
  }
    int a1[10000][50],a2[10000][50];
    int n1 = subsetToK(input+1,n-1,a1,k-input[0]);
    int n2 = subsetToK(input+1,n-1,a2,k);
    for(int i =0;i<n1;i++){
        output[i][0]=a1[i][0]+1;
        output[i][1]=input[0];
        for(int j=2;j<=a1[i][0]+1;j++){
            output[i][j]=a1[i][j-1];
        }
    }
    for(int i =n1;i<n1+n2;i++){
       output[i][0]=a2[i-n1][0];
        for(int j =0;j<=a2[i-n1][0];j++){
            output[i][j]=a2[i-n1][j];
        }
    }
    
return n1+n2;
}

void printSubsetSumToK(int input[], int size, int k) {
    int output[10000][50];
   int ans =  subsetToK(input,size,output,k);
  for( int i = 0; i < ans; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}