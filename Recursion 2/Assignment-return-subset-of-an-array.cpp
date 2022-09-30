/*
Return subset of an array
Send Feedback
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)

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
int subset(int input[], int n, int output[][20]) {
    if(n==0){
        output[0][0]=0;
        return 1;
    }
    int count = subset(input+1,n-1,output);
    int i,j;
    for(i=0;i<count;i++){
        output[count+i][0]=output[i][0]+1;
        output[count+i][1]=input[0];
    }
    for(i=0;i<count;i++){
        for(j=1;j<output[count+i][0];j++){
            output[count+i][j+1]=output[i][j];
        }
    }
    return 2*count;

}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
