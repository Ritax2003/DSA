/*
Merge Sort Code

Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/
#include <iostream>
using namespace std;
void merge(int input[], int start, int mid, int end)
{ int n1= (mid-start)+1;
  int n2= (end-mid);
 int a[n1]={0};
 int b[n2]={0};
 for(int i=0;i<n1;i++){
     a[i]=input[start+i];
 }
 for(int j=0;j<n2;j++){
     b[j]=input[mid+j+1];
 }
 int count =start,i=0,j=0;
 while(i<n1 && j<n2){
     if(a[i]<=b[j]){
         input[count]=a[i];
         i++;
         count++;
     }
     else{
         input[count]=b[j];
         j++;
         count++;
     }
 }
 while(i<n1){
     input[count]=a[i];
     i++;
     count++;
 }
 while(j<n2){
     input[count]=b[j];
     j++;
     count++;
 }
	
}
void mergeSort(int input[],int start,int end){
    if(start>=end){
        return;
    }
    if(start<end){
        int mid = (start+end)/2;
        mergeSort(input,start,mid);
        mergeSort(input,mid+1,end);
        merge(input,start,mid,end);
    }
}
void mergeSort(int input[],int size){
	mergeSort(input,0,size-1);
        
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}