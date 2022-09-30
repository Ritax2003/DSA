/*
Return subsets sum to K
Send Feedback
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Constraints :
1 <= n <= 20
Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1
*/
#include <iostream>
using namespace std;
int subsetSumToK(int input[], int n, int output[][50], int k) {
  if(n==0){
      if(k==0){
          return 1;
      }
      else{ return 0;
  }
  }
    int a1[10000][50],a2[10000][50];
    int n1 = subsetSumToK(input+1,n-1,a1,k-input[0]);
    int n2 = subsetSumToK(input+1,n-1,a2,k);
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

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
